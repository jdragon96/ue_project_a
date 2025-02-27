// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

class UNiagaraSystem;
class USphereComponent;

UCLASS()
class UE_PROJECT_A_API ABullet : public AActor
{
	GENERATED_BODY()

public:
	ABullet();

	void Shot(FVector vel);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double BulletMass = 0.00395;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USceneComponent> Root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> BulletMesh;
};
