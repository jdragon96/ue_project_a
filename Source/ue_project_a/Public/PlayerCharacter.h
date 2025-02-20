// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "MovieSceneSequenceID.h"
#include "PlayerCharacter.generated.h"

struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

#define DECLARE_ACCESSOR(Type, VarName) \
		FORCEINLINE Type Get##VarName() const { return VarName; }\
    FORCEINLINE void Set##VarName(Type NewValue) { VarName = NewValue; };

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
	/// 애니메이션 트랜지션에 사용한다
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
	ECharacterState PlayerAnimState;

	DECLARE_ACCESSOR(ECharacterState, PlayerAnimState);
};
