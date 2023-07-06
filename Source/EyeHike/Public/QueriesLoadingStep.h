#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "LoadingStep.h"
#include "QueriesLoadingStep.generated.h"

/**
 * @brief Loading step that queries matches to enrichen ground truth info.
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EYEHIKE_API UQueriesLoadingStep : public USceneComponent, public ILoadingStep
{
	GENERATED_BODY()

public:	
	/**
	* @brief Constructor. Sets default values for this component's properties.
	*/
	UQueriesLoadingStep();

protected:
	/**
	 * @brief Called when the game starts.
	*/
	virtual void BeginPlay() override;

public:	

	/**
	 * @brief Struct whith the info to paint a line between to points in the bitmap.
	*/
	struct sSegmentVisualInfo
	{
		FColor Color {}; //!< Color of the line. 
		float Width {1.0f}; //!< Width of the line, in some unit. 

		sSegmentVisualInfo(FColor aColor, uint64_t aWidth) :
			Color(aColor),
			Width(aWidth)
		{}

		sSegmentVisualInfo() :
			Color(255U,0U,0U,255U), // TODO: Move default color into variable. 
			Width(1.0f)
		{}
	};

	using tTrackVisualInfo = std::vector<sSegmentVisualInfo>; //!< Type to save the information to draw a OSM way. 
	using tGroundTruthVisualInfo = std::vector<tTrackVisualInfo>; //!< Type to save the information to draw the ground truth. 

	/**
	 * @brief Called every frame.
	 * @param DeltaTime
	 * @param TickType
	 * @param ThisTickFunction
	*/
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

	/**
	 * @brief Returns the queries info to paint the bit map. 
	 * @return Thethe queries info.
	*/
	tGroundTruthVisualInfo& GetQueriesInfo();

private:
	tGroundTruthVisualInfo m_GroundTruthVisualInfo {}; //!< Information on how to paint the segments relating to the ground truth. Index of ways and points is same as in ground truth.
};
