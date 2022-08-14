// Fill out your copyright notice in the Description page of Project Settings.

#include "ScouterMachine.h"
#include "PlayerMachine.h"
#include "Kismet/GameplayStatics.h"

//////////////////////////////////////////////////////////////////////////////////////////
void AScouterMachine::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (InRangeToAttack())
    {
        FVector PlayerLocation = Player_machine_->GetActorLocation();
        FVector ScouterLocation = GetActorLocation();

        FVector LocationsSumVector = PlayerLocation - ScouterLocation;

        FRotator CalculatedRotation = LocationsSumVector.Rotation();

        SetActorRotation(CalculatedRotation);
    };
}
//////////////////////////////////////////////////////////////////////////////////////////
void AScouterMachine::BeginPlay()
{
    Super::BeginPlay();

    Player_machine_ = Cast<APlayerMachine>(UGameplayStatics::GetPlayerPawn(this, 0));

    GetWorldTimerManager().SetTimer(ShootTimer_, this, &AScouterMachine::AttackIfNeccessary, Attack_interval_, true);
}
//////////////////////////////////////////////////////////////////////////////////////////
void AScouterMachine::Die()
{
Destroy();
}
//////////////////////////////////////////////////////////////////////////////////////////

bool AScouterMachine::InRangeToAttack()
{
    if (Player_machine_)
    {
        float Distance = FVector::Dist(GetActorLocation(), Player_machine_->GetActorLocation());

        if (Distance <= Minimum_detection_distance)
        {
            return true;
        }
    };
    return false;
}
//////////////////////////////////////////////////////////////////////////////////////////
void AScouterMachine::AttackIfNeccessary()
{
    if (InRangeToAttack())
    {
        FireFirstWeapon();
    };
}
//////////////////////////////////////////////////////////////////////////////////////////