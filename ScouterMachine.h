// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DiscMachine.h"
#include "IEnemyAttacker.h"
#include "IEnemyPatrol.h"
#include "ScouterMachine.generated.h"

UCLASS()
class CRAZYDISC_API AScouterMachine : public ADiscMachine, public IEnemyAttacker, public IEnemyPatrol
{
	GENERATED_BODY()

public:
	AScouterMachine();

	virtual void Tick(float DeltaTime) override;
	virtual void Die() override;

	// Pure overrides
	virtual void ExecuteAttack() override;
	virtual float GetAttackInterval() override {return Attack_interval_;};
	virtual class UMovingBody* GetMovingBodyComponent() override {return MovingBodyComponent_;};
    virtual float GetMinimumDistanceToDetection() override {return Minimum_detection_distance;};

	UPROPERTY(EditAnywhere, Category = "Security area settings")
	float Minimum_detection_distance = 1000;

	UPROPERTY(EditAnywhere, Category = "Security")
	float Attack_interval_ = 0.5;

private:
	class APlayerMachine* Player_machine_;
	
protected:
	virtual void BeginPlay() override;
	virtual void FireFirstWeapon() override;

	UPROPERTY(EditAnywhere)
	class UMovingBody *MovingBodyComponent_;

	

	

};
