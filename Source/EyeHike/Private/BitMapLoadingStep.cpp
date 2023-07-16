#include "BitMapLoadingStep.h"

#include "Area.h"
#include "GroundTruthLoadingStep.h"
#include "QueriesLoadingStep.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Engine/Canvas.h"

#include "Engine/Texture2D.h" // TODO: MAYBE REMOVE THIS???.
#include "Serialization/BulkData.h" // TODO: MAYBE REMOVE THIS???.

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
	



	// Sooo we should CreateCanvasRenderTarget2D
	// Bind function to it
	// Update it
	// Set is as material on the mesh component (or the terrain actor). 
	

	// Using KismetRenderingLibrary::BeginDrawCanvasToRenderTarget. 

	float MAP_WIDTH {128.0f};
	float MAP_HEIGHT {128.0f};

	up_RenderTarget->InitCustomFormat(MAP_WIDTH, MAP_HEIGHT, PF_B8G8R8A8, true);
	UCanvas* Canvas;
	FVector2D CanvasSize {128.0f, 128.0f};
	FDrawToRenderTargetContext Context;

	FVector Location {GetOwner()->GetActorLocation()};

	UKismetRenderingLibrary::BeginDrawCanvasToRenderTarget(this, up_RenderTarget, Canvas, CanvasSize, Context);

	FVector2D LineLocStart {FVector2D(Location.X, Location.Y)};
	FVector2D LineLocEnd {LineLocStart + FVector2D(100, 100)};
	Canvas->K2_DrawLine(LineLocStart, LineLocEnd, 2.0f, FLinearColor::Yellow);

	UKismetRenderingLibrary::EndDrawCanvasToRenderTarget(this, Context);

	UMaterialInstanceDynamic* DynamicMaterial = MeshComponent->CreateDynamicMaterialInstance(0, MeshComponent->GetMaterial(0));
	DynamicMaterial->SetTextureParameterValue("Texture", up_RenderTarget);
	MeshComponent->SetMaterial(0, DynamicMaterial);
	
	// Modyfying directly the texture, bit by bit: 
	//uint32 MAP_WIDTH {100U};
	//uint32 MAP_HEIGHT {100U};
	//UTexture2D* CustomTexture = UTexture2D::CreateTransient(MAP_WIDTH, MAP_HEIGHT);
	//FTexture2DMipMap* MipMap = &(CustomTexture->PlatformData->Mips[0]);
	//FByteBulkData* ImageData = &(MipMap->BulkData);
	//uint8* RawImageData = (uint8*)ImageData->Lock(LOCK_READ_WRITE);
	//int ArraySize = 4 * MAP_WIDTH * MAP_HEIGHT;
	//for (auto i = 0; i < ArraySize; i += 4)
	//{
	//	RawImageData[i] = 255;
	//	RawImageData[i + 1] = 0;
	//	RawImageData[i + 2] = 255;
	//	RawImageData[i + 3] = 0;
	//}
	//ImageData->Unlock();
	//CustomTexture->UpdateResource();
	//UMaterialInstanceDynamic* DynamicMaterial = MeshComponent->CreateDynamicMaterialInstance(0, MeshComponent->GetMaterial(0));
	//DynamicMaterial->SetTextureParameterValue("Texture", CustomTexture);
	//MeshComponent->SetMaterial(0, DynamicMaterial);

	m_LoadingFinished = true;
}

void UBitMapLoadingStep::StopLoadThread()
{
	// Kills process that is generating bitmap. 
}