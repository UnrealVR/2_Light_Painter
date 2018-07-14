// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGridCard.h"


void UPaintingGridCard::SetPaintingName(FString PaintingName)
{
	PaintingNameText->SetText(FText::FromString(PaintingName));
}
