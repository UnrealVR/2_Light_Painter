// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingSaveGameIndex.h"

#include "Kismet/GameplayStatics.h"

const FString SAVE_NAME = TEXT("PaintingList");

UPaintingSaveGameIndex* UPaintingSaveGameIndex::Load()
{
	auto SaveGame = Cast<UPaintingSaveGameIndex>(UGameplayStatics::LoadGameFromSlot(SAVE_NAME, 0));
	if (!SaveGame)
	{
		SaveGame = Cast<UPaintingSaveGameIndex>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
	}
	return SaveGame;
}

bool UPaintingSaveGameIndex::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, SAVE_NAME, 0);
}


