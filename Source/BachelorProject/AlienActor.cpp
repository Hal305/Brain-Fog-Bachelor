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

bool AAlienActor::CheckPlayerTextInput(FText playerInput, FText &alienOutput)
{
	playerInput = FText::TrimPreceding(playerInput);
	playerInput = FText::TrimTrailing(playerInput);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *playerInput.ToString());
	for (int i = 0; i < gameplayData.correctInputs.Num(); i++)
	{
		if (playerInput.ToLower().EqualTo(gameplayData.correctInputs[i].ToLower()))
		{
			alienOutput = gameplayData.phaseStartOutput;
			phaseCount++;
			return true;
		}
	}
	for (int i = 0; i < gameplayData.specialInputs.Num(); i++)
	{
		if (playerInput.ToLower().EqualTo(gameplayData.specialInputs[i].ToLower()))
		{
			alienOutput = gameplayData.specialOutputs[i];
			return false;
		}
	}
	alienOutput = gameplayData.defaultWrongOutput;
	return false;
}

void AAlienActor::UpdateGameplayText(TArray<FText> newCorrectInputs, FText newPhaseStartOutput,
	TArray<FText> newSpecialInputs, TArray<FText> newSpecialOutputs, FText newDefaultWrongOutput)
{
	gameplayData.correctInputs = newCorrectInputs;
	gameplayData.phaseStartOutput = newPhaseStartOutput;
	gameplayData.specialInputs = newSpecialInputs;
	gameplayData.specialOutputs = newSpecialOutputs;
	gameplayData.defaultWrongOutput = newDefaultWrongOutput; 
}

