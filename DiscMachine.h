// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DiscMachine.generated.h"

UCLASS()
class CRAZYDISC_API ADiscMachine : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADiscMachine();

protected:

	UPROPERTY(EditAnywhere)
	class USphereComponent* SphereComponent_;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponentDisc_;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponentBall_;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponentCannon_;

	UPROPERTY(EditAnywhere, Category = "Movements")
	float Acceleration_Speed_Rate_ = 500.f;

	UPROPERTY(EditAnywhere, Category = "Movements")
	float Direction_Speed_Rate_ = 100.f;

	UPROPERTY(EditAnywhere, Category = "Movements")
	float Balance_Speed_Rate_ = 100.f;

	UPROPERTY(EditAnywhere, Category = "Movements")
	float UpDown_Speed_Rate_ = 100.f;

	UPROPERTY(EditAnywhere, Category = "Movements")
	bool UpDown_Inversion_ = false;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Fly(float InputValue);
	void ChangeDirectionToLeft(float InputX);
	void ChangeDirectionToRight(float InputX);
	void ChangeDirection(float InputX);
	void ChangeBalance(float InputX);
	void ChangeUpDown(float InputY);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
