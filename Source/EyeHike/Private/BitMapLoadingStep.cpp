// Fill out your copyright notice in the Description page of Project Settings.


#include "BitMapLoadingStep.h"

// Sets default values for this component's properties
UBitMapLoadingStep::UBitMapLoadingStep()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBitMapLoadingStep::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBitMapLoadingStep::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBitMapLoadingStep::LoadDataFromFiles()
{
	// Reads bitmap result, from a previous generated result (load a png)
}

void UBitMapLoadingStep::LaunchLoadThread()
{
	// Generates bitmap based on har coded config.
}

void UBitMapLoadingStep::StopLoadThread()
{
	// Kills process that is generating bitmap. . 
}