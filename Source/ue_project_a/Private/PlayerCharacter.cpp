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
	// 1. ĳ���� ȸ�� ó��
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	GetCharacterMovement()->bOrientRotationToMovement = false; // �̵� ���⿡ ���� �ڵ� ȸ�� ����
	GetCharacterMovement()->bUseControllerDesiredRotation = true; // ��Ʈ�ѷ��� ȸ�� ���� ����

	// ��Ʈ�ѷ� ȸ���� ���� ȸ���� ����
	bUseControllerRotationPitch = true;
	bUseControllerRotationRoll = true;
	bUseControllerRotationYaw = true;

	PlayerAnimState = ECharacterState::IDLE;
}
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}