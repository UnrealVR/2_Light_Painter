// Fill out your copyright notice in the Description page of Project Settings.

#include "PainterSaveGame.h"

#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

#include "PainterListSaveGame.h"

#include "Stroke.h"

UPainterSaveGame * UPainterSaveGame::Create()
{
	UPainterSaveGame* NewSaveGame = Cast<UPainterSaveGame>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
	NewSaveGame->SlotName = FGuid::NewGuid().ToString();
	auto Index = UPainterListSaveGame::Load();
	Index->AddPainting(NewSaveGame);
	Index->Save();
	NewSaveGame->Save(); // Because don't want it to disappear now.
	return NewSaveGame;
}

bool UPainterSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, SlotName, 0);
}

UPainterSaveGame * UPainterSaveGame::Load(FString SlotName)
{
	UE_LOG(LogTemp, Warning, TEXT("Painting Index:"));
	for (auto PaintingName : UPainterListSaveGame::Load()->GetPaintings())
	{
		UE_LOG(LogTemp, Warning, TEXT("Painting: %s"), *PaintingName);
	}
	return Cast<UPainterSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
}

void UPainterSaveGame::SerializeFromWorld(UWorld * World)
{
	Strokes.Empty();
	for (TActorIterator<AStroke> StrokeItr(World); StrokeItr; ++StrokeItr)
	{
		Strokes.Add(StrokeItr->SerializeToStruct());
	}
}

void UPainterSaveGame::DeserializeToWorld(UWorld * World)
{
	ClearWorld(World);
	for (FStrokeState StrokeState : Strokes)
	{
		AStroke::SpawnAndDeserializeFromStruct(World, StrokeState);
	}
}

void UPainterSaveGame::ClearWorld(UWorld * World)
{
	for (TActorIterator<AStroke> StrokeItr(World); StrokeItr; ++StrokeItr)
	{
		StrokeItr->Destroy();
	}
}
