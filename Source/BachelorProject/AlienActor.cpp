// Fill out your copyright notice in the Description page of Project Settings.


#include "AlienActor.h"

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

	phaseCount = 0;
	numberOfCorrectInputs, numberOfSpecialInputs = 0;
}

// Called every frame
void AAlienActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AAlienActor::CheckPlayerTextInput(FText playerInput, FText &alienOutput)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *playerInput.ToString());
	for (int i = 0; i < numberOfCorrectInputs; i++)
	{
		if (playerInput.ToLower().EqualTo(testCorrect.ToLower()))
		{
			phaseCount++;
			//CorrectInputs.Empty(); //Might be done elsewhere
			alienOutput = alienOutput.FromString("Yes!");
			UE_LOG(LogTemp, Warning, TEXT("Input match!"));
			return true;
		}
	}
	for (int i = 0; i < numberOfSpecialInputs; i++)
	{
		if (playerInput.ToLower().EqualTo(specialInputs[i].ToLower()))
		{
			break;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("No input match!"));
	alienOutput = alienOutput.FromString("Huh?");
	return false;
}

