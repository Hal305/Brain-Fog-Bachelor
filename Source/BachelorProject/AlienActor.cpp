// Fill out your copyright notice in the Description page of Project Settings.


#include "AlienActor.h"

#include "Engine/SkeletalMesh.h"

// Sets default values
AAlienActor::AAlienActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AAlienActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAlienActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AAlienActor::CheckPlayerTextInput(FString playerInput, FString &alienOutput)
{
	playerInput = playerInput.TrimStart();
	playerInput =  playerInput.TrimEnd();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *playerInput);
	for (int i = 0; i < gameplayData.correctInputs.Num(); i++)
	{
		if (playerInput.ToLower().Equals(gameplayData.correctInputs[i].ToLower()))
		{
			alienOutput = gameplayData.phaseStartOutput;
			phaseCount++;
			return true;
		}
	}
	for (int i = 0; i < gameplayData.specialInputs.Num(); i++)
	{
		if (playerInput.ToLower().Equals(gameplayData.specialInputs[i].ToLower()))
		{
			alienOutput = gameplayData.specialOutputs[i];
			return false;
		}
	}
	alienOutput = gameplayData.defaultWrongOutput;
	return false;
}

