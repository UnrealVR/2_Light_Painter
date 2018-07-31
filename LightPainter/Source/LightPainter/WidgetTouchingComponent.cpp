// Fill out your copyright notice in the Description page of Project Settings.

#include "WidgetTouchingComponent.h"

#include "WidgetComponent.h"

void UWidgetTouchingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsOverInteractableWidget() && !bIsClicked)
	{
		PressPointerKey(EKeys::LeftMouseButton);
		bIsClicked = true;
		UE_LOG(LogTemp, Warning, TEXT("Clicked"));
	}
	if (!IsOverInteractableWidget() && bIsClicked)
	{
		ReleasePointerKey(EKeys::LeftMouseButton);
		UE_LOG(LogTemp, Warning, TEXT("Released"));
		bIsClicked = false;
	}
}