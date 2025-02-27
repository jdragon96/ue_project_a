#include "Weapon/Bullet.h"
#include "Components/SphereComponent.h"

ABullet::ABullet()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	//Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	//Mesh->SetupAttachment(Root);
	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletSphere"));
	BulletMesh->SetupAttachment(Root);
	BulletMesh->SetSimulatePhysics(true);
	BulletMesh->SetEnableGravity(true);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (SphereMeshAsset.Succeeded())
	{
		BulletMesh->SetStaticMesh(SphereMeshAsset.Object);
		BulletMesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f)); // 크기 조정 (선택)
		BulletMesh->SetMassOverrideInKg(NAME_None, BulletMass, true);
	}
}

void ABullet::BeginPlay()
{
	Super::BeginPlay();
}

void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABullet::Shot(FVector vel)
{
	if (BulletMesh)
		BulletMesh->AddImpulse(vel, NAME_None, true); // 물리 기반 힘 적용
}