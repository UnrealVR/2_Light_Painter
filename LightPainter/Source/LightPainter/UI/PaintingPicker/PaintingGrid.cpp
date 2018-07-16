// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGrid.h"

#include "Components/SizeBox.h"


void UPaintingGrid::AddPainting(int32 Index, FString PaintingName)
{
	USizeBox* GridCell = Cast<USizeBox>(PaintingGrid->GetChildAt(Index));
	if (!GridCell) return;
	UPaintingGridCard* GridCard = CreateWidget<UPaintingGridCard>(GetWorld(), GridCardClass);
	if (!GridCard)
	{
		UE_LOG(LogTemp, Error, TEXT("Must provide a GridCard class to spawn."));
		return;
	}
	GridCard->SetPaintingName(PaintingName);
	GridCell->AddChild(GridCard);
}

void UPaintingGrid::ClearPaintings()
{
	int32 Count = PaintingGrid->GetChildrenCount();
	for (int32 i = 0; i < Count; ++i)
	{
		USizeBox* GridCell = Cast<USizeBox>(PaintingGrid->GetChildAt(i));
		if (!GridCell) continue;
		GridCell->ClearChildren();
	}
}