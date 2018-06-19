// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PainterGameMode.generated.h"

/**
 * Stores the current painting's ID.
 *
 * It get's this id in InitGame where it is launched. It is also responsible for loading the saved game.
 */
UCLASS()
class UIEXPERIENCE_API APainterGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void InitGame(const FString & MapName, const FString & Options,	FString & ErrorMessage) override;

	void StartPlay() override;

	FString GetGameId() const { return SaveGameId; }

private:
	FString SaveGameId;
	
};
