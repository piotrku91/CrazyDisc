// Fill out your copyright notice in the Description page of Project Settings.

#include "GameBall.h"
#include "PlayerMachine.h"
#include "Bullet.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGameBall::AGameBall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MeshComponentBall_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	RootComponent = MeshComponentBall_;
}

// Called when the game starts or when spawned
void AGameBall::BeginPlay()
{
	Super::BeginPlay();

	Player_machine_ = Cast<APlayerMachine>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	MeshComponentBall_->OnComponentHit.AddDynamic(this, &AGameBall::OnHit);
}

// Called every frame
void AGameBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGameBall::ExecuteAttack()
{
	if (Player_machine_)
	{
		FVector PlayerLocation{Player_machine_->GetActorLocation()};
		FVector BallLocation{GetActorLocation()};
		MeshComponentBall_->AddImpulse(PlayerLocation - BallLocation, NAME_None, true);
	}
}

void AGameBall::Die()
{
	Destroy();
}

void AGameBall::OnHit(UPrimitiveComponent *HitComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &Hit)
{
	if (OtherActor && OtherActor != this && OtherActor == Player_machine_)
	{
		UGameplayStatics::ApplyDamage(OtherActor, 75, GetInstigatorController(), this, UDamageType::StaticClass());
		Die();
	} 
}
