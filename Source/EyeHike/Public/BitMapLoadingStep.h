// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "LoadingStep.h"
#include "BitMapLoadingStep.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EYEHIKE_API UBitMapLoadingStep : public USceneComponent, public ILoadingStep
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBitMapLoadingStep();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/**
	* Loads from files data corresponding to current step generated in a previous loading procedure.
	*/
	void LoadDataFromFiles() override;

	/**
	* Launches Thread that will perform the current generation step.
	*/
	void LaunchLoadThread() override;

	/**
	* Kills current load process.
	*/
	void StopLoadThread() override;
};
