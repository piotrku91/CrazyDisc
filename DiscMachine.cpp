// Fill out your copyright notice in the Description page of Project Settings.


#include "DiscMachine.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADiscMachine::ADiscMachine()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent_ = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = CapsuleComponent_;

	MeshComponentDisc_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Disc"));
	MeshComponentDisc_->SetupAttachment(CapsuleComponent_);

	MeshComponentBall_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	MeshComponentBall_->SetupAttachment(MeshComponentDisc_);

	MeshComponentCannon_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cannon"));
	MeshComponentCannon_->SetupAttachment(MeshComponentDisc_);

}

// Called when the game starts or when spawned
void ADiscMachine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADiscMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADiscMachine::Fly(float InputValue)
{
	float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	FVector NewLocation{InputValue * DeltaTime * Speed_, 0 , 0};
	AddActorLocalOffset(NewLocation);
}
