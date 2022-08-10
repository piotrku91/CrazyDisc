// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DiscMachine.h"
#include "PlayerMachine.generated.h"

/**
 *
 */
UCLASS()
class CRAZYDISC_API APlayerMachine : public ADiscMachine
{
	GENERATED_BODY()

public:
	APlayerMachine();

protected:
	UPROPERTY(EditAnywhere)
	class USpringArmComponent *SpringArm_;

	UPROPERTY(EditAnywhere)
	class UCameraComponent *CameraComponent_;

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;
};
