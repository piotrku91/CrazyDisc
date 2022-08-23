// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MovingBody.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRAZYDISC_API UMovingBody : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMovingBody();

	UPROPERTY(EditAnywhere)
	bool Move_component_active_ = false;

	UPROPERTY(EditAnywhere)
	bool Move_enabled_ = false;

	UPROPERTY(EditAnywhere)
	bool Reverse_at_target_ = false;

	void SetGoDirection(bool go_to_begin) {Go_to_begin_ = go_to_begin;};

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	FVector Offset_;

	UPROPERTY(EditAnywhere)
	float Time_to_go_ = 5;

	private:
	bool Go_to_begin_ = false;
	FVector BaseLocation_;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
