// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class CRAZYDISC_API ABullet : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent *MeshComponentBullet_;

	UPROPERTY(EditAnywhere)
	class UProjectileMovementComponent *MovementComponentBullet_;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
