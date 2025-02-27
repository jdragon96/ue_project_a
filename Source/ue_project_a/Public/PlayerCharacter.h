// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "MovieSceneSequenceID.h"
#include "MyMacro.h"
#include "PlayerCharacter.generated.h"

struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

/**
 * 
 */
UCLASS()
class UE_PROJECT_A_API APlayerCharacter : public ACharacterBase
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	/// <summary>
	/// 
	/// </summary>
	virtual void BeginPlay() override;

	

	/// <summary>
	/// �ִϸ��̼� Ʈ�����ǿ� ����Ѵ�
	/// </summary>
	DECLARE_ACCESSOR(ECharacterState, PlayerAnimState);
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animation")
	ECharacterState PlayerAnimState;
};
