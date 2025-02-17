// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "InputModifiers.h"
#include "QuaterViewIMC.h"
#include "PlayerCharacter.h"
#include "PlayerAnimation.h"
#include "GameFramework/PawnMovementComponent.h"

AMyPlayerController::AMyPlayerController()
{
	PlayerContext = NewObject<UInputMappingContext>();
	MoveAction = NewObject<UInputAction>();
	MoveAction->ValueType = EInputActionValueType::Axis2D;
	FEnhancedActionKeyMapping& MoveUpMapping = PlayerContext->MapKey(MoveAction, EKeys::Up);
	FEnhancedActionKeyMapping& MoveDownMapping = PlayerContext->MapKey(MoveAction, EKeys::Down);
	FEnhancedActionKeyMapping& MoveRightMapping = PlayerContext->MapKey(MoveAction, EKeys::Right);
	FEnhancedActionKeyMapping& MoveLeftMapping = PlayerContext->MapKey(MoveAction, EKeys::Left);
	{
		auto upAxisMod = NewObject<UInputModifierSwizzleAxis>();
		upAxisMod->Order = EInputAxisSwizzle::YXZ;
		MoveUpMapping.Modifiers.Add(upAxisMod);
	}
	{
		auto downAxisMod = NewObject<UInputModifierSwizzleAxis>();
		downAxisMod->Order = EInputAxisSwizzle::YXZ;
		auto downNegMod = NewObject<UInputModifierNegate>();
		downNegMod->bX = true;
		downNegMod->bY = true;
		downNegMod->bZ = true;
		MoveDownMapping.Modifiers.Add(downNegMod);
		MoveDownMapping.Modifiers.Add(downAxisMod);
	}
	{
		//auto rightAxisMod = NewObject<UInputModifierSwizzleAxis>();
		//rightAxisMod->Order = EInputAxisSwizzle::X;
		//MoveRightMapping.Modifiers.Add(rightAxisMod);
	}
	{
		auto leftNegMod = NewObject<UInputModifierNegate>();
		leftNegMod->bX = true;
		leftNegMod->bY = false;
		leftNegMod->bZ = false;
		MoveLeftMapping.Modifiers.Add(leftNegMod);
	}
	InputMappingContext = NewObject<UQuaterViewIMC>();
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(InputMappingContext);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(PlayerContext, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	OwnerActor = GetPawn<APlayerCharacter>();
	OwnerAnimation = Cast<UPlayerAnimation>(OwnerActor->GetMesh()->GetAnimInstance());

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(MoveAction);
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyPlayerController::Move);
}
void AMyPlayerController::PreProcessInput(const float DeltaTime, const bool bGamePaused)
{
	Super::PreProcessInput(DeltaTime, bGamePaused);
	if (OwnerActor)
		OwnerActor->SetAnimState(ECharacterState::IDLE);
	if (OwnerAnimation)
		OwnerAnimation->SetAnimState(ECharacterState::IDLE);
}
void AMyPlayerController::Move(const FInputActionValue& InputActionValue)
{
	// InputAction의 ValueType과 연관되어 있음
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	// 2. 정면 탐색
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (OwnerActor)
	{
		OwnerActor->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		OwnerActor->AddMovementInput(RightDirection, InputAxisVector.X);
		OwnerActor->SetAnimState(ECharacterState::RUN);
	}
	if (OwnerAnimation)
	{
		OwnerAnimation->SetAnimState(ECharacterState::RUN);
	}
}