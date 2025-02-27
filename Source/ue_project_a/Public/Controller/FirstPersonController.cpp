#include "Controller/FirstPersonController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "InputModifiers.h"
#include "PlayerAnimation.h"
#include "PlayerCharacter.h"

AFirstPersonController::AFirstPersonController(): AControllerBase() {
	InitAction();
	bShowMouseCursor = false;
}
void AFirstPersonController::InitAction() {
	{
		LookRightAction = NewObject<UInputAction>();
		LookRightAction->ValueType = EInputActionValueType::Axis1D;
		FEnhancedActionKeyMapping& LookUpMapping =
			PlayerContext->MapKey(LookRightAction, EKeys::MouseX);
	}
	{
		LookUpAction = NewObject<UInputAction>();
		LookUpAction->ValueType = EInputActionValueType::Axis1D;
		FEnhancedActionKeyMapping& LookUpMapping =
			PlayerContext->MapKey(LookUpAction, EKeys::MouseY);
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
		FEnhancedActionKeyMapping& rightMapper =
			PlayerContext->MapKey(MoveRightAction, EKeys::A);
		FEnhancedActionKeyMapping& leftMapper =
			PlayerContext->MapKey(MoveRightAction, EKeys::D);
		auto negativeMod = NewObject<UInputModifierNegate>();
		negativeMod->bX = true;
		negativeMod->bY = false;
		negativeMod->bZ = false;
		rightMapper.Modifiers.Add(negativeMod);
	}
	{
		ShotAction = NewObject<UInputAction>();
		ShotAction->ValueType = EInputActionValueType::Axis1D;
		FEnhancedActionKeyMapping& rightMapper = PlayerContext->MapKey(ShotAction, EKeys::LeftMouseButton);
	}
}
void AFirstPersonController::BindAction(UEnhancedInputComponent* Component)
{
	AControllerBase::BindAction(Component);
	Component->BindAction(LookUpAction, ETriggerEvent::Triggered, this, &AFirstPersonController::ExecuteLookUpAction);
	Component->BindAction(LookRightAction, ETriggerEvent::Triggered, this, &AFirstPersonController::ExecuteLookRightAction);
	Component->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &AFirstPersonController::ExecuteMoveForwardAction);
	Component->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &AFirstPersonController::ExecuteMoveRightAction);
	Component->BindAction(ShotAction, ETriggerEvent::Triggered, this, &AFirstPersonController::ExecuteShotAction);
}
void AFirstPersonController::ClearInputState() {
	AControllerBase::ClearInputState();
}
void AFirstPersonController::UpdateInputState() {
	AControllerBase::UpdateInputState();
	OwnerAnimation->CharacterMovementUnitVector.X = MoveVector.X;
	OwnerAnimation->CharacterMovementUnitVector.Y = MoveVector.Y;
}
void AFirstPersonController::ExecuteLookUpAction(const FInputActionValue& InputActionValue) {
	const float value = InputActionValue.Get<float>();
	OwnerActor->AddControllerPitchInput(value);
}
void AFirstPersonController::ExecuteLookRightAction(const FInputActionValue& InputActionValue) {
	const float value = InputActionValue.Get<float>();
	OwnerActor->AddControllerYawInput(value);
}
void AFirstPersonController::ExecuteMoveForwardAction(const FInputActionValue& InputActionValue) {
	const float value = InputActionValue.Get<float>();
	OwnerActor->AddMovementInput(OwnerActor->GetActorForwardVector() * value);
	MoveVector.Y = OwnerActor->GetVelocity().Length() / OwnerActor->GetCharacterMovement()->GetMaxSpeed() * value;
	MoveVector.Y = value;
}
void AFirstPersonController::ExecuteMoveRightAction(const FInputActionValue& InputActionValue) {
	const float value = InputActionValue.Get<float>();
	OwnerActor->AddMovementInput(OwnerActor->GetActorRightVector() * value);
	MoveVector.X = OwnerActor->GetVelocity().Length() / OwnerActor->GetCharacterMovement()->GetMaxSpeed() * value;
	MoveVector.X = value;
}
void AFirstPersonController::ExecuteShotAction(const FInputActionValue& InputActionValue) {
	const float value = InputActionValue.Get<float>();
	OwnerActor->ClickMouseLeftButton();
}