// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingSaveGame.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "HAL/FileManager.h"
#include "Paths.h"

#include "PaintingSaveGameIndex.h"
#include "Canvas/Stroke.h"
#include "Canvas/SnapshotCamera.h"

UPaintingSaveGame* UPaintingSaveGame::Create()
{
	auto SaveGame = Cast<UPaintingSaveGame>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
	auto Guid = FGuid::NewGuid();
	SaveGame->UniqueIdentifier = Guid.ToString();
	AddToIndex(SaveGame->UniqueIdentifier);
	SaveGame->Save();
	return SaveGame;
}

UPaintingSaveGame* UPaintingSaveGame::Load(const FString& UniqueIdentifier)
{
	return Cast<UPaintingSaveGame>(UGameplayStatics::LoadGameFromSlot(UniqueIdentifier, 0));
}

bool UPaintingSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, UniqueIdentifier, 0);
}

void UPaintingSaveGame::Delete()
{
	// TODO: extract
	auto List = UPaintingSaveGameIndex::Load();
	List->RemovePainting(UniqueIdentifier);
	List->Save();

	UGameplayStatics::DeleteGameInSlot(UniqueIdentifier, 0);
	
	IFileManager::Get().Delete(*GetImagePath(UniqueIdentifier));
}

void UPaintingSaveGame::SnapshotLevel(UWorld* World)
{
	Strokes.Empty();
	for (TActorIterator<AStroke> Itr(World); Itr; ++Itr)
	{
		FStrokeData Stroke = Itr->GetData();
		Strokes.Add(Stroke);
	}

	// TODO: extract
	for (TActorIterator<ASnapshotCamera> SnapshotCamera(World); SnapshotCamera; ++SnapshotCamera)
	{
		FString ThumbnailDir = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("Thumbs"));
		IFileManager::Get().MakeDirectory(*ThumbnailDir, true);
		FString FileName = UniqueIdentifier + ".png";

		SnapshotCamera->CaptureScreenshot(ThumbnailDir, FileName);
		break; // Only snapshot the first camera in a scene.
	}
}

void UPaintingSaveGame::RestoreLevel(UWorld* World)
{
	for (FStrokeData Stroke : Strokes)
	{
		AStroke::CreateFromData(World, Stroke);
	}
}

void UPaintingSaveGame::AddToIndex(const FString& UUID)
{
	auto List = UPaintingSaveGameIndex::Load();
	List->AddPainting(UUID);
	List->Save();
}

FString UPaintingSaveGame::GetImagePath(const FString & UniqueIdentifier)
{
	FString ThumbnailDir = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("Thumbs"));
	FString FileName = UniqueIdentifier + ".png";

	return FPaths::Combine(ThumbnailDir, FileName);
}