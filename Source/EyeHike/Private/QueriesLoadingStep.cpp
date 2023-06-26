// Fill out your copyright notice in the Description page of Project Settings.


#include "QueriesLoadingStep.h"

// Sets default values for this component's properties
UQueriesLoadingStep::UQueriesLoadingStep()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UQueriesLoadingStep::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UQueriesLoadingStep::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UQueriesLoadingStep::LoadDataFromFiles()
{
	// Reads queriy results from file, from a previous generated result (parse xml). 
}

void UQueriesLoadingStep::LaunchLoadThread()
{
	// Generates queries results based on hard coded config.
}

void UQueriesLoadingStep::StopLoadThread()
{
	// Kills process that is generating queries. 
}

