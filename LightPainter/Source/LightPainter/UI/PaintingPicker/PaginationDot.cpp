// Fill out your copyright notice in the Description page of Project Settings.

#include "PaginationDot.h"


void UPaginationDot::SetActive(bool Active)
{
	if (!DotImage) return;

	float Opacity = Active ? 1 : DeactivatedOpacity;
	DotImage->SetOpacity(Opacity);
}

