// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MeshComponentBullet_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet"));
	RootComponent = MeshComponentBullet_;

	MovementComponentBullet_ = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Bullet movement component"));
	MovementComponentBullet_->MaxSpeed = 1000.f;
	MovementComponentBullet_->InitialSpeed = 800.f;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	MeshComponentBullet_->OnComponentHit.AddDynamic(this, &ABullet::OnHit);

}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::OnHit(UPrimitiveComponent *HitComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &Hit)
{
	UE_LOG(LogTemp, Display, TEXT("OnHit"));
	UE_LOG(LogTemp, Display, TEXT("HitComp: %s"), *HitComp->GetName());
	UE_LOG(LogTemp, Display, TEXT("OtherActor: %s"), *OtherActor->GetName());
	UE_LOG(LogTemp, Display, TEXT("OtherComp: %s"), *OtherComp->GetName());
}


