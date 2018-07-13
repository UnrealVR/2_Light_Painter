// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PainterListSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTPAINTER_API UPainterListSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	static UPainterListSaveGame* Load();
	bool Save();
	void AddPainting(class UPainterSaveGame* PainterSaveGame);
	TArray<FString> GetPaintings() const { return PainterSaveGameSlotNames; }

private:
	static const FString SLOT_NAME;

	// State
	UPROPERTY()
	TArray<FString> PainterSaveGameSlotNames;

};
