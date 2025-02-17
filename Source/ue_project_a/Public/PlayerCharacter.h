// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "PlayerCharacter.generated.h"

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
	/// ĳ���� �ִϸ��̼� ���¸� �����Ѵ�.
	/// </summary>
	/// <param name="state">ĳ���� �ִϸ��̼� ����</param>
	void SetAnimState(ECharacterState state);

	/// <summary>
	/// �ִϸ��̼� ���¸� ��ȯ�Ѵ�.
	/// </summary>
	/// <returns></returns>
	ECharacterState GetAnimState();

	/// <summary>
	/// 
	/// </summary>
	virtual void BeginPlay() override;

	/// <summary>
	/// 
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
	ECharacterState PlayerAnimState;
};
