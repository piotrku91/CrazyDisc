// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"
#include "CrazyDiscGameMode.h"
#include "Kismet/GameplayStatics.h"
//////////////////////////////////////////////////////////////////////////////////////////
// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}
//////////////////////////////////////////////////////////////////////////////////////////
// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth_ = MaximumHealth_;
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageHandle);

	GameMode_ = Cast<ACrazyDiscGameMode>(UGameplayStatics::GetGameMode(this));
}
//////////////////////////////////////////////////////////////////////////////////////////
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
//////////////////////////////////////////////////////////////////////////////////////////
void UHealthComponent::DamageHandle(AActor *DamagedActor, float Damage, const UDamageType *DamageType, class AController *Instigator, AActor *DamageCauser)
{
	if (Damage <= 0)
	{
		return;
	};

	CurrentHealth_ -= Damage;

	GameMode_->UpdateHealthIfItIsAPlayer(DamagedActor, CurrentHealth_);

	if (CurrentHealth_ <= 0 && GameMode_) {
		GameMode_->SomeActorDied(DamagedActor);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////