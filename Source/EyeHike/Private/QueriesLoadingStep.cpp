#include "QueriesLoadingStep.h"

UQueriesLoadingStep::UQueriesLoadingStep()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame. 
	// Turn these features off to improve performance if not needed.
	PrimaryComponentTick.bCanEverTick = true;
}

void UQueriesLoadingStep::BeginPlay()
{
	Super::BeginPlay();
}

void UQueriesLoadingStep::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UQueriesLoadingStep::LoadDataFromFiles()
{
	UE_LOG(LogTemp, Warning, TEXT("Loading generated queries from file."));
	// Reads queriy results from file, from a previous generated result (parse xml). 
}

void UQueriesLoadingStep::LaunchLoadThread()
{
	UE_LOG(LogTemp, Warning, TEXT("Generating queries."));
	m_LoadingFinished = true;
	// Generates queries results based on hard coded config.
	// For now, just pass the ground truth data to the next component. 
}

void UQueriesLoadingStep::StopLoadThread()
{
	// Kills process that is generating queries. 
}