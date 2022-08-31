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

  //  if (InRangeToAttack())
   // {
     /*   if (MovingBodyComponent_->Move_component_active_) {MovingBodyComponent_->Move_enabled_ = false;};
    }
    else
    {
       // if (MovingBodyComponent_->Move_component_active_) {MovingBodyComponent_->Move_enabled_ = true;};
}*/
//};
}
//////////////////////////////////////////////////////////////////////////////////////////
void AScouterMachine::BeginPlay()
{
    Super::BeginPlay();

    Player_machine_ = Cast<APlayerMachine>(UGameplayStatics::GetPlayerPawn(this, 0));

}
//////////////////////////////////////////////////////////////////////////////////////////
void AScouterMachine::Die()
{
Destroy();
}

//////////////////////////////////////////////////////////////////////////////////////////
void AScouterMachine::ExecuteAttack()
{
    FireFirstWeapon();
}
//////////////////////////////////////////////////////////////////////////////////////////
void AScouterMachine::FireFirstWeapon()
{
    FVector SpawnLocation = WeaponComponentSpawnPoint_->GetComponentLocation();
	FRotator SpawnRotation = WeaponComponentSpawnPoint_->GetComponentRotation();

	auto SpawnedBullet = GetWorld()->SpawnActor<ABullet>(BulletClassFirst, SpawnLocation, SpawnRotation);
	SpawnedBullet->SetOwner(this);
}