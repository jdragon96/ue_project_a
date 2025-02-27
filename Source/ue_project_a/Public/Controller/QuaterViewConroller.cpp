#include "Controller/QuaterViewConroller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "InputModifiers.h"
#include "PlayerAnimation.h"
#include "PlayerCharacter.h"

AQuaterViewConroller::AQuaterViewConroller(): AControllerBase() {
	InitAction();
	bShowMouseCursor = false;
}
void AQuaterViewConroller::InitAction() {
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
void AQuaterViewConroller::BindAction(UEnhancedInputComponent* Component) {
	Component->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &AQuaterViewConroller::ExecuteMoveForwardAction);
	Component->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &AQuaterViewConroller::ExecuteMoveRightAction);
}
void AQuaterViewConroller::ClearInputState() {
}
void AQuaterViewConroller::UpdateInputState() {
	OwnerAnimation->CharacterMovementUnitVector.X = MoveVector.X;
	OwnerAnimation->CharacterMovementUnitVector.Y = MoveVector.Y;
}
void AQuaterViewConroller::ExecuteMoveForwardAction(const FInputActionValue& InputActionValue) {
	const float value = InputActionValue.Get<float>();
	OwnerActor->AddMovementInput(OwnerActor->GetActorForwardVector() * value);
	MoveVector.Y = OwnerActor->GetVelocity().Length() / OwnerActor->GetCharacterMovement()->GetMaxSpeed() * value;
	MoveVector.Y = value;
}
void AQuaterViewConroller::ExecuteMoveRightAction(const FInputActionValue& InputActionValue) {
	const float value = InputActionValue.Get<float>();
	OwnerActor->AddMovementInput(OwnerActor->GetActorRightVector() * value);
	MoveVector.X = OwnerActor->GetVelocity().Length() / OwnerActor->GetCharacterMovement()->GetMaxSpeed() * value;
	MoveVector.X = value;
}