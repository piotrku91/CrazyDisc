// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ScouterAIController.generated.h"

/**
 */
UCLASS()
class CRAZYDISC_API AScouterAIController : public AAIController
{
	GENERATED_BODY()
	
	private:
	virtual void Tick(float DeltaTime) override;
	FTimerHandle ShootTimer_;

	APawn* PlayerPawn_;
	APawn* ControlledPawn_;
	class IEnemyAttacker* EnemyAttackerHandle_;
	class IEnemyPatrol* EnemyPatrolHandle_;

	protected:
	virtual void BeginPlay() override;
	void AttackIfNeccessary();
	bool InRange();
	
};
