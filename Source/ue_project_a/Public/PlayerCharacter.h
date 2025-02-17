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
	/// 캐릭터 애니메이션 상태를 설정한다.
	/// </summary>
	/// <param name="state">캐릭터 애니메이션 상태</param>
	void SetAnimState(ECharacterState state);

	/// <summary>
	/// 애니메이션 상태를 반환한다.
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
