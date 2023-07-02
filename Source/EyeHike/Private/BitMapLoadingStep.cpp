#include "BitMapLoadingStep.h"

UBitMapLoadingStep::UBitMapLoadingStep()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBitMapLoadingStep::BeginPlay()
{
	Super::BeginPlay();
}

void UBitMapLoadingStep::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UBitMapLoadingStep::LoadDataFromFiles()
{
	UE_LOG(LogTemp, Warning, TEXT("Loading bitmap from file."));
	// Reads bitmap result, from a previous generated result (load a png)
}

void UBitMapLoadingStep::LaunchLoadThread()
{
	UE_LOG(LogTemp, Warning, TEXT("Generating bitmap."));
	m_LoadingFinished = true;
	// Generates bitmap based on har coded config.
}

void UBitMapLoadingStep::StopLoadThread()
{
	// Kills process that is generating bitmap. . 
}