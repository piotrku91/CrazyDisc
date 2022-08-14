// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CrazyDiscPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CRAZYDISC_API ACrazyDiscPlayerController : public APlayerController
{
	GENERATED_BODY()

	public:
	void SetPlayerState(bool state);
	
};
