// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CharacterBase.h"
#include "MyPlayerController.generated.h"

class UInputAction;
struct FInputActionValue;
class UInputMappingContext;
class UQuaterViewIMC;
class APlayerCharacter;
class UPlayerAnimation;
/**
 *
 */
UCLASS()
class UE_PROJECT_A_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMyPlayerController();

protected:
	/// <summary>
	/// 
	/// </summary>
	virtual void BeginPlay() override;

	/// <summary>
	/// 입력 액션 바인딩
	/// </summary>
	virtual void SetupInputComponent() override;

	/// <summary>
	/// 입력 전 초기화
	/// </summary>
	/// <param name="DeltaTime"></param>
	/// <param name="bGamePaused"></param>
	virtual void PreProcessInput(const float DeltaTime, const bool bGamePaused) override;

	/// <summary>
	/// 입력 후 처리
	/// </summary>
	/// <param name="DeltaTime"></param>
	/// <param name="bGamePaused"></param>
	virtual void PostProcessInput(const float DeltaTime, const bool bGamePaused) override;

private:
	/// <summary>
	/// 캐릭터 입력 처리
	/// </summary>
	/// <param name="InputActionValue"></param>
	void LookUp(const FInputActionValue& InputActionValue);
	void LookRight(const FInputActionValue& InputActionValue);
	void LookAround(const FInputActionValue& InputActionValue);
	void MoveForward(const FInputActionValue& InputActionValues);
	void MoveRight(const FInputActionValue& InputActionValues);

	/// <summary>
	/// 입력 액션 초기화하기
	/// </summary>
	void InitAction();

	/// <summary>
	/// 입력값을 기반으로 캐릭터 상태 갱신
	/// </summary>
	void UpdateInputState();

private:
	/// <summary>
	/// 캐릭터, 애니메이션 인스턴스 포인터
	/// </summary>
	TObjectPtr<APlayerCharacter> OwnerActor;
	TObjectPtr<UPlayerAnimation> OwnerAnimation;


	/// <summary>
	/// 캐릭터 입력 액션
	/// </summary>
	TObjectPtr<UInputMappingContext> PlayerContext;
	TObjectPtr<UInputAction> LookUpAction;
	TObjectPtr<UInputAction> LookRightAction;
	TObjectPtr<UInputAction> LookAroundAction;
	TObjectPtr<UInputAction> MoveForwardAction;
	TObjectPtr<UInputAction> MoveRightAction;

	/// <summary>
	/// 캐릭터 이동 방향벡터
	/// </summary>
	FVector MoveVector;
};

