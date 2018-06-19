// Fill out your copyright notice in the Description page of Project Settings.

#include "PainterGameMode.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/StereoLayerFunctionLibrary.h"

#include "Data/PaintingSaveGame.h"

void APainterGameMode::InitGame(const FString & MapName, const FString & Options, FString & ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	SaveGameId = UGameplayStatics::ParseOption(Options, "SaveGame");
}

void APainterGameMode::StartPlay()
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
