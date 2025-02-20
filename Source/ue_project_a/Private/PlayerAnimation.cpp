// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimation.h"
#include "Animation/AnimSequence.h"
#include "Animation/ActiveStateMachineScope.h"
#include "Animation/AnimNode_StateMachine.h"
#include "Animation/AnimNodeBase.h"
#include "PlayerCharacter.h"


UPlayerAnimation::UPlayerAnimation()
{
	//CurrentState = ECharacterState::IDLE;
	AnimState = ECharacterState::IDLE;
}

void UPlayerAnimation::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (OwnerActor == nullptr)
	{
		OwnerActor = Cast<APlayerCharacter>(TryGetPawnOwner());
	}
}

void UPlayerAnimation::NativeUpdateAnimation(float DeltaTimeX)
{
	Super::NativeUpdateAnimation(DeltaTimeX);
	if (!OwnerActor)
		return;
	AnimState = OwnerActor->GetPlayerAnimState();
}

void UPlayerAnimation::SetAnimState(ECharacterState state)
{
	AnimState = state;
}