// Fill out your copyright notice in the Description page of Project Settings.


#include "Area.h"

// Sets default values
AArea::AArea()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AArea::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("HELLO THERE! THIS IS A SMALL CHANGE"));
	Super::BeginPlay();
	
}

// Called every frame
void AArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}