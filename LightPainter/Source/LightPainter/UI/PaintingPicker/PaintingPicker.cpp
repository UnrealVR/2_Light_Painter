// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingPicker.h"

#include "Saving/PainterSaveGameIndex.h"
#include "Saving/PainterSaveGame.h"

#include "PaintingGrid.h"
#include "ActionBar.h"

// Sets default values
APaintingPicker::APaintingPicker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	PaintingGrid = CreateDefaultSubobject<UWidgetComponent>(TEXT("PaintingGrid"));
	PaintingGrid->SetupAttachment(GetRootComponent());

	ActionBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("ActionBar"));
	ActionBar->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void APaintingPicker::BeginPlay()
{
	Super::BeginPlay();

	UActionBar* ActionBarWidget = Cast<UActionBar>(ActionBar->GetUserWidgetObject());
	if (ActionBarWidget)
	{
		ActionBarWidget->SetParentPicker(this);
	}

	Refresh();
}

void APaintingPicker::RefreshSlots()
{
	if (!GetPaintingGrid()) return;

	GetPaintingGrid()->ClearPaintings();

	int32 StartOffset = CurrentPage * GetPaintingGrid()->GetNumberOfSlots();
	auto PaintingNames = UPainterSaveGameIndex::Load()->GetSlotNames();
	for (int32 i = 0; i < GetPaintingGrid()->GetNumberOfSlots() && i + StartOffset < PaintingNames.Num(); ++i)
	{
		FString PaintingName = PaintingNames[StartOffset + i];
		GetPaintingGrid()->AddPainting(i, PaintingName);
	}
}

void APaintingPicker::RefreshPagination()
{
	if (!GetPaintingGrid()) return;

	GetPaintingGrid()->ClearPaginationDots();

	for (int i = 0; i < GetNumberOfPages(); ++i)
	{
		GetPaintingGrid()->AddPaginationDot(CurrentPage == i);
	}
}

int APaintingPicker::GetNumberOfPages() const
{
	if (!GetPaintingGrid()) return 0;

	int NumberOfPaintings = UPainterSaveGameIndex::Load()->GetSlotNames().Num();

	return FMath::CeilToInt((float) NumberOfPaintings / GetPaintingGrid()->GetNumberOfSlots());
}

void APaintingPicker::AddPainting()
{
	UPainterSaveGame::Create();

	Refresh();
}

void APaintingPicker::ToggleDeleteMode()
{
	UPaintingGrid* PaintingGridWidget = Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject());
	if (!PaintingGridWidget) return;
		
	PaintingGridWidget->ClearPaintings();
}

UPaintingGrid * APaintingPicker::GetPaintingGrid() const
{
	return Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject());
}

void APaintingPicker::Paginate(int Offset)
{
	CurrentPage = FMath::Clamp(CurrentPage + Offset, 0, GetNumberOfPages() - 1);

	UE_LOG(LogTemp, Warning, TEXT("CurrentPage: %d"), CurrentPage);

	Refresh();
}