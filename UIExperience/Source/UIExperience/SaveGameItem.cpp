// Fill out your copyright notice in the Description page of Project Settings.

#include "SaveGameItem.h"

#include "Kismet/GameplayStatics.h"

#include "LaserPainterGameInstance.h"
#include "PaintingSaveGame.h"

void USaveGameItem::SetName(const FString & NameText)
{
	Name->SetText(FText::FromString(NameText));
}

void USaveGameItem::Clicked()
{
	UE_LOG(LogTemp, Warning, TEXT("cLICKED"));
	auto GameInstance = Cast<ULaserPainterGameInstance>(GetWorld()->GetGameInstance());
	if (GameInstance)
	{
		GameInstance->SetSaveGameToLoad(GetName());
		UGameplayStatics::OpenLevel(GetWorld(), "Canvas");
	}
}

FString USaveGameItem::GetName() const
{
	return Name->GetText().ToString();
}
