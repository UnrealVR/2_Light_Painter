// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PaintingSaveGame.generated.h"

USTRUCT()
struct FStrokeDataPoints
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
	TArray<FStrokeDataPoints> StrokePoints;
};

/**
 * 
 */
UCLASS()
class UIEXPERIENCE_API UPaintingSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:

	static UPaintingSaveGame* Create();

	static UPaintingSaveGame* Load();

	bool Save();

	void SnapshotLevel(UWorld * World);

	void RestoreLevel(UWorld * World);

private:
	UPROPERTY()
	TArray<FStrokeData> Strokes;
};
