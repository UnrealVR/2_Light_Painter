// Fill out your copyright notice in the Description page of Project Settings.

#include "RadialMenu.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/StereoLayerFunctionLibrary.h"
#include "EngineUtils.h"

#include "PainterGameMode.h"
#include "Data/PaintingSaveGame.h"
#include "PainterPawn/PaintBrushHandController.h"

bool URadialMenu::Initialize()
{
	if (!Super::Initialize()) return false;
	if (BrushButton) BrushButton->OnClicked.AddDynamic(this, &URadialMenu::BrushButtonClicked);
	if (EraserButton) EraserButton->OnClicked.AddDynamic(this, &URadialMenu::EraserButtonClicked);
	if (BackButton) BackButton->OnClicked.AddDynamic(this, &URadialMenu::BackButtonClicked);
	return true;
}

void URadialMenu::BrushButtonClicked()
{
	for (TActorIterator<APaintBrushHandController> Itr(GetWorld()); Itr; ++Itr)
	{
		Itr->SetState(EBrushState::Painting);
	}
}

void URadialMenu::EraserButtonClicked()
{	
	for (TActorIterator<APaintBrushHandController> Itr(GetWorld()); Itr; ++Itr)
	{
		Itr->SetState(EBrushState::Erasing);
	}
}

void URadialMenu::BackButtonClicked()
{
	SaveAndQuit();
}

void URadialMenu::SaveAndQuit()
{

	auto GameMode = Cast<APainterGameMode>(GetWorld()->GetAuthGameMode());
	UPaintingSaveGame* SaveGame;
	if (GameMode)
	{
		SaveGame = UPaintingSaveGame::Load(GameMode->GetGameId());
	}
	else
	{
		SaveGame = UPaintingSaveGame::Create();
	}
	auto UniquePaintingIdentifier = SaveGame->GetUniqueIdentifier();
	UE_LOG(LogTemp, Warning, TEXT("UUID: %s"), *SaveGame->GetUniqueIdentifier());
	SaveGame->SnapshotLevel(GetWorld());
	bool bDidSave = SaveGame->Save();
	if (bDidSave)
	{
		UE_LOG(LogTemp, Warning, TEXT("Did Save"))
			UStereoLayerFunctionLibrary::ShowSplashScreen();

		UGameplayStatics::OpenLevel(GetWorld(), "LoadMenu");
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Did not save"));
	}
}


