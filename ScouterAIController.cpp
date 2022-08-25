
#include "ScouterAIController.h"
#include "Kismet/GameplayStatics.h"

void AScouterAIController::BeginPlay()
{
    Super::BeginPlay();

    APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (PlayerPawn)
	{
		SetFocus(PlayerPawn);
	};

    
}