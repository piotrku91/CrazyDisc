// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingBody.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMovingBody::UMovingBody()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UMovingBody::BeginPlay()
{
	Super::BeginPlay();

	BaseLocation_ = GetOwner()->GetActorLocation();
}

// Called every frame
void UMovingBody::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Move_component_active_ && Move_enabled_)
	{
		FVector CurrentLocation = GetOwner()->GetActorLocation();

		FVector TargetLocation = (Go_to_begin_) ? BaseLocation_ : BaseLocation_ + Offset_;

		float Speed = Offset_.Length() / Time_to_go_;

		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
		GetOwner()->SetActorLocation(NewLocation);

		if (Reverse_at_target_ && CurrentLocation == TargetLocation)
		{
			Go_to_begin_ = !Go_to_begin_;
		};
	}
};
