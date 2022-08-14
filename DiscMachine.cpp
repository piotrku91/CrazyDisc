// Fill out your copyright notice in the Description page of Project Settings.

#include "DiscMachine.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Bullet.h"

// Sets default values
ADiscMachine::ADiscMachine()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent_ = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collider"));
	RootComponent = SphereComponent_;

	MeshComponentDisc_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Disc"));
	MeshComponentDisc_->SetupAttachment(RootComponent);

	MeshComponentBall_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	MeshComponentBall_->SetupAttachment(MeshComponentDisc_);

	MeshComponentCannon_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cannon"));
	MeshComponentCannon_->SetupAttachment(MeshComponentDisc_);

	WeaponComponentSpawnPoint_ = CreateDefaultSubobject<USceneComponent>(TEXT("Weapon spawn point"));
	WeaponComponentSpawnPoint_->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADiscMachine::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(UltraSpeedFuelValueRecoverTimer, this, &ADiscMachine::RecoverUltraSpeedFuelValue, Ultra_Speed_Recover_Time_, true);
}

// Called every frame
void ADiscMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADiscMachine::Accelerate(float InputValue)
{
	if (InputValue > 0)
	{
		float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
		float acceleration = Acceleration_Speed_Rate_;
		if (Ultra_Speed_Allowed_ && Ultra_Speed_Active_)
		{
			acceleration = Acceleration_Speed_Rate_ + Ultra_Speed_Amount_;
			DecraseUltraSpeedFuelValue(1);
		};
		FVector NewLocation{InputValue * DeltaTime * acceleration, 0, 0};
		AddActorLocalOffset(NewLocation);
	}
	else
	{
		if (Slow_Down_Active_)
		{
			FVector LocationForSlowDown{RootComponent->GetForwardVector()};
			LocationForSlowDown = LocationForSlowDown * Slow_Down_time_;
			SphereComponent_->AddImpulse(LocationForSlowDown, NAME_None, true);
		};
	}
}

void ADiscMachine::SetUltraSpeed(float Input)
{
	if (Input > 0 && Ultra_Speed_FuelValue_ > 0)
	{
		Ultra_Speed_Active_ = true;
		Ultra_Speed_Can_Recover_ = false;
	}
	else
	{
		Ultra_Speed_Active_ = false;
	}

	if (Input <= 0)
	{
		Ultra_Speed_Can_Recover_ = true;
	}
}

void ADiscMachine::ChangeDirection(float InputValue)
{
	float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	FRotator NewRotation{0, InputValue * DeltaTime * Direction_Speed_Rate_, 0};
	AddActorLocalRotation(NewRotation, true);
}

void ADiscMachine::ChangeDirectionToLeft(float InputValue)
{
	ChangeDirection(InputValue);
}

void ADiscMachine::ChangeDirectionToRight(float InputValue)
{
	ChangeDirection(-InputValue);
}

void ADiscMachine::ChangeBalance(float InputX)
{
	float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	FRotator NewRotation{0, 0, InputX * DeltaTime * Balance_Speed_Rate_};
	AddActorLocalRotation(NewRotation, true);
}

void ADiscMachine::ChangeUpDown(float InputY)
{
	if (UpDown_Inversion_)
	{
		InputY = -InputY;
	};
	float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	FRotator NewRotation{InputY * DeltaTime * UpDown_Speed_Rate_, 0, 0};
	AddActorLocalRotation(NewRotation, true);
}

void ADiscMachine::DecraseUltraSpeedFuelValue(float value)
{
	Ultra_Speed_FuelValue_ -= value;
	if (Ultra_Speed_FuelValue_ < 0)
	{
		Ultra_Speed_FuelValue_ = 0;
	};
}

void ADiscMachine::RecoverUltraSpeedFuelValue()
{
	if (Ultra_Speed_Can_Recover_)
	{
		Ultra_Speed_FuelValue_ += 10;
		if (Ultra_Speed_FuelValue_ >= MaxUltraSpeedFuelValue)
		{
			Ultra_Speed_FuelValue_ = MaxUltraSpeedFuelValue;
		};
	};
}

void ADiscMachine::FireFirstWeapon()
{
	FVector SpawnLocation = WeaponComponentSpawnPoint_->GetComponentLocation();
	FRotator SpawnRotation = WeaponComponentSpawnPoint_->GetComponentRotation();

	auto SpawnedBullet = GetWorld()->SpawnActor<ABullet>(BulletClassFirst, SpawnLocation, SpawnRotation);
	SpawnedBullet->SetOwner(this);

};

void ADiscMachine::FireSecondWeapon()
{
	FVector SpawnLocation = WeaponComponentSpawnPoint_->GetComponentLocation();
	FRotator SpawnRotation = WeaponComponentSpawnPoint_->GetComponentRotation();

	auto SpawnedBullet = GetWorld()->SpawnActor<ABullet>(BulletClassSecond, SpawnLocation, SpawnRotation);

	SpawnedBullet->SetOwner(this);
}