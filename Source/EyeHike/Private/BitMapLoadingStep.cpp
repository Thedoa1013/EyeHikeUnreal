#include "BitMapLoadingStep.h"

#include "GroundTruthLoadingStep.h"
#include "QueriesLoadingStep.h"
#include "Serialization/BulkData.h"
#include "Engine/Texture2D.h"

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

	const auto& GroundTruthComponent {GetOwner()->GetComponentByClass(UGroundTruthLoadingStep::StaticClass())};
	const auto& GroundTruth {Cast<UGroundTruthLoadingStep>(GroundTruthComponent)->GetGroundTruth()};

	const auto& QueriesComponent {GetOwner()->GetComponentByClass(UQueriesLoadingStep::StaticClass())};
	const auto& QueriesInfo {Cast<UQueriesLoadingStep>(QueriesComponent)->GetQueriesInfo()};

	const auto& MeshComponent {Cast<UMeshComponent>(GetOwner()->GetComponentByClass(UStaticMeshComponent::StaticClass()))};

	uint32 MAP_WIDTH {100U};
	uint32 MAP_HEIGHT {100U};

	//UTexture2D* RuntimeTexture = UTexture2D::CreateTransient(MAP_WIDTH, MAP_HEIGHT);
	//FTexturePlatformData** PlatformData;
	
	//PlatformData = RuntimeTexture->GetRunningPlatformData();
	//FTexture2DMipMap FirstMip = (*PlatformData)->Mips[0];
	//FByteBulkData ImageData = FirstMip.BulkData;
	//uint8* RawImageData = (uint8*)ImageData.Lock(LOCK_READ_WRITE);

	UTexture2D* CustomTexture = UTexture2D::CreateTransient(MAP_WIDTH, MAP_HEIGHT);
	FTexture2DMipMap* MipMap = &(CustomTexture->PlatformData->Mips[0]);
	FByteBulkData* ImageData = &(MipMap->BulkData);
	uint8* RawImageData = (uint8*)ImageData->Lock(LOCK_READ_WRITE);


	int ArraySize = 4 * MAP_WIDTH * MAP_HEIGHT;
	for (auto i = 0; i < ArraySize; i += 4)
	{
		RawImageData[i] = 255;
		RawImageData[i + 1] = 0;
		RawImageData[i + 2] = 255;
		RawImageData[i + 3] = 0;
	}

	ImageData->Unlock();
	CustomTexture->UpdateResource();

	UMaterialInstanceDynamic* DynamicMaterial = MeshComponent->CreateDynamicMaterialInstance(0, MeshComponent->GetMaterial(0));
	DynamicMaterial->SetTextureParameterValue("Texture", CustomTexture);


	MeshComponent->SetMaterial(0, DynamicMaterial);

	m_LoadingFinished = true;
	// Generates bitmap based on hardcoded config.
}

void UBitMapLoadingStep::StopLoadThread()
{
	// Kills process that is generating bitmap. . 
}