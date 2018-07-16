// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGrid.h"

void UPaintingGrid::AddPainting()
{
	if (PaintingGrid)
	{
		UE_LOG(LogTemp, Warning, TEXT("Grid Name: %s"), *PaintingGrid->GetName());
	}
}


