// Fill out your copyright notice in the Description page of Project Settings.


#include "BallFactory.h"

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

}

void ABallFactory::ProduceNewBall()
{
UE_LOG(LogTemp, Display, TEXT("New one!"));
}

