// Fill out your copyright notice in the Description page of Project Settings.

#include "SaveGameList.h"

#include "Components/UniformGridSlot.h"

#include "Data/PaintingListSaveGame.h"
#include "SaveGameItem.h"

bool USaveGameList::Initialize()
{
	if (!Super::Initialize()) return false;

	ReloadSlots();
	return true;
}


void USaveGameList::ReloadSlots()
{
	ClearSlots();
	auto List = UPaintingListSaveGame::Load();
	auto Slots = GetSlots();
	auto Paintings = List->GetPaintings();
	int PaintingsOffset = CurrentPage * Slots.Num();
	for (auto Slot : Slots)
	{
		if (PaintingsOffset >= Paintings.Num()) break;
		auto Name = Paintings[PaintingsOffset];
		auto Widget = CreateWidget<USaveGameItem>(GetWorld(), SaveGameItemClass);
		if (!Widget) return;
		Widget->SetName(Name);
		Widget->SetParent(this);
		Slot->AddChild(Widget);
		++PaintingsOffset;
	}
}

void USaveGameList::ClearSlots()
{
	for (auto Slot : GetSlots())
	{
		Slot->ClearChildren();
	}
}

int32 USaveGameList::GetNumberOfPages() const
{
	auto List = UPaintingListSaveGame::Load();
	auto Paintings = List->GetPaintings();

	auto Slots = GetSlots();

	return FMath::CeilToInt((float)Paintings.Num() / Slots.Num());
}

TArray<UPanelWidget *> USaveGameList::GetSlots() const
{
	TArray<UPanelWidget *> Result;
	for (auto Slot : Grid->GetSlots())
	{
		auto SlotWidget = Cast<UPanelWidget>(Slot->Content);
		if (!SlotWidget) continue;
		Result.Add(SlotWidget);
	}
	return Result;
}