// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

// UENUM 매크로를 사용하여 Enum 정의
UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	IDLE  UMETA(DisplayName = "Standing"),
	WALK UMETA(DisplayName = "Walking"),
	RUN  UMETA(DisplayName = "Running")
};

UCLASS()
class UE_PROJECT_A_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
