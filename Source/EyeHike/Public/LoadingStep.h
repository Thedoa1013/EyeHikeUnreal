// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LoadingStep.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class ULoadingStep : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface which implements functionality about a step of the loading process.
 */
class EYEHIKE_API ILoadingStep
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/**
	* Loads from files data corresponding to current step generated in a previous loading procedure.
	*/
	virtual void LoadDataFromFiles(); 

	/**
	* Launches Thread that will perform the current generation step. 
	*/
	virtual void LaunchLoadThread();

	/**
	* Kills current load process. 
	*/
	virtual void StopLoadThread();
};
