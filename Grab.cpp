// Fill out your copyright notice in the Description page of Project Settings.


#include "Grab.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"


// Sets default values for this component's properties
UGrab::UGrab()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UGrab::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrab::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Component should rotated in blueprint -90 degrees in PITCH rotation to trace under the disc.
	FVector StartPoint = GetComponentLocation();
	FVector EndPoint = StartPoint + GetForwardVector() * 200;
	DrawDebugLine(GetWorld(), StartPoint, EndPoint, FColor::Red);

	FCollisionShape CollisionShphere = FCollisionShape::MakeSphere(100);
	FHitResult HitResult;
	bool Hit = GetWorld()->SweepSingleByChannel(HitResult, StartPoint, EndPoint,FQuat::Identity, ECC_GameTraceChannel1,CollisionShphere);

}

