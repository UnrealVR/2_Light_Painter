// Fill out your copyright notice in the Description page of Project Settings.

#include "UIGameModeBase.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/StereoLayerFunctionLibrary.h"

#include "Data/PaintingSaveGame.h"

void AUIGameModeBase::InitGame(const FString & MapName, const FString & Options, FString & ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	SaveGameId = UGameplayStatics::ParseOption(Options, "SaveGame");
}

void AUIGameModeBase::StartPlay()
{
	Super::StartPlay();
	if (SaveGameId == "") return;

	auto Save = UPaintingSaveGame::Load(SaveGameId);
	if (Save)
	{
		Save->RestoreLevel(GetWorld());
	}

	UStereoLayerFunctionLibrary::HideSplashScreen();
}
