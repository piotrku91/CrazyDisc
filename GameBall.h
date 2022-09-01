// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "IEnemyAttacker.h"
#include "IEnemyPatrol.h"
#include "GameBall.generated.h"

UCLASS()
class CRAZYDISC_API AGameBall : public APawn, public IEnemyAttacker, public IEnemyPatrol
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameBall();

	// Pure overrides
	virtual void ExecuteAttack() override;
	virtual float GetAttackInterval() override {return Attack_interval_;};
	virtual class UMovingBody* GetMovingBodyComponent() override {return nullptr;};
    virtual float GetMinimumDistanceToDetection() override {return Minimum_detection_distance;};

private:
	UStaticMeshComponent* MeshComponentBall_;
	class APlayerMachine* Player_machine_;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Security area settings")
	float Minimum_detection_distance = 1000;

	UPROPERTY(EditAnywhere, Category = "Security")
	float Attack_interval_ = 0.5;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
