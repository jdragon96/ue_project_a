// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimSequence.h"
#include "CharacterBase.h"
#include "PlayerAnimation.generated.h"


//class UAnimSequence;
struct FAnimNode_StateMachine;
class APlayerCharacter;

/**
 *
 */
UCLASS()
class UE_PROJECT_A_API UPlayerAnimation : public UAnimInstance
{
	GENERATED_BODY()

public:

	UPlayerAnimation();

	/**
	*
	* @return
	*/
	virtual void NativeInitializeAnimation() override;

	/**
	*
	*	@param DeltaTimeX �ð� ��ȭ��
	* @return
	*/
	virtual void NativeUpdateAnimation(float DeltaTimeX) override;

	void SetAnimState(ECharacterState state);


public:
	/// <summary>
	/// �ִϸ��̼� ����
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
	ECharacterState AnimState;

	/// <summary>
	/// �ִϸ��̼��� �����ϰ� �ִ� ��ü
	/// </summary>
	TObjectPtr<APlayerCharacter> OwnerActor;
};
