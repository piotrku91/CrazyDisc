// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallFactory.generated.h"

UCLASS()
class CRAZYDISC_API ABallFactory : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABallFactory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent *MeshComponent_;

	UPROPERTY(EditAnywhere)
	USceneComponent *BallSpawnPointComponent_;

	UPROPERTY(EditAnywhere, Category = "Production")
	float Produce_Interval_ = 5.f;

	UPROPERTY(EditAnywhere, Category = "Production")
	float Max_Balls_Per_Level_ = 100.f;

	UPROPERTY(EditAnywhere, Category = "Production")
	bool Flying_Factory_ = true;

private:
	FTimerHandle BallFactoryProductionTimer;
	int Spawned_ = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Production")
	TSubclassOf<class AGameBall> BallClass;

	void ProduceNewBall();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
