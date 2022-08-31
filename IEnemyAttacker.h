#pragma once

#include "IEnemyAttacker.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UEnemyAttacker : public UInterface
{
    GENERATED_BODY()
};

class IEnemyAttacker
{    
    GENERATED_BODY()

public:
    virtual void ExecuteAttack() = 0;
    virtual float GetAttackInterval() = 0;
};