// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/Button.h"

#include "PaintingListSaveGame.h"

#include "PaintingListSaveGameButtons.generated.h"

/**
 * 
 */
UCLASS()
class UIEXPERIENCE_API UPaintingListSaveGameButtons : public UUserWidget
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere)
	UPaintingListSaveGame* SaveGameList;

	UPROPERTY(meta = (BindWidget))
	UButton* CreateNewButton;
		
	UPROPERTY(meta = (BindWidget))	
	UButton* DeleteButton;

	UPROPERTY(meta = (BindWidget))
	UButton* PrevPageButton;

	UPROPERTY(meta = (BindWidget))
	UButton* NextPageButton;

};
