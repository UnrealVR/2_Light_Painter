// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/Button.h"

#include "MainMenu.h"

#include "PaintingListSaveGameButtons.generated.h"

/**
 * 
 */
UCLASS()
class UIEXPERIENCE_API UPaintingListSaveGameButtons : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetParent(AMainMenu* NewParent) { Parent = NewParent; }

protected:
	bool Initialize() override;

private:

	AMainMenu* Parent;

	UFUNCTION()
	void CreateNewButtonClicked() { Parent->AddSlot(); };

	UFUNCTION()
	void DeleteButtonClicked() { Parent->BeginDelete(); };

	UPROPERTY(meta = (BindWidget))
	UButton* CreateNewButton;
		
	UPROPERTY(meta = (BindWidget))	
	UButton* DeleteButton;

	UPROPERTY(meta = (BindWidget))
	UButton* PrevPageButton;

	UPROPERTY(meta = (BindWidget))
	UButton* NextPageButton;

};
