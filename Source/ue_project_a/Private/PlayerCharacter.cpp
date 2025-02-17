// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerAnimation.h"

APlayerCharacter::APlayerCharacter()
{
	// 1. 캐릭터 회전 처리
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	PlayerAnimState = ECharacterState::IDLE;
}
void APlayerCharacter::SetAnimState(ECharacterState state)
{
	PlayerAnimState = state;
}
ECharacterState APlayerCharacter::GetAnimState()
{
	return PlayerAnimState;
}
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}