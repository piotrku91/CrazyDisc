// Fill out your copyright notice in the Description page of Project Settings.


#include "CrazyDiscGameMode.h"
#include "PlayerMachine.h"
#include "ScouterMachine.h"
#include "CrazyDiscPlayerController.h"
#include "Kismet/GameplayStatics.h"
//////////////////////////////////////////////////////////////////////////////////////////
void ACrazyDiscGameMode::SomeActorDied(AActor *DeadActor)
{
    if (DeadActor == PlayerMachine_)
    {
       PlayerDied();
    }
    else if (AScouterMachine* ScouterMachine = Cast<AScouterMachine>(DeadActor))
    {
        ScouterMachine->Die();
    }
} 
//////////////////////////////////////////////////////////////////////////////////////////
void ACrazyDiscGameMode::PlayerDied()
{
     PlayerMachine_->Die();
        if (PlayerController_)
        {
            PlayerController_->SetPlayerState(false);
        }
}
//////////////////////////////////////////////////////////////////////////////////////////
void ACrazyDiscGameMode::BeginPlay()
{
    Super::BeginPlay();

    PlayerMachine_ = Cast<APlayerMachine>(UGameplayStatics::GetPlayerPawn(this, 0));
    PlayerController_ = Cast<ACrazyDiscPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

    StartGame();

}
//////////////////////////////////////////////////////////////////////////////////////////
void ACrazyDiscGameMode::StartGame()
{
    PlayerController_->SetPlayerState(true);

}
//////////////////////////////////////////////////////////////////////////////////////////