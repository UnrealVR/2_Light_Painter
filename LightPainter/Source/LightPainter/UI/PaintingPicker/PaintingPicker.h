// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/WidgetComponent.h"

#include "PaintingPicker.generated.h"

UCLASS()
class LIGHTPAINTER_API APaintingPicker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APaintingPicker();

protected:
	void BeginPlay() override;

private:

	void ReloadPaintings();

	// Components
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* PaintingGrid;

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* ActionBar;
	
};