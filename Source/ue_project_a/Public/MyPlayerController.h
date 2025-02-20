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
	/// �Է� �׼� ���ε�
	/// </summary>
	virtual void SetupInputComponent() override;

	/// <summary>
	/// �Է� �� �ʱ�ȭ
	/// </summary>
	/// <param name="DeltaTime"></param>
	/// <param name="bGamePaused"></param>
	virtual void PreProcessInput(const float DeltaTime, const bool bGamePaused) override;

	/// <summary>
	/// �Է� �� ó��
	/// </summary>
	/// <param name="DeltaTime"></param>
	/// <param name="bGamePaused"></param>
	virtual void PostProcessInput(const float DeltaTime, const bool bGamePaused) override;

private:
	/// <summary>
	/// ĳ���� �Է� ó��
	/// </summary>
	/// <param name="InputActionValue"></param>
	void LookUp(const FInputActionValue& InputActionValue);
	void LookRight(const FInputActionValue& InputActionValue);
	void LookAround(const FInputActionValue& InputActionValue);
	void MoveForward(const FInputActionValue& InputActionValues);
	void MoveRight(const FInputActionValue& InputActionValues);

	/// <summary>
	/// �Է� �׼� �ʱ�ȭ�ϱ�
	/// </summary>
	void InitAction();

	/// <summary>
	/// �Է°��� ������� ĳ���� ���� ����
	/// </summary>
	void UpdateInputState();

private:
	/// <summary>
	/// ĳ����, �ִϸ��̼� �ν��Ͻ� ������
	/// </summary>
	TObjectPtr<APlayerCharacter> OwnerActor;
	TObjectPtr<UPlayerAnimation> OwnerAnimation;


	/// <summary>
	/// ĳ���� �Է� �׼�
	/// </summary>
	TObjectPtr<UInputMappingContext> PlayerContext;
	TObjectPtr<UInputAction> LookUpAction;
	TObjectPtr<UInputAction> LookRightAction;
	TObjectPtr<UInputAction> LookAroundAction;
	TObjectPtr<UInputAction> MoveForwardAction;
	TObjectPtr<UInputAction> MoveRightAction;

	/// <summary>
	/// ĳ���� �̵� ���⺤��
	/// </summary>
	FVector MoveVector;
};

