// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/WidgetComponent.h"


#include "MainMenu.generated.h"

/**
 * The root actor for the main menu.
 *
 * This class handles the routing of UI messages between the various widget
 * elements. State of the UI should be stored here.
 */
UCLASS()
class UIEXPERIENCE_API AMainMenu : public AActor
{
	GENERATED_BODY()
	
public:	
	AMainMenu();

	void AddSlot();
	void ClickedItem(FString ItemID);
	void ToggleDeleteMode();
	bool IsDeleteMode() const { return DeleteMode; }
	bool HasNextPage() const;
	bool HasPrevPage() const;
	void NextPage();
	void PrevPage();
	int32 GetCurrentPage() const { return CurrentPage; }

protected:
	virtual void BeginPlay() override;

private:

	void OpenLevel(FString ItemID);
	void DeleteItem(FString ItemID);

	class USaveGameList* GetSaveGameList() const;
	class USaveGameButtons* GetSaveGameListButtons() const;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* Menu;

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* MenuButtons;

	// State
	bool DeleteMode = false;
	int CurrentPage = 0;

};
