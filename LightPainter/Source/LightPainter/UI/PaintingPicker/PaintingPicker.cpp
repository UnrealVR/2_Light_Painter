// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingPicker.h"

#include "PaintingGrid.h"

#include "Saving/PainterListSaveGame.h"


// Sets default values
APaintingPicker::APaintingPicker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	PaintingGrid = CreateDefaultSubobject<UWidgetComponent>(TEXT("PaintingGrid"));
	PaintingGrid->SetupAttachment(Root);

	ActionBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("ActionBar"));
	ActionBar->SetupAttachment(Root);
}

void APaintingPicker::BeginPlay()
{
	Super::BeginPlay();

	ReloadPaintings();
}

void APaintingPicker::ReloadPaintings()
{
	UPaintingGrid* Grid = Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject());
	if (!Grid) return;
	
	int32 Index = 0;
	for (FString PaintingName : UPainterListSaveGame::Load()->GetPaintings())
	{
		Grid->AddPainting(Index, PaintingName);
		++Index;
	}
}

