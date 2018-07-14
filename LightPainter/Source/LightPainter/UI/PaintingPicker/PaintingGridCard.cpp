// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGridCard.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/StereoLayerFunctionLibrary.h"


void UPaintingGridCard::SetPaintingName(FString NewPaintingName)
{
	PaintingName = NewPaintingName;
	PaintingNameText->SetText(FText::FromString(PaintingName));
	PaintingButton->OnClicked.AddDynamic(this, &UPaintingGridCard::Clicked);
}

void UPaintingGridCard::Clicked()
{
	UStereoLayerFunctionLibrary::ShowSplashScreen();
	UGameplayStatics::OpenLevel(this, "Canvas", true, "PaintingName=" + PaintingName);
}
