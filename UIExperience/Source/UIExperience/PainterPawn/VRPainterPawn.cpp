// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPainterPawn.h"

#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/StereoLayerFunctionLibrary.h"

#include "Data/PaintingSaveGame.h"
#include "EngineUtils.h"
#include "UIGameModeBase.h"


// Called when the game starts or when spawned
void AVRPainterPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void AVRPainterPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Save", EInputEvent::IE_Released, this, &AVRPainterPawn::SaveAndQuit);
	PlayerInputComponent->BindAction("Load", EInputEvent::IE_Released, this, &AVRPainterPawn::Load);
}

void AVRPainterPawn::SaveAndQuit()
{
	
	auto GameMode = Cast<AUIGameModeBase>(GetWorld()->GetAuthGameMode());
	UPaintingSaveGame* SaveGame;
	if (GameMode)
	{
		SaveGame = UPaintingSaveGame::Load(GameMode->GetGameId());
	}
	else
	{
		SaveGame = UPaintingSaveGame::Create();
	}
	UniquePaintingIdentifier = SaveGame->GetUniqueIdentifier();
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

void AVRPainterPawn::Load()
{
	auto SaveGame = UPaintingSaveGame::Load(UniquePaintingIdentifier);
	if (SaveGame)
	{
		for (TActorIterator<AStroke> Itr(GetWorld()); Itr; ++Itr)
		{
			Itr->Destroy();
		}

		SaveGame->RestoreLevel(GetWorld());
		UE_LOG(LogTemp, Warning, TEXT("Restored Level"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not restore level"));
	}
}