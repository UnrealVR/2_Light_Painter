// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/UniformGridPanel.h"
#include "PaintingGridCard.h"
#include "PaintingPicker.h"

#include "PaintingGrid.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTPAINTER_API UPaintingGrid : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetPaintingPicker(APaintingPicker* NewPaintingPicker) { PaintingPicker = NewPaintingPicker; }
	
	UFUNCTION(BlueprintCallable)
	void AddPainting(int32 Index, FString PaintingName);

	bool Initialize() override;
	
protected:
	// Components
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta=(BindWidget))
	UUniformGridPanel* PaintingGrid;

	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
	UButton* AddButton;

private:
	UFUNCTION()
	void CreatePainting() { if (PaintingPicker) PaintingPicker->CreatePainting(); }

	// Config
	UPROPERTY(EditAnywhere)
	TSubclassOf<UPaintingGridCard> GridCardClass;

	// References
	APaintingPicker* PaintingPicker;
	
};
