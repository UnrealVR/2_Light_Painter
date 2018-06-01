// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPainterPawn.h"

#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "PaintingSaveGame.h"
#include "EngineUtils.h"


// Called when the game starts or when spawned
void AVRPainterPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void AVRPainterPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Save", EInputEvent::IE_Released, this, &AVRPainterPawn::Save);
	PlayerInputComponent->BindAction("Load", EInputEvent::IE_Released, this, &AVRPainterPawn::Load);
}

void AVRPainterPawn::Save()
{
	auto SaveGame = UPaintingSaveGame::Load(UniquePaintingIdentifier);
	if (!SaveGame)
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