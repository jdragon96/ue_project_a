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
	* @name ���� ���� ���� �� ȣ��
	* @return
	*/
	virtual void BeginPlay() override;

	/**
	* @name Ŀ���� �Է� ���ε��� �����ϰ� ��
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
	* @name ĳ���� �̵� ó��
	* @param InputActionValue ĳ���� �Է� ��Ȳ
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

