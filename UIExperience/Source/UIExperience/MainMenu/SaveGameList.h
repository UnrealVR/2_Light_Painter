// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/UniformGridPanel.h"
#include "MainMenu.h"

#include "SaveGameList.generated.h"

/**
 * 
 */
UCLASS()
class UIEXPERIENCE_API USaveGameList : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void ReloadSlots();
	void ClickedItem(FString ItemID) { if (Parent) Parent->ClickedItem(ItemID); }

	void SetParent(AMainMenu* NewParent) { Parent = NewParent; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsDeleteMode() const { return Parent->IsDeleteMode(); };

protected:
	bool Initialize() override;

private:
	
	void ClearSlots();
	TArray<UPanelWidget *> GetSlots() const;

	// References
	AMainMenu * Parent;
	
	UPROPERTY(meta = (BindWidget))
	UUniformGridPanel* Grid;

	// Config
	UPROPERTY(EditAnywhere)
	TSubclassOf<class USaveGameItem> SaveGameItemClass;

	UPROPERTY(EditAnywhere)
	int NumberOfRows = 3;
	UPROPERTY(EditAnywhere)
	int NumberOfColumns = 3;

	// State
	int CurrentPage = 0;
};
