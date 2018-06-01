// Fill out your copyright notice in the Description page of Project Settings.

#include "SaveGameItem.h"

void USaveGameItem::SetName(const FString & NameText)
{
	Name->SetText(FText::FromString(NameText));
}

FString USaveGameItem::GetName() const
{
	return Name->GetText().ToString();
}
