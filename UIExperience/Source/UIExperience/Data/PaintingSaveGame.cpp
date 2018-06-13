// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingSaveGame.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "EngineUtils.h"

#include "PaintingListSaveGame.h"
#include "Stroke.h"

UPaintingSaveGame* UPaintingSaveGame::Create()
{
	auto SaveGame = Cast<UPaintingSaveGame>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
	auto Guid = FGuid::NewGuid();
	SaveGame->UniqueIdentifier = Guid.ToString();
	auto List = UPaintingListSaveGame::Load();
	List->AddPainting(SaveGame->UniqueIdentifier);
	List->Save();
	SaveGame->Save();
	return SaveGame;
}

UPaintingSaveGame* UPaintingSaveGame::Load(const FString& UniqueIdentifier)
{
	return Cast<UPaintingSaveGame>(UGameplayStatics::LoadGameFromSlot(UniqueIdentifier, 0));
}

bool UPaintingSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, UniqueIdentifier, 0);
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