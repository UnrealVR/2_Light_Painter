// Fill out your copyright notice in the Description page of Project Settings.

#include "HandControllerBase.h"


AHandControllerBase::AHandControllerBase()
{
	PrimaryActorTick.bCanEverTick = true;

	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	SetRootComponent(MotionController);
	MotionController->SetShowDeviceModel(true);
	MotionController->SetTrackingSource(EControllerHand::Right);
}


