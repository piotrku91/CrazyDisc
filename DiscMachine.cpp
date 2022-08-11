// Fill out your copyright notice in the Description page of Project Settings.


#include "DiscMachine.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADiscMachine::ADiscMachine()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent_ = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collider"));
	RootComponent = SphereComponent_;

	MeshComponentDisc_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Disc"));
	MeshComponentDisc_->SetupAttachment(SphereComponent_);

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
	if (InputValue > 0) {
	SphereComponent_->SetEnableGravity(false);
	float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	FVector NewLocation{InputValue * DeltaTime * Acceleration_Speed_Rate_, 0 , 0};
	AddActorLocalOffset(NewLocation);
	}
	else
	{
	SphereComponent_->SetEnableGravity(true);
	}
}

void ADiscMachine::ChangeDirection(float InputValue)
{
	float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	FRotator NewRotation{0, InputValue * DeltaTime * Direction_Speed_Rate_, 0};
	AddActorLocalRotation(NewRotation, true);
}

void ADiscMachine::ChangeDirectionToLeft(float InputValue)
{
	ChangeDirection(InputValue);
}

void ADiscMachine::ChangeDirectionToRight(float InputValue)
{
	ChangeDirection(-InputValue);
}

void ADiscMachine::ChangeBalance(float InputX)
{
	float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	FRotator NewRotation{0, 0, InputX * DeltaTime * Balance_Speed_Rate_};
	AddActorLocalRotation(NewRotation, true);
}

void ADiscMachine::ChangeUpDown(float InputY)
{
	if (UpDown_Inversion_) {InputY = -InputY;};
	float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	FRotator NewRotation{InputY * DeltaTime * UpDown_Speed_Rate_, 0, 0};
	AddActorLocalRotation(NewRotation, true);
	
}

