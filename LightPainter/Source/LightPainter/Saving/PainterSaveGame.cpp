// Fill out your copyright notice in the Description page of Project Settings.

#include "PainterSaveGame.h"

#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

#include "Stroke.h"

UPainterSaveGame * UPainterSaveGame::Create()
{
	USaveGame* NewSaveGame = UGameplayStatics::CreateSaveGameObject(StaticClass());
	return Cast<UPainterSaveGame>(NewSaveGame);
}

bool UPainterSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, TEXT("Test"), 0);
}

UPainterSaveGame * UPainterSaveGame::Load()
{
	return Cast<UPainterSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("Test"), 0));
}

void UPainterSaveGame::SerializeFromWorld(UWorld * World)
{
	Strokes.Empty();
	for (TActorIterator<AStroke> StrokeItr(World); StrokeItr; ++StrokeItr)
	{
		//TODO:Serialize
		Strokes.Add(StrokeItr->GetClass());
	}
}

void UPainterSaveGame::DeserializeToWorld(UWorld * World)
{
	ClearWorld(World);
	for (TSubclassOf<AStroke> StrokeClass : Strokes)
	{
		World->SpawnActor<AStroke>(StrokeClass);
	}
}

void UPainterSaveGame::ClearWorld(UWorld * World)
{
	for (TActorIterator<AStroke> StrokeItr(World); StrokeItr; ++StrokeItr)
	{
		StrokeItr->Destroy();
	}
}
