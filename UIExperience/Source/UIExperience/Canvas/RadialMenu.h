// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/Button.h"

#include "RadialMenu.generated.h"

/**
 * Menu that provides tools while drawing.
 */
UCLASS()
class UIEXPERIENCE_API URadialMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadonly, meta = (BindWidget))
	UButton* BrushButton;

	UPROPERTY(BlueprintReadonly, meta = (BindWidget))
	UButton* EraserButton;
	
	UPROPERTY(BlueprintReadonly, meta = (BindWidget))
	UButton* BackButton;


protected:
	bool Initialize() override;

private:

	void SaveAndQuit();
	
	UFUNCTION()
	void BrushButtonClicked();
	UFUNCTION()
	void EraserButtonClicked();
	UFUNCTION()
	void BackButtonClicked();

};
