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
	class UCapsuleComponent* CapsuleComponent_;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponentDisc_;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponentBall_;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponentCannon_;

	UPROPERTY(EditAnywhere, Category = "Movements")
	float Speed_ = 100.f;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Fly(float InputValue);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
