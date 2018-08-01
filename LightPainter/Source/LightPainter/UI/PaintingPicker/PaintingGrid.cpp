// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGrid.h"

#include "Components/SizeBox.h"
#include "HorizontalBoxSlot.h"

void UPaintingGrid::AddPainting(int32 PaintingIndex, FString PaintingName)
{
	if (!PaintingGrid) return;
	UPaintingGridCard* NewWidget = CreateWidget<UPaintingGridCard>(GetWorld(), GridCardClass);
	if (!NewWidget) return;

	NewWidget->SetPaintingName(PaintingName);

	USizeBox* CardContainer = Cast<USizeBox>(PaintingGrid->GetChildAt(PaintingIndex));
	if (!CardContainer) return;

	CardContainer->AddChild(NewWidget);
}

void UPaintingGrid::ClearPaintings()
{
	for (int32 i = 0; i < PaintingGrid->GetChildrenCount(); ++i)
	{
		USizeBox* CardContainer = Cast<USizeBox>(PaintingGrid->GetChildAt(i));
		if (!CardContainer) continue;

		CardContainer->ClearChildren();
	}
}

void UPaintingGrid::ClearPaginationDots()
{
	if (!PaginationDots) return;

	PaginationDots->ClearChildren();	
}

void UPaintingGrid::AddPaginationDot(bool Active)
{
	if (!PaginationDots) return;

	UPaginationDot* Dot = CreateWidget<UPaginationDot>(GetWorld(), PaginationDotClass);
	if (!Dot) return;
	Dot->SetActive(Active);

	UHorizontalBoxSlot* Slot = PaginationDots->AddChildToHorizontalBox(Dot);
	if (!Slot) return;

	Slot->SetPadding(FMargin(PaginationDotPadding, 0));
}