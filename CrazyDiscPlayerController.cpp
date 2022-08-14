// Fill out your copyright notice in the Description page of Project Settings.


#include "CrazyDiscPlayerController.h"
#include "GameFramework/Pawn.h"


void ACrazyDiscPlayerController::SetPlayerState(bool state)
{
    if (state)
    {
        GetPawn()->EnableInput(this);
    }
    else
    {
        GetPawn()->DisableInput(this);
    }
}
