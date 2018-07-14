// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGrid.h"

#include "Saving/PainterSaveGame.h"

#include "Components/SizeBox.h"


bool UPaintingGrid::Initialize()
{
	if (!Super::Initialize()) return false;

	if (!AddButton) return false;
	AddButton->OnClicked.AddDynamic(this, &UPaintingGrid::CreatePainting);
	return true;
}

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
