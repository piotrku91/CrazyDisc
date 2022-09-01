
#include "ScouterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "ScouterMachine.h"
#include "MovingBody.h"

void AScouterAIController::BeginPlay()
{
    Super::BeginPlay();

    PlayerPawn_ = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    EnemyAttackerHandle_ = Cast<IEnemyAttacker>(GetPawn());
    EnemyPatrolHandle_ = Cast<IEnemyPatrol>(GetPawn());

    if (EnemyAttackerHandle_)
    {
        GetWorldTimerManager().SetTimer(ShootTimer_, this, &AScouterAIController::AttackIfNeccessary, EnemyAttackerHandle_->GetAttackInterval(), true);
    };
}

void AScouterAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (LineOfSightTo(PlayerPawn_) && InRange())
    {
        if (EnemyPatrolHandle_)
        {
            if (EnemyPatrolHandle_->GetMovingBodyComponent() && EnemyPatrolHandle_->GetMovingBodyComponent()->Move_component_active_)
            {
                EnemyPatrolHandle_->GetMovingBodyComponent()->Move_enabled_ = false;
            }
        };

        SetFocus(PlayerPawn_);
    }
    else
    {
        if (EnemyPatrolHandle_)
        {
            if (EnemyPatrolHandle_->GetMovingBodyComponent() && EnemyPatrolHandle_->GetMovingBodyComponent()->Move_component_active_)
            {
                EnemyPatrolHandle_->GetMovingBodyComponent()->Move_enabled_ = true;
            }
        };
        ClearFocus(EAIFocusPriority::Gameplay);
    }
}

void AScouterAIController::AttackIfNeccessary()
{
    if (InRange())
    {
        EnemyAttackerHandle_->ExecuteAttack();
    };
}

bool AScouterAIController::InRange()
{
    if (PlayerPawn_ && EnemyPatrolHandle_)
    {
        float Distance = FVector::Dist(GetPawn()->GetActorLocation(), PlayerPawn_->GetActorLocation());

        if (Distance <= EnemyPatrolHandle_->GetMinimumDistanceToDetection())
        {
            return true;
        }
    };
    return false;
}
