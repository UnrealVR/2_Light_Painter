// Fill out your copyright notice in the Description page of Project Settings.

#include "SaveGameList.h"

#include "Components/UniformGridSlot.h"

#include "Data/PaintingSaveGameIndex.h"
#include "SaveGameItem.h"


void USaveGameList::ReloadSlots()
{
	if (!Parent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't reload slots without a parent."));
		return;
	}

	ClearSlots();

	auto List = UPaintingSaveGameIndex::Load();
	auto Slots = GetSlots();
	auto Paintings = List->GetPaintings();
	int PaintingsOffset = Parent->GetCurrentPage() * Slots.Num();

	// TODO extract: PopulateSlots
	for (auto Slot : Slots)
	{
		if (PaintingsOffset >= Paintings.Num()) break;
		auto Name = Paintings[PaintingsOffset];
		AddWidgetToSlot(Slot, Name);
		++PaintingsOffset;
	}
}

void USaveGameList::AddWidgetToSlot(UPanelWidget * Slot, const FString & Name)
{
	auto Widget = CreateWidget<USaveGameItem>(GetWorld(), SaveGameItemClass);
	if (!Widget) return;
	Widget->SetName(Name);
	Widget->SetParent(this);
	Slot->AddChild(Widget);
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
	auto List = UPaintingSaveGameIndex::Load();
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