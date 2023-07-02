#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"

#include "LoadingStep.h"
#include "GroundTruthLoadingStep.generated.h"

/**
 * @brief Loading step that obtains the ground truth.
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EYEHIKE_API UGroundTruthLoadingStep : public USceneComponent, public ILoadingStep
{
	GENERATED_BODY()

public:	
	/**
	* @brief Constructor. Sets default values for this component's properties.
	*/
	UGroundTruthLoadingStep();

protected:
	/**
	 * @brief Called when the game starts.
	*/
	virtual void BeginPlay() override;

public:	
	/**
	 * @brief Called every frame. 
	 * @param DeltaTime 
	 * @param TickType 
	 * @param ThisTickFunction 
	*/
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/**
	* @brief Loads from files data corresponding to current step generated in a previous loading procedure.
	*/
	void LoadDataFromFiles() override;
};
