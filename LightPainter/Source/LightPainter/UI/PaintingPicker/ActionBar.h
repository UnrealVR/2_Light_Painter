// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/Button.h"

#include "ActionBar.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTPAINTER_API UActionBar : public UUserWidget
{
	GENERATED_BODY()

public:
int test;
	bool Initialize() override;
	
protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UButton* AddButton;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UButton* DeleteButton;

private:
	UFUNCTION()
	void AddButtonClicked() 
	{
		UE_LOG(LogTemp, Warning, TEXT("Add clicked."));
	}

	UFUNCTION()
	void DeleteButtonClicked()
	{
		UE_LOG(LogTemp, Warning, TEXT("Delete clicked."));
	}

};
