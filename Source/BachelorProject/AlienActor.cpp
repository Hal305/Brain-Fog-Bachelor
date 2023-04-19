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
	for (int i = 0; i < gameData.correctInputs.Num(); i++)
	{
		if (playerInput.ToLower().EqualTo(gameData.correctInputs[i].ToLower()))
		{
			alienOutput = gameData.correctOutput;
			phaseCount++;
			return true;
		}
	}
	for (int i = 0; i < gameData.specialInputs.Num(); i++)
	{
		if (playerInput.ToLower().EqualTo(gameData.specialInputs[i].ToLower()))
		{
			alienOutput = gameData.specialOutputs[i];
			return false;
		}
	}
	alienOutput = gameData.defaultWrongOutput;
	return false;
}

void AAlienActor::UpdateGameplayText(TArray<FText> newCorrectInputs, FText newCorrectOutput,
	TArray<FText> newSpecialInputs, TArray<FText> newSpecialOutputs, FText newDefaultWrongOutput)
{
	gameData.correctInputs = newCorrectInputs;
	gameData.correctOutput = newCorrectOutput;
	gameData.specialInputs = newSpecialInputs;
	gameData.specialOutputs = newSpecialOutputs;
	gameData.defaultWrongOutput = newDefaultWrongOutput; 
}

