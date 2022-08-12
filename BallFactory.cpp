// Fill out your copyright notice in the Description page of Project Settings.

#include "BallFactory.h"
#include "Gameball.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABallFactory::ABallFactory()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Factory"));
	MeshComponent_->SetupAttachment(RootComponent);

	BallSpawnPointComponent_ = CreateDefaultSubobject<USceneComponent>(TEXT("Ball spawn point"));
	BallSpawnPointComponent_->SetupAttachment(MeshComponent_);
}

// Called when the game starts or when spawned
void ABallFactory::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(BallFactoryProductionTimer, this, &ABallFactory::ProduceNewBall, Produce_Interval_, true);
}
// Called every frame
void ABallFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location{RootComponent->GetForwardVector()};
	Location = Location * 200;
	MeshComponent_->AddImpulse(Location, NAME_None, true);

	if (Flying_Factory_)
	{
		FRotator NewRotation{180 * DeltaTime, 180 * DeltaTime, 180 * DeltaTime};
		RootComponent->AddLocalRotation(NewRotation, true);
	};
}

void ABallFactory::ProduceNewBall()
{
	if (Spawned_ <= Max_Balls_Per_Level_)
	{

		FVector SpawnLocation = BallSpawnPointComponent_->GetComponentLocation();
		FRotator SpawnRotation = BallSpawnPointComponent_->GetComponentRotation();

		GetWorld()->SpawnActor<AGameBall>(BallClass, SpawnLocation, SpawnRotation);
		Spawned_++;
	}
}
