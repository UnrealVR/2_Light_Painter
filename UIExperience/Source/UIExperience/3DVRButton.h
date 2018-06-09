// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/ArrowComponent.h"
#include "Components/WidgetComponent.h"

#include "3DVRButton.generated.h"

UCLASS()
class UIEXPERIENCE_API A3DVRButton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	A3DVRButton();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Config
	UPROPERTY(EditAnywhere)
	float TraceRadius = 5;
	UPROPERTY(EditAnywhere)
	float TraceDepth = 1;

	// Components
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UArrowComponent* TraceStart;

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* Widget;
	
	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* TriggerPlaneWidget;

};
