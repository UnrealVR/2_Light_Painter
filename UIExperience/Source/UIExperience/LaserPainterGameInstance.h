// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LaserPainterGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UIEXPERIENCE_API ULaserPainterGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	void SetSaveGameToLoad(const FString & InSaveGameToLoad) { SaveGameToLoad = InSaveGameToLoad; }
	FString GetSaveGameToLoad() { return SaveGameToLoad; }

private:

	FString SaveGameToLoad;
	
};
