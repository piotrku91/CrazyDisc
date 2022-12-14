// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CrazyDiscGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CRAZYDISC_API ACrazyDiscGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void SomeActorDied(AActor* DeadActor);
	void UpdateHealthIfItIsAPlayer(AActor* Actor, float CurrentHealth);
	void UpdatePlayerUltraSpeedFuel(float SpeedFuel, float MaxSpeedFuel);

	UFUNCTION(BlueprintImplementableEvent)
	void HealthHUDUpdate(float NewHealthValue);

	UFUNCTION(BlueprintImplementableEvent)
	void UltraSpeedFuelHUDUpdate(float SpeedFuelValue);

protected:

	virtual void BeginPlay() override;
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void GameStartBegin();

private:
	class APlayerMachine* PlayerMachine_;
	class ACrazyDiscPlayerController* PlayerController_;

	void PlayerDied();
	
};
