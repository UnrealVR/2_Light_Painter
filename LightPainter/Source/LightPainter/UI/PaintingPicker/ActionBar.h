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
	bool Initialize() override;

protected:
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
	UButton* AddButton;
	
private:
	UFUNCTION()
	void AddPainting() { UE_LOG(LogTemp, Warning, TEXT("Adding Painting")) };

};
