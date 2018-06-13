// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingSaveGame.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "Engine/GameViewportClient.h"
#include "Misc/FileHelper.h"
#include "ImageUtils.h"

#include "PaintingListSaveGame.h"
#include "Stroke.h"

UPaintingSaveGame* UPaintingSaveGame::Create()
{
	auto SaveGame = Cast<UPaintingSaveGame>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
	auto Guid = FGuid::NewGuid();
	SaveGame->UniqueIdentifier = Guid.ToString();
	auto List = UPaintingListSaveGame::Load();
	List->AddPainting(SaveGame->UniqueIdentifier);
	List->Save();
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
	auto List = UPaintingListSaveGame::Load();
	List->RemovePainting(UniqueIdentifier);
	List->Save();
	UGameplayStatics::DeleteGameInSlot(UniqueIdentifier, 0);
}

void UPaintingSaveGame::SnapshotLevel(UWorld* World)
{
	for (TActorIterator<AStroke> Itr(World); Itr; ++Itr)
	{
		FStrokeData Stroke = Itr->GetData();
		Strokes.Add(Stroke);
	}

	TArray<FColor> Pixels;
	
	if(World->GetGameViewport()->Viewport->ReadPixels(Pixels))
	{
		FVector2D ViewportSize;
		World->GetGameViewport()->GetViewportSize(ViewportSize);

		TArray<uint8> PNGData;
		FImageUtils::CompressImageArray(ViewportSize.X, ViewportSize.Y, Pixels, PNGData);

		FFileHelper::SaveArrayToFile(PNGData, TEXT("C:\\Users\\Samuel Pattuzzi\\Documents\\Courses\\Unreal VR\\section_2_proto\\UIExperience\\Saved\\test.png"));
	}
}

void UPaintingSaveGame::RestoreLevel(UWorld* World)
{
	for (FStrokeData Stroke : Strokes)
	{
		AStroke::CreateFromData(World, Stroke);
	}
}