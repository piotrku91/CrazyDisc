// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBall.h"
#include "PlayerMachine.h"
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
	
}

// Called every frame
void AGameBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameBall::ExecuteAttack()
{
		FVector Location{RootComponent->GetForwardVector()};
		MeshComponentBall_->AddImpulse(Location, NAME_None, true);

}

