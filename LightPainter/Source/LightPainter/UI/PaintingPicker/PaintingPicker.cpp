// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingPicker.h"

#include "Saving/PainterSaveGameIndex.h"
#include "Saving/PainterSaveGame.h"

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

	RefreshSlots();
}

void APaintingPicker::RefreshSlots()
{
	UE_LOG(LogTemp, Warning, TEXT("Number of pages %d"), GetNumberOfPages());

	if (!GetPaintingGrid()) return;

	GetPaintingGrid()->AddPaginationDot(true);
	GetPaintingGrid()->AddPaginationDot(false);
	GetPaintingGrid()->AddPaginationDot(false);

	GetPaintingGrid()->ClearPaintings();

	int32 Index = 0;
	for (FString SlotName : UPainterSaveGameIndex::Load()->GetSlotNames())
	{
		GetPaintingGrid()->AddPainting(Index, SlotName);
		++Index;
	}
}

void APaintingPicker::AddPainting()
{
	UPainterSaveGame::Create();

	RefreshSlots();
}

void APaintingPicker::ToggleDeleteMode()
{
	if (!GetPaintingGrid()) return;

	GetPaintingGrid()->ClearPaintings();
}

int32 APaintingPicker::GetNumberOfPages() const
{
	if (!GetPaintingGrid()) return 0;

	int32 TotalNumberOfSlot = UPainterSaveGameIndex::Load()->GetSlotNames().Num();
	int32 SlotsPerPage = GetPaintingGrid()->GetNumberOfSlots();

	return FMath::CeilToInt((float) TotalNumberOfSlot / SlotsPerPage);
}