#include "QueriesLoadingStep.h"

#include "GroundTruthLoadingStep.h"

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

	const auto& GroundTruthComponent {GetOwner()->GetComponentByClass(UGroundTruthLoadingStep::StaticClass())};
	const auto& GroundTruth {Cast<UGroundTruthLoadingStep>(GroundTruthComponent)->GetGroundTruth()};

	for (const auto& Way : GroundTruth)
	{
		checkf(Way.size() > 0U, TEXT("FOUND EMPTY WAY WHILE GENERATING QUERIES"));
		const size_t LinesInWay {Way.size() - 1U};
		m_GroundTruthVisualInfo.emplace_back(tTrackVisualInfo(LinesInWay, sSegmentVisualInfo()));
	}

	m_LoadingFinished = true;
}

void UQueriesLoadingStep::StopLoadThread()
{
	// Kills process that is generating queries. 
}

UQueriesLoadingStep::tGroundTruthVisualInfo& UQueriesLoadingStep::GetQueriesInfo()
{
	return m_GroundTruthVisualInfo;
}