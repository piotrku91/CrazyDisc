// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DiscMachine.generated.h"

constexpr float MaxUltraSpeedFuelValue = 1000;

UCLASS()
class CRAZYDISC_API ADiscMachine : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADiscMachine();

	virtual void Die();

protected:

	UPROPERTY(EditAnywhere)
	class USphereComponent* SphereComponent_;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponentDisc_;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponentBall_;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponentCannon_;

	UPROPERTY(EditAnywhere)
	USceneComponent* WeaponComponentSpawnPoint_;

	UPROPERTY(EditAnywhere, Category = "Movements")
	float Acceleration_Speed_Rate_ = 500.f;

	UPROPERTY(EditAnywhere, Category = "Movements")
	float Ultra_Speed_Amount_ = 2500.f;

	UPROPERTY(EditAnywhere, Category = "Movements")
	float Ultra_Speed_Recover_Time_ = 0.2f;

	UPROPERTY(EditAnywhere, Category = "Movements")
	bool Ultra_Speed_Allowed_ = true;

	UPROPERTY(EditAnywhere, Category = "Movements")
	float Direction_Speed_Rate_ = 100.f;

	UPROPERTY(EditAnywhere, Category = "Movements")
	float Balance_Speed_Rate_ = 100.f;

	UPROPERTY(EditAnywhere, Category = "Movements")
	float UpDown_Speed_Rate_ = 100.f;

	UPROPERTY(EditAnywhere, Category = "Movements")
	bool UpDown_Inversion_ = false;

	UPROPERTY(EditAnywhere, Category = "Movements")
	bool Slow_Down_Active_ = false;

	UPROPERTY(EditAnywhere, Category = "Movements")
	float Slow_Down_time_ = 5.f;

	UPROPERTY(EditAnywhere, Category = "Weapons")
	TSubclassOf<class ABullet> BulletClassFirst;

	UPROPERTY(EditAnywhere, Category = "Weapons")
	TSubclassOf<class ABullet> BulletClassSecond;

	virtual void FireFirstWeapon();
	virtual void FireSecondWeapon();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Accelerate(float InputValue);
	void ChangeDirectionToLeft(float InputX);
	void ChangeDirectionToRight(float InputX);
	void ChangeDirection(float InputX);
	void ChangeBalance(float InputX);
	void ChangeUpDown(float InputY);
	void SetUltraSpeed(float Input);

	private:
	class ACrazyDiscGameMode* GameMode_;

	FTimerHandle UltraSpeedFuelValueRecoverTimer;
	bool Ultra_Speed_Active_ = false;
	bool Ultra_Speed_Can_Recover_ = false;
	float Ultra_Speed_FuelValue_ = MaxUltraSpeedFuelValue;
	float Last_Slow_Down_TimeStamp = 0;

	void DecraseUltraSpeedFuelValue(float value);
	void RecoverUltraSpeedFuelValue();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
