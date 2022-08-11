// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMachine.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

APlayerMachine::APlayerMachine()
{
    SpringArm_ = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm_->SetupAttachment(RootComponent);

    CameraComponent_ = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    CameraComponent_->SetupAttachment(SpringArm_);
}

void APlayerMachine::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("Accelerate", this, &APlayerMachine::Accelerate);
    PlayerInputComponent->BindAxis("UpDown", this, &APlayerMachine::ChangeUpDown);
    PlayerInputComponent->BindAxis("Balance", this, &APlayerMachine::ChangeBalance);
    PlayerInputComponent->BindAxis("Left", this, &APlayerMachine::ChangeDirectionToLeft);
    PlayerInputComponent->BindAxis("Right", this, &APlayerMachine::ChangeDirectionToRight);
    PlayerInputComponent->BindAxis("Ultra Speed", this, &APlayerMachine::SetUltraSpeed);
}
