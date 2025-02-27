// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class USkeletalMeshComponent;
class AWeaponBase;

// UENUM 매크로를 사용하여 Enum 정의
UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	IDLE  UMETA(DisplayName = "Standing"),
	WALK	UMETA(DisplayName = "Walking"),
	RUN		UMETA(DisplayName = "Running"),
	JUMP  UMETA(DisplayName = "Jumping"),
	// WALK
	// RUN
	RUN_FORWARD  UMETA(DisplayName = "RUN_FORWARD"),
	RUN_FORWARD_LEFT  UMETA(DisplayName = "RUN_FORWARD_LEFT"),
	RUN_FORWARD_RIGHT  UMETA(DisplayName = "RUN_FORWARD_RIGHT"),
	RUN_LEFT  UMETA(DisplayName = "RUN_LEFT"),
	RUN_RIGHT  UMETA(DisplayName = "RUN_RIGHT"),
	RUN_BACK  UMETA(DisplayName = "RUN_BACK"),
	RUN_BACK_LEFT  UMETA(DisplayName = "RUN_BACK_LEFT"),
	RUN_BACK_RIGHT  UMETA(DisplayName = "RUN_BACK_RIGHT")
};

UCLASS()
class UE_PROJECT_A_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 왼쪽 마우스 클릭 이벤트
	virtual void ClickMouseLeftButton();

	// 왼쪽 마우스 클릭 이벤트
	virtual void ClickMouseRightButton();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<AWeaponBase> WeaponClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
	TObjectPtr<AWeaponBase> WeaponPtr;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
