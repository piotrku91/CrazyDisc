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

        auto PlayerFowardVector = Player_machine_->GetRootComponentForwardVector();

        FVector ExpectedNextLocation = PlayerLocation - PlayerFowardVector;

        ExpectedNextLocation.X += Expected_position_player_X_offset;
        ExpectedNextLocation.Y += Expected_position_player_Y_offset;
        ExpectedNextLocation.Z += Expected_position_player_Z_offset;

        FVector ScouterLocation = GetActorLocation();

        FVector LocationsSumVector = ExpectedNextLocation - ScouterLocation;

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