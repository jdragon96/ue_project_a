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

	/**
	* @name 게임 적용 시작 시 호출
	* @return
	*/
	virtual void BeginPlay() override;

	/**
	* @name 커스텀 입력 바인딩을 가능하게 함
	* @return
	*/
	virtual void SetupInputComponent() override;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="DeltaTime"></param>
	/// <param name="bGamePaused"></param>
	virtual void PreProcessInput(const float DeltaTime, const bool bGamePaused) override;

private:
	/**
	* @name 캐릭터 이동 처리
	* @param InputActionValue 캐릭터 입력 현황
	* @return 
	*/
	void Move(const FInputActionValue& InputActionValue);

private:
	/// <summary>
	/// 
	/// </summary>
	TObjectPtr<APlayerCharacter> OwnerActor;

	/// <summary>
	/// 
	/// </summary>
	TObjectPtr<UInputMappingContext> PlayerContext;

	/// <summary>
	/// 
	/// </summary>
	TObjectPtr<UPlayerAnimation> OwnerAnimation;

	/// <summary>
	/// 
	/// </summary>
	TObjectPtr<UInputAction> MoveAction;

	/// <summary>
	/// 
	/// </summary>
	TObjectPtr<UQuaterViewIMC> InputMappingContext;
};

