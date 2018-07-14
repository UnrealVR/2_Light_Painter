// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGrid.h"

#include "Components/SizeBox.h"


void UPaintingGrid::AddPainting(int32 Index, FString PaintingName)
{
	USizeBox* GridCell = Cast<USizeBox>(PaintingGrid->GetChildAt(Index));
	if (!GridCell) return;
	UUserWidget* GridCard = CreateWidget<UUserWidget>(GetWorld(), GridCardClass);
	GridCell->AddChild(GridCard);
}
