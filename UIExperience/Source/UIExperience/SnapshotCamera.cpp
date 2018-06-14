// Fill out your copyright notice in the Description page of Project Settings.

#include "SnapshotCamera.h"

#include "Kismet/KismetRenderingLibrary.h"

// Sets default values
ASnapshotCamera::ASnapshotCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CaptureComponent = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("CaptureComponent"));
	CaptureComponent->bCaptureEveryFrame = false;
	CaptureComponent->bCaptureOnMovement = false;
	CaptureComponent->CaptureSource = SCS_FinalColorLDR;
}

void ASnapshotCamera::CaptureScreenshot(const FString & Directory, const FString & Filename)
{
	auto RenderTarget = UKismetRenderingLibrary::CreateRenderTarget2D(this, 1000, 1000, RTF_RGBA8);
	CaptureComponent->TextureTarget = RenderTarget;
	CaptureComponent->CaptureScene();
	UKismetRenderingLibrary::ExportRenderTarget(this, RenderTarget, Directory, Filename);
}