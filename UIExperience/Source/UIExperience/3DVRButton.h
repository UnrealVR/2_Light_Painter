// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/CapsuleComponent.h"
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
	// Components
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Collider;

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* Widget;
	
};
