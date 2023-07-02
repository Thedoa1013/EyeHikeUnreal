#include "GroundTruthLoadingStep.h"

UGroundTruthLoadingStep::UGroundTruthLoadingStep()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame. 
	// Turn these features off to improve performance if not needed.
	PrimaryComponentTick.bCanEverTick = true;
}

void UGroundTruthLoadingStep::BeginPlay()
{
	Super::BeginPlay();
}

void UGroundTruthLoadingStep::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UGroundTruthLoadingStep::LoadDataFromFiles()
{
	UE_LOG(LogTemp, Warning, TEXT("Loading ground truth from file."));
	m_LoadingFinished = true; 
	// Load ground truth from files: parse xml. 
}