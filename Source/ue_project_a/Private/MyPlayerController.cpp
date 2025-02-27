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
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PawnMovementComponent.h"

AMyPlayerController::AMyPlayerController()
{
	InitAction();
	bShowMouseCursor = false;
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	// 1. Input Mapping Context를 연동
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(PlayerContext, 0);
	}

	// 2. 마우스 입력 처리
	bShowMouseCursor = false;
	DefaultMouseCursor = EMouseCursor::Default;
	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);

	// 3. 액터 포인터 체크
	OwnerActor = GetPawn<APlayerCharacter>();
	OwnerAnimation = Cast<UPlayerAnimation>(OwnerActor->GetMesh()->GetAnimInstance());
}
void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(LookUpAction, ETriggerEvent::Triggered, this, &AMyPlayerController::LookUp);
	EnhancedInputComponent->BindAction(LookRightAction, ETriggerEvent::Triggered, this, &AMyPlayerController::LookRight);
	EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &AMyPlayerController::MoveForward);
	EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &AMyPlayerController::MoveRight);
}
void AMyPlayerController::PreProcessInput(const float DeltaTime, const bool bGamePaused)
{
	Super::PreProcessInput(DeltaTime, bGamePaused);
	MoveVector.X = 0.0;
	MoveVector.Y = 0.0;
	MoveVector.Z = 0.0;
}
void AMyPlayerController::PostProcessInput(const float DeltaTime, const bool bGamePaused)
{
	Super::PostProcessInput(DeltaTime, bGamePaused);
	UpdateInputState();
	UpdateMoveVector();
}
void AMyPlayerController::InitAction()
{
	PlayerContext = NewObject<UInputMappingContext>();
	{
		LookRightAction = NewObject<UInputAction>();
		LookRightAction->ValueType = EInputActionValueType::Axis1D;
		FEnhancedActionKeyMapping& LookUpMapping = PlayerContext->MapKey(LookRightAction, EKeys::MouseX);
	}
	{
		LookUpAction = NewObject<UInputAction>();
		LookUpAction->ValueType = EInputActionValueType::Axis1D;
		FEnhancedActionKeyMapping& LookUpMapping = PlayerContext->MapKey(LookUpAction, EKeys::MouseY);
		auto negativeMod = NewObject<UInputModifierNegate>();
		negativeMod->bX = true;
		negativeMod->bY = false;
		negativeMod->bZ = false;
		LookUpMapping.Modifiers.Add(negativeMod);
	}
	{
		MoveForwardAction = NewObject<UInputAction>();
		MoveForwardAction->ValueType = EInputActionValueType::Axis1D;
		FEnhancedActionKeyMapping& forwardMapping = PlayerContext->MapKey(MoveForwardAction, EKeys::W);
		FEnhancedActionKeyMapping& backMapping = PlayerContext->MapKey(MoveForwardAction, EKeys::S);
		auto negativeMod = NewObject<UInputModifierNegate>();
		negativeMod->bX = true;
		negativeMod->bY = false;
		negativeMod->bZ = false;
		backMapping.Modifiers.Add(negativeMod);
	}
	{
		MoveRightAction = NewObject<UInputAction>();
		MoveRightAction->ValueType = EInputActionValueType::Axis1D;
		FEnhancedActionKeyMapping& rightMapper = PlayerContext->MapKey(MoveRightAction, EKeys::A);
		FEnhancedActionKeyMapping& leftMapper = PlayerContext->MapKey(MoveRightAction, EKeys::D);
		auto negativeMod = NewObject<UInputModifierNegate>();
		negativeMod->bX = true;
		negativeMod->bY = false;
		negativeMod->bZ = false;
		rightMapper.Modifiers.Add(negativeMod);
	}
}
void AMyPlayerController::UpdateInputState()
{
	static double RUN_THRESHOLD = 0.9;

	if (MoveVector.X > RUN_THRESHOLD && MoveVector.Y > RUN_THRESHOLD)
	{
		// Forward Right/
		OwnerActor->SetPlayerAnimState(ECharacterState::RUN_FORWARD_RIGHT);
		OwnerAnimation->SetAnimState(ECharacterState::RUN_FORWARD_RIGHT);
	}
	else if (MoveVector.X < -RUN_THRESHOLD && MoveVector.Y > RUN_THRESHOLD)
	{
		// Forward Left
		OwnerActor->SetPlayerAnimState(ECharacterState::RUN_FORWARD_LEFT);
		OwnerAnimation->SetAnimState(ECharacterState::RUN_FORWARD_LEFT);
	}
	else if (MoveVector.X == 0.0 && MoveVector.Y > RUN_THRESHOLD)
	{
		// Forward
		OwnerActor->SetPlayerAnimState(ECharacterState::RUN_FORWARD);
		OwnerAnimation->SetAnimState(ECharacterState::RUN_FORWARD);
	}
	else if (MoveVector.X > RUN_THRESHOLD && MoveVector.Y == 0.0)
	{
		// RIght
		OwnerActor->SetPlayerAnimState(ECharacterState::RUN_RIGHT);
		OwnerAnimation->SetAnimState(ECharacterState::RUN_RIGHT);
	}
	else if (MoveVector.X < -RUN_THRESHOLD && MoveVector.Y == 0.0)
	{
		// Left
		OwnerActor->SetPlayerAnimState(ECharacterState::RUN_LEFT);
		OwnerAnimation->SetAnimState(ECharacterState::RUN_LEFT);
	}
	else if (MoveVector.X == 0.0 && MoveVector.Y < -RUN_THRESHOLD)
	{
		// Back
		OwnerActor->SetPlayerAnimState(ECharacterState::RUN_BACK);
		OwnerAnimation->SetAnimState(ECharacterState::RUN_BACK);
	}
	else if (MoveVector.X > RUN_THRESHOLD && MoveVector.Y < -RUN_THRESHOLD)
	{
		// Back Right
		OwnerActor->SetPlayerAnimState(ECharacterState::RUN_BACK_RIGHT);
		OwnerAnimation->SetAnimState(ECharacterState::RUN_BACK_RIGHT);
	}
	else if (MoveVector.X < -RUN_THRESHOLD && MoveVector.Y < -RUN_THRESHOLD)
	{
		// Back Left
		OwnerActor->SetPlayerAnimState(ECharacterState::RUN_BACK_LEFT);
		OwnerAnimation->SetAnimState(ECharacterState::RUN_BACK_LEFT);
	}
	else
	{
		OwnerActor->SetPlayerAnimState(ECharacterState::IDLE);
		OwnerAnimation->SetAnimState(ECharacterState::IDLE);
	}
}
void AMyPlayerController::UpdateMoveVector()
{
	OwnerAnimation->CharacterMovementUnitVector.X = MoveVector.X;
	OwnerAnimation->CharacterMovementUnitVector.Y = MoveVector.Y;
}
void AMyPlayerController::LookUp(const FInputActionValue& InputActionValue)
{
	const float value = InputActionValue.Get<float>();
	OwnerActor->AddControllerPitchInput(value);
}
void AMyPlayerController::LookRight(const FInputActionValue& InputActionValue)
{
	const float value = InputActionValue.Get<float>();
	OwnerActor->AddControllerYawInput(value);
}
void AMyPlayerController::MoveForward(const FInputActionValue& InputActionValue)
{
	const float value = InputActionValue.Get<float>();
	OwnerActor->AddMovementInput(OwnerActor->GetActorForwardVector() * value);
	MoveVector.Y = OwnerActor->GetVelocity().Length() / OwnerActor->GetCharacterMovement()->GetMaxSpeed() * value;
	MoveVector.Y = value;
}
void AMyPlayerController::MoveRight(const FInputActionValue& InputActionValue)
{
	const float value = InputActionValue.Get<float>();
	OwnerActor->AddMovementInput(OwnerActor->GetActorRightVector() * value);
	MoveVector.X = OwnerActor->GetVelocity().Length() / OwnerActor->GetCharacterMovement()->GetMaxSpeed() * value;
	MoveVector.X = value;
}