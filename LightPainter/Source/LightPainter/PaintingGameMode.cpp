// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGameMode.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/StereoLayerFunctionLibrary.h"

#include "Saving/PainterSaveGame.h"

void APaintingGameMode::InitGame(const FString & MapName, const FString & Options, FString & ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	PaintingName = UGameplayStatics::ParseOption(Options, "PaintingName");
}

void APaintingGameMode::StartPlay()
{	
	Super::StartPlay();

	auto Painting = UPainterSaveGame::Load(PaintingName);
	Painting->DeserializeToWorld(GetWorld());

	UStereoLayerFunctionLibrary::HideSplashScreen();
}

void APaintingGameMode::SavePainting()
{
	UPainterSaveGame* Painting = UPainterSaveGame::Load(PaintingName);
	if (Painting)
	{
		Painting->SetState("Hello World!");
		Painting->SerializeFromWorld(GetWorld());
		Painting->Save();
	}
}



