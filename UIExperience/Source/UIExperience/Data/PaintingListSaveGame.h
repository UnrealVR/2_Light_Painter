// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PaintingListSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class UIEXPERIENCE_API UPaintingListSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	static UPaintingListSaveGame* Load();
	bool Save();

	TArray<FString> GetPaintings() const { return Paintings; }
	void AddPainting(const FString& Name) { Paintings.Add(Name); }
	void RemovePainting(const FString& Name) { Paintings.Remove(Name); }

private:
	UPROPERTY()
	TArray<FString> Paintings;
	
};
