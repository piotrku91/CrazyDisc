// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DiscMachine.h"
#include "ScouterMachine.generated.h"

UCLASS()
class CRAZYDISC_API AScouterMachine : public ADiscMachine
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;
	virtual void Die() override;

private:
	class APlayerMachine* Player_machine_;
	FTimerHandle ShootTimer_;

	bool InRangeToAttack();
	void AttackIfNeccessary();

protected:
	virtual void BeginPlay() override;
	virtual void FireFirstWeapon() override;

	UPROPERTY(EditAnywhere, Category = "Security area settings")
	FVector Start_point_;

	UPROPERTY(EditAnywhere, Category = "Security area settings")
	FVector End_point_;

	UPROPERTY(EditAnywhere, Category = "Security area settings")
	float Minimum_detection_distance = 1000;

	UPROPERTY(EditAnywhere, Category = "Security")
	float Attack_interval_ = 0.5;

	UPROPERTY(EditAnywhere, Category = "Security")
	float Expected_position_player_X_offset = 200;

	UPROPERTY(EditAnywhere, Category = "Security")
	float Expected_position_player_Y_offset = 0;

	UPROPERTY(EditAnywhere, Category = "Security")
	float Expected_position_player_Z_offset = 100;

};
