// Fill out your copyright notice in the Description page of Project Settings.


#include "MatchesLoadingStep.h"

// Sets default values for this component's properties
UMatchesLoadingStep::UMatchesLoadingStep()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMatchesLoadingStep::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMatchesLoadingStep::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMatchesLoadingStep::LoadDataFromFiles() 
{
	// Load matches from files: parse several xml. 
}