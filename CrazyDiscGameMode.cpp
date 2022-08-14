// Fill out your copyright notice in the Description page of Project Settings.


#include "CrazyDiscGameMode.h"
#include "PlayerMachine.h"
#include "ScouterMachine.h"
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
        if (PlayerMachine_->GetPlayerController())
        {
            PlayerMachine_->DisableInput(PlayerMachine_->GetPlayerController());
            PlayerMachine_->GetPlayerController()->bShowMouseCursor = false;
        }
}
//////////////////////////////////////////////////////////////////////////////////////////
void ACrazyDiscGameMode::BeginPlay()
{
    Super::BeginPlay();

    PlayerMachine_ = Cast<APlayerMachine>(UGameplayStatics::GetPlayerPawn(this, 0));
}
//////////////////////////////////////////////////////////////////////////////////////////