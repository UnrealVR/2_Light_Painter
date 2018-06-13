// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"

#include "SaveGameList.h"
#include "PaintingListSaveGameButtons.h"

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

// Called when the game starts or when spawned
void AMainMenu::BeginPlay()
{
	Super::BeginPlay();
	
	if (auto Buttons = GetSaveGameListButtons())
	{
		Buttons->SetParent(this);
	}
}

// Called every frame
void AMainMenu::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainMenu::AddSlot()
{
	UE_LOG(LogTemp, Warning, TEXT("Button callback called"));
}

USaveGameList * AMainMenu::GetSaveGameList() const
{
	return Cast<USaveGameList>(Menu->GetUserWidgetObject());
}

UPaintingListSaveGameButtons * AMainMenu::GetSaveGameListButtons() const
{
	return Cast<UPaintingListSaveGameButtons>(MenuButtons->GetUserWidgetObject());
}
