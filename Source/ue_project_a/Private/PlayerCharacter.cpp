// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerAnimation.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "InputModifiers.h"
#include "QuaterViewIMC.h"
#include "GameFramework/PawnMovementComponent.h"

APlayerCharacter::APlayerCharacter()
{
	// 1. 캐릭터 회전 처리
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	GetCharacterMovement()->bOrientRotationToMovement = false; // 이동 방향에 따라 자동 회전 방지
	GetCharacterMovement()->bUseControllerDesiredRotation = true; // 컨트롤러의 회전 적용 방지

	// 컨트롤러 회전에 따른 회전값 적용
	bUseControllerRotationPitch = true;
	bUseControllerRotationRoll = true;
	bUseControllerRotationYaw = true;

	PlayerAnimState = ECharacterState::IDLE;
}
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}