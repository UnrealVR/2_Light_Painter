// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/TextBlock.h"
#include "SaveGameList.h"

#include "SaveGameItem.generated.h"

/**
 * 
 */
UCLASS()
class UIEXPERIENCE_API USaveGameItem : public UUserWidget
{
	GENERATED_BODY()
public:
	FString GetName() const;
	void SetName(const FString& Name);

	UFUNCTION(BlueprintCallable)
	void Clicked() { if (Parent) Parent->ClickedItem(GetName()); }

	void SetParent(USaveGameList* NewParent) { Parent = NewParent; }

private:

	USaveGameList* Parent;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Name;
	
};
