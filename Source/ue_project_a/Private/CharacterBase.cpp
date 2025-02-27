// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include "Weapon/WeaponBase.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	{
		//Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
		//Weapon->SetupAttachment(GetMesh(), FName("WeaponSocket"));
		//Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
	{
		auto worl = GetWorld();
		WeaponPtr = worl->SpawnActor<AWeaponBase>(WeaponClass);
		WeaponPtr->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
		WeaponPtr->SetOwner(this);
		//GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	}
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharacterBase::ClickMouseLeftButton()
{
	// 1. 무기 이팩트 처리
	if (WeaponPtr)
	{
		WeaponPtr->ClickLeftMouseBtn();
	}
	// 2. 물리효과 적용

}

void ACharacterBase::ClickMouseRightButton()
{
}

