// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PaintingSaveGame.generated.h"

USTRUCT()
struct FStrokeDataPoint
{
	GENERATED_BODY()

	UPROPERTY()
	FVector LocalLocation;

	UPROPERTY()
	FVector LocalTangent;
};


USTRUCT()
struct FStrokeData
{
	GENERATED_BODY()

	UPROPERTY()
	TSubclassOf<class AStroke> TheClass;

	UPROPERTY()
	FTransform Transform;

	UPROPERTY()
	class UMaterialInterface* Material;

	UPROPERTY()
	TArray<FStrokeDataPoint> StrokePoints;
};

/**
 * Captures the strokes of a painting and persists them.
 */
UCLASS()
class UIEXPERIENCE_API UPaintingSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:

	FString GetUniqueIdentifier() const { return UniqueIdentifier; }

	static UPaintingSaveGame* Create();

	static UPaintingSaveGame * Load(const FString & UniqueIdentifier);

	static FString GetImagePath(const FString & UniqueIdentifier);

	bool Save();

	void Delete();

	void SnapshotLevel(UWorld * World);

	void RestoreLevel(UWorld * World);

private:
	UPROPERTY()
	FString UniqueIdentifier;

	UPROPERTY()
	TArray<FStrokeData> Strokes;
};
