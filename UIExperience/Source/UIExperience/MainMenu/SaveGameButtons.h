// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/Button.h"

#include "MainMenu.h"

#include "SaveGameButtons.generated.h"

/**
 * 
 */
UCLASS()
class UIEXPERIENCE_API USaveGameButtons : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetParent(AMainMenu* NewParent) { Parent = NewParent; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsDeleteMode() const { return Parent->IsDeleteMode(); };

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasNextPage() const { return Parent && Parent->HasNextPage(); }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasPrevPage() const { return Parent && Parent->HasPrevPage(); }

	UPROPERTY(BlueprintReadonly, meta = (BindWidget))
	UButton* CreateNewButton;

	UPROPERTY(BlueprintReadonly, meta = (BindWidget))
	UButton* DeleteButton;

	UPROPERTY(BlueprintReadonly, meta = (BindWidget))
	UButton* PrevPageButton;

	UPROPERTY(BlueprintReadonly, meta = (BindWidget))
	UButton* NextPageButton;

protected:
	bool Initialize() override;

private:

	AMainMenu* Parent;

	UFUNCTION()
	void CreateNewButtonClicked() { Parent->AddSlot(); };

	UFUNCTION()
	void DeleteButtonClicked() { Parent->ToggleDeleteMode(); };

	UFUNCTION()
	void NextPage() { if (Parent) Parent->NextPage(); }

	UFUNCTION()
	void PrevPage() { if (Parent) Parent->PrevPage(); }

};
