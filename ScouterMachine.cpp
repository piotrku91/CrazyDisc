// Fill out your copyright notice in the Description page of Project Settings.

#include "ScouterMachine.h"
#include "PlayerMachine.h"
#include "Bullet.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Math/Vector.h"
#include "MovingBody.h"

AScouterMachine::AScouterMachine()
{
    MovingBodyComponent_ = CreateDefaultSubobject<UMovingBody>(TEXT("MovingBody"));
}

//////////////////////////////////////////////////////////////////////////////////////////
void AScouterMachine::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (InRangeToAttack())
    {
       if (MovingBodyComponent_->Move_component_active_) {MovingBodyComponent_->Move_enabled_ = false;};
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
    }
    else
    {
        if (MovingBodyComponent_->Move_component_active_) {MovingBodyComponent_->Move_enabled_ = true;};
}
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
void AScouterMachine::FireFirstWeapon()
{
    FVector SpawnLocation = WeaponComponentSpawnPoint_->GetComponentLocation();
	FRotator SpawnRotation = WeaponComponentSpawnPoint_->GetComponentRotation();

	auto SpawnedBullet = GetWorld()->SpawnActor<ABullet>(BulletClassFirst, SpawnLocation, SpawnRotation);
	SpawnedBullet->SetOwner(this);
}