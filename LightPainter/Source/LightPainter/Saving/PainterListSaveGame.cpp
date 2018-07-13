// Fill out your copyright notice in the Description page of Project Settings.

#include "PainterListSaveGame.h"

#include "Kismet/GameplayStatics.h"

#include "PainterSaveGame.h"

const FString UPainterListSaveGame::SLOT_NAME = "PaintingIndex";

UPainterListSaveGame* UPainterListSaveGame::Load()
{
	auto PainterList = Cast<UPainterListSaveGame>(UGameplayStatics::LoadGameFromSlot(SLOT_NAME, 0));
	if (!PainterList)
	{
		PainterList = Cast<UPainterListSaveGame>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
	}
	return PainterList;
}

bool UPainterListSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, SLOT_NAME, 0);
}

void UPainterListSaveGame::AddPainting(UPainterSaveGame * PainterSaveGame)
{
	PainterSaveGameSlotNames.Add(PainterSaveGame->GetSlotName());
}


