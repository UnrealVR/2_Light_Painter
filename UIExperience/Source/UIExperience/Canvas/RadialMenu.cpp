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
		Itr->SetState(EBrushMode::Painting);
	}
}

void URadialMenu::EraserButtonClicked()
{	
	for (TActorIterator<APaintBrushHandController> Itr(GetWorld()); Itr; ++Itr)
	{
		Itr->SetState(EBrushMode::Erasing);
	}
}

void URadialMenu::BackButtonClicked()
{
	SaveAndQuit();
}

void URadialMenu::SaveAndQuit()
{
	// TODO extract: GetSaveGame
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
	//

	SaveGame->SnapshotLevel(GetWorld());
	bool bDidSave = SaveGame->Save();
	if (bDidSave)
	{
		UStereoLayerFunctionLibrary::ShowSplashScreen();

		UGameplayStatics::OpenLevel(GetWorld(), "/Game/Maps/Menu");
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Did not save"));
	}
}


