// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingListSaveGame.h"

#include "Kismet/GameplayStatics.h"

const FString SAVE_NAME = TEXT("PaintingList");

UPaintingListSaveGame* UPaintingListSaveGame::Load()
{
	auto SaveGame = Cast<UPaintingListSaveGame>(UGameplayStatics::LoadGameFromSlot(SAVE_NAME, 0));
	if (!SaveGame)
	{
		SaveGame = Cast<UPaintingListSaveGame>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
	}
	return SaveGame;
}

bool UPaintingListSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, SAVE_NAME, 0);
}


