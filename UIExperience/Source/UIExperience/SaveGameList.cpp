// Fill out your copyright notice in the Description page of Project Settings.

#include "SaveGameList.h"

#include "Components/UniformGridSlot.h"

#include "PaintingListSaveGame.h"
#include "SaveGameItem.h"

bool USaveGameList::Initialize()
{
	if (!Super::Initialize()) return false;

	auto List = UPaintingListSaveGame::Load();
	uint32 i = 0;
	for (const FString& Name : List->GetPaintings())
	{
		UE_LOG(LogTemp, Warning, TEXT("Loading widget for %s"), *Name);
		auto Widget = CreateWidget<USaveGameItem>(GetWorld(), SaveGameItemClass);
		Widget->SetName(Name);
		auto Slot = Grid->AddChildToUniformGrid(Widget);
		Slot->SetRow((int)i / 3);
		Slot->SetColumn(i % 3);
		++i;
	}
	return true;
}


