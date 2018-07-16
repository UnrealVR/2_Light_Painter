// Fill out your copyright notice in the Description page of Project Settings.

#include "ActionBar.h"

bool UActionBar::Initialize()
{
	if (!Super::Initialize()) return false;

	if (!AddButton) return false;

	AddButton->OnClicked.AddDynamic(this, &UActionBar::AddPainting);

	return true;
}


