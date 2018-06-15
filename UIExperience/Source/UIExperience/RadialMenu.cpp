// Fill out your copyright notice in the Description page of Project Settings.

#include "RadialMenu.h"

#include "PainterPawn/VRPainterPawn.h"


bool URadialMenu::Initialize()
{
	if (!Super::Initialize()) return false;
	if (BrushButton) BrushButton->OnClicked.AddDynamic(this, &URadialMenu::BrushButtonClicked);
	if (EraserButton) EraserButton->OnClicked.AddDynamic(this, &URadialMenu::EraserButtonClicked);
	if (BackButton) BackButton->OnClicked.AddDynamic(this, &URadialMenu::BackButtonClicked);
	return true;
}

void URadialMenu::BrushButtonClicked()
{
}

void URadialMenu::EraserButtonClicked()
{
}

void URadialMenu::BackButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Bakc"));
	auto Pawn = Cast<AVRPainterPawn>(GetOwningPlayerPawn());
	if (Pawn)
	{
		Pawn->SaveAndQuit();
	}
}

