// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

class UNiagaraSystem;
class ABullet;

UCLASS()
class UE_PROJECT_A_API AWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeaponBase();

	virtual bool ClickLeftMouseBtn();
	virtual bool ClickRightMouseBtn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double MaxWaitTime = 0.2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double LaunchSpeed = 10000;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USceneComponent> Root;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USkeletalMeshComponent> Mesh;

	UPROPERTY(EditAnywhere, Category="Bullet")
	TSubclassOf<ABullet> BulletClass;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UParticleSystem> MuzzleFlash;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UNiagaraSystem> WeaponEffect;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USoundBase> MuzzleSound;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UParticleSystem> ImpactEffect;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USoundBase> ImpactSound;


private:
	float WatingTime = 0.f;
	bool WaitShot = false;
};
