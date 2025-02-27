// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon/WeaponBase.h"
#include "Weapon/Bullet.h"
#include "Engine/DamageEvents.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "NiagaraSystem.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

}
//void WeaponBase::ClickLeftMouseBtn()
//{
//	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
//	UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("MuzzleFlashSocket"));
//
//	FHitResult Hit;
//	FVector ShotDirection;
//	bool bSuccess = GunTrace(Hit, ShotDirection);
//	if (bSuccess)
//	{
//		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShotDirection.Rotation());
//		UGameplayStatics::PlaySoundAtLocation(GetWorld(), ImpactSound, Hit.Location);
//		
//		AActor* HitActor = Hit.GetActor();
//		if (HitActor != nullptr)
//		{
//			FPointDamageEvent DamageEvent(Damage, Hit, ShotDirection, nullptr);
//			AController *OwnerController = GetOwnerController();
//			HitActor->TakeDamage(Damage, DamageEvent, OwnerController, this);
//		}
//	}
//
//}
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
}
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// 1. 총알 발사시간 간격을 충족 하였는지 검사
	if (WaitShot)
	{
		if (WatingTime > MaxWaitTime)
		{
			WaitShot = false;
			WatingTime = 0.f;
		}
	}
	// 2. 아직 대기중이면 대기시간 증가시키고 종료
	if (WaitShot)
		WatingTime += DeltaTime;
}
bool AWeaponBase::ClickLeftMouseBtn()
{
	if (WaitShot)
		return false;

	// 1. 총알 발사
	auto owner = GetOwner();
	if (auto World = GetWorld())
	{
		//TObjectPtr<ABullet> Bullet = World->SpawnActor<ABullet>();
		auto Bullet = World->SpawnActor<ABullet>(BulletClass, Mesh->GetSocketLocation("MuzzleFlashSocket"), GetActorRotation());
		Bullet->Shot(owner->GetActorForwardVector() * LaunchSpeed);
	}
	// 2. 물리법칙 적용
	// 3. 히트 체크
	// 4. 이펙트 적용
	if (WeaponEffect)
	{
		//UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAttached(
		//	WeaponEffect,                  // 사용할 Niagara System
		//	Mesh,                          // 부착할 컴포넌트 (Skeletal Mesh)
		//	TEXT("MuzzleFlashSocket"),         // 소켓 이름
		//	FVector::ZeroVector,                // 로컬 위치 오프셋 (소켓 기준)
		//	FRotator::ZeroRotator,              // 로컬 회전 오프셋
		//	EAttachLocation::KeepRelativeOffset,// 부착 방식 (소켓 위치 유지)
		//	true                               // AutoDestroy: 효과 종료 후 자동 소멸
		//);
	}
	WaitShot = true;
	return true;
}
void AWeaponBase::ClickRightMouseBtn()
{
	return true;
}