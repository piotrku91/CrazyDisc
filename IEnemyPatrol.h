#pragma once

#include "IEnemyPatrol.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UEnemyPatrol : public UInterface
{
    GENERATED_BODY()
};

class IEnemyPatrol
{    
    GENERATED_BODY()

public:
    virtual class UMovingBody* GetMovingBodyComponent() = 0;
    virtual float GetMinimumDistanceToDetection() = 0;
};