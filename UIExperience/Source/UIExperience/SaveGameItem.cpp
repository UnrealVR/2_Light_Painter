// Fill out your copyright notice in the Description page of Project Settings.

#include "SaveGameItem.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/StereoLayerFunctionLibrary.h"

#include "LaserPainterGameInstance.h"
#include "PaintingSaveGame.h"

void USaveGameItem::SetName(const FString & NameText)
{
	Name->SetText(FText::FromString(NameText));
}

void USaveGameItem::Clicked()
{
	auto GameInstance = Cast<ULaserPainterGameInstance>(GetWorld()->GetGameInstance());
	if (GameInstance)
	{
		GameInstance->SetSaveGameToLoad(GetName());

		UStereoLayerFunctionLibrary::ShowSplashScreen();

		UGameplayStatics::OpenLevel(GetWorld(), "Canvas", true, "SaveGame=" + GetName());
	}
}

FString USaveGameItem::GetName() const
{
	return Name->GetText().ToString();
}
