// Fill out your copyright notice in the Description page of Project Settings.

#include "VRUIPawn.h"

#include "HeadMountedDisplayFunctionLibrary.h"

void AVRUIPawn::BeginPlay()
{
	Super::BeginPlay();
	UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::Eye);
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}