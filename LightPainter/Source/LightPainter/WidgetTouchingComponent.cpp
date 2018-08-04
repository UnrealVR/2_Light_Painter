// Fill out your copyright notice in the Description page of Project Settings.

#include "WidgetTouchingComponent.h"


void UWidgetTouchingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsOverInteractableWidget() && !bIsClicked)
	{
		PressPointerKey(EKeys::LeftMouseButton);
		UE_LOG(LogTemp, Warning, TEXT("Pressed."));
		bIsClicked = true;
	}
	if (!IsOverInteractableWidget() && bIsClicked)
	{
		ReleasePointerKey(EKeys::LeftMouseButton);
		UE_LOG(LogTemp, Warning, TEXT("Release."));
		bIsClicked = false;
	}

}

