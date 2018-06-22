// Fill out your copyright notice in the Description page of Project Settings.

#include "SaveGameItem.h"

#include "Brushes/SlateDynamicImageBrush.h"
#include "HAL/FileManager.h"

#include "Data/PaintingSaveGame.h"

void USaveGameItem::SetName(const FString & NameText)
{
	Name = NameText;

	FString ImagePath = UPaintingSaveGame::GetImagePath(Name);
	if (IFileManager::Get().FileExists(*ImagePath))
	{
		// TODO: Parameter for size
		FSlateDynamicImageBrush Brush(*ImagePath, FVector2D(1000, 1000), FLinearColor::White);
		Thumbnail->SetBrush(Brush);
	}
}

FString USaveGameItem::GetName() const
{
	return Name;
}
