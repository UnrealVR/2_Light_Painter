// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"

#include "SaveGameList.h"
#include "SaveGameButtons.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/StereoLayerFunctionLibrary.h"
#include "Data/PaintingSaveGame.h"

// Sets default values
AMainMenu::AMainMenu()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Menu = CreateDefaultSubobject<UWidgetComponent>(TEXT("Menu"));
	Menu->SetupAttachment(Root);

	MenuButtons = CreateDefaultSubobject<UWidgetComponent>(TEXT("MenuButtons"));
	MenuButtons->SetupAttachment(Root);
}

void AMainMenu::BeginPlay()
{
	Super::BeginPlay();
	
	if (auto List = GetSaveGameList())
	{
		List->SetParent(this);
		List->ReloadSlots();
	}

	if (auto Buttons = GetSaveGameListButtons())
	{
		Buttons->SetParent(this);
	}
}

void AMainMenu::AddSlot()
{
	auto NewSlot = UPaintingSaveGame::Create();
	NewSlot->Save();

	if (auto List = GetSaveGameList())
	{
		List->ReloadSlots();
	}
}

void AMainMenu::ClickedItem(FString ItemID)
{
	if (DeleteMode)
	{
		DeleteItem(ItemID);
	}
	else
	{
		OpenLevel(ItemID);
	}
}

void AMainMenu::ToggleDeleteMode()
{
	DeleteMode = !DeleteMode;
}

bool AMainMenu::HasNextPage() const { return GetSaveGameList() && CurrentPage + 1 < GetSaveGameList()->GetNumberOfPages(); }
bool AMainMenu::HasPrevPage() const { return CurrentPage > 0; }

void AMainMenu::NextPage() 
{ 
	if (HasNextPage())
	{
		++CurrentPage;
		if (GetSaveGameList()) GetSaveGameList()->ReloadSlots();
	}
}

void AMainMenu::PrevPage() 
{ 
	if (HasPrevPage()) 
	{
		--CurrentPage;
		if (GetSaveGameList()) GetSaveGameList()->ReloadSlots();
	}
}

void AMainMenu::OpenLevel(FString ItemID)
{
	UStereoLayerFunctionLibrary::ShowSplashScreen();

	UGameplayStatics::OpenLevel(GetWorld(), "Canvas", true, "SaveGame=" + ItemID);
}

void AMainMenu::DeleteItem(FString ItemID)
{
	auto Slot = UPaintingSaveGame::Load(ItemID);
	Slot->Delete();

	if (auto List = GetSaveGameList())
	{
		List->ReloadSlots();
	}
}

USaveGameList * AMainMenu::GetSaveGameList() const
{
	return Cast<USaveGameList>(Menu->GetUserWidgetObject());
}

USaveGameButtons * AMainMenu::GetSaveGameListButtons() const
{
	return Cast<USaveGameButtons>(MenuButtons->GetUserWidgetObject());
}
