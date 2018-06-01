// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/WidgetInteractionComponent.h"
#include "PaintBrushHandController.h"

#include "VRPawn.generated.h"


UCLASS()
class UIEXPERIENCE_API AVRPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVRPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	void RightTriggerPressed() { RightHandController->RightTriggerPressed(); }
	void RightTriggerReleased() { RightHandController->RightTriggerReleased(); }
	void Save();
	void Load();

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;
	
	UPROPERTY(VisibleAnywhere)
	UWidgetInteractionComponent* WidgetInteractionComponent;

	UPROPERTY(VisibleAnywhere)
	APaintBrushHandController* RightHandController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<APaintBrushHandController> RightHandControllerClass;

};
