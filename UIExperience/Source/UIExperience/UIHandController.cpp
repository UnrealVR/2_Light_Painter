// Fill out your copyright notice in the Description page of Project Settings.

#include "UIHandController.h"

AUIHandController::AUIHandController()
{
	WidgetInteractionComponent = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("WidgetInteractionComponent"));
	WidgetInteractionComponent->SetupAttachment(GetRootComponent());
	WidgetInteractionComponent->bShowDebug = true;
}

void AUIHandController::RightTriggerPressed()
{
	WidgetInteractionComponent->PressPointerKey(EKeys::LeftMouseButton);
}

void AUIHandController::RightTriggerReleased()
{
	WidgetInteractionComponent->ReleasePointerKey(EKeys::LeftMouseButton);
}