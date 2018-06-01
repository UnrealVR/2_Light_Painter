// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingSaveGame.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "EngineUtils.h"

#include "Stroke.h"

UPaintingSaveGame* UPaintingSaveGame::Create()
{
	return Cast<UPaintingSaveGame>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
}

UPaintingSaveGame* UPaintingSaveGame::Load()
{
	return Cast<UPaintingSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("Slot"), 0));
}

bool UPaintingSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, TEXT("Slot"), 0);
}

void UPaintingSaveGame::SnapshotLevel(UWorld* World)
{
	for (TActorIterator<AStroke> Itr(World); Itr; ++Itr)
	{
		FStrokeData Stroke = Itr->GetData();
		Strokes.Add(Stroke);
	}
}

void UPaintingSaveGame::RestoreLevel(UWorld* World)
{
	for (FStrokeData Stroke : Strokes)
	{
		AStroke::CreateFromData(World, Stroke);
	}
}