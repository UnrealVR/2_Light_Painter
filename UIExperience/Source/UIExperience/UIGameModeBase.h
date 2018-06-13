// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UIGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UIEXPERIENCE_API AUIGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void InitGame(const FString & MapName, const FString & Options,	FString & ErrorMessage) override;

	void StartPlay() override;

	FString GetGameId() const { return SaveGameId; }

private:
	FString SaveGameId;
	
};
