// Fill out your copyright notice in the Description page of Project Settings.

#include "LaserPainterGameInstance.h"

#include "Kismet/StereoLayerFunctionLibrary.h"

void ULaserPainterGameInstance::Init()
{
	UStereoLayerFunctionLibrary::SetSplashScreen(SplashScreen);
}
