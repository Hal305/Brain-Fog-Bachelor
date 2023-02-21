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

bool AAlienActor::CheckPlayerTextInput(FText input)
{
	for (int i = 0; i < numberOfCorrectInputs; i++)
	{
		if (input.ToLower().EqualTo(correctInputs[i].ToLower()))
		{
			phaseCount++;
			//CorrectInputs.Empty(); //Might be done elsewhere
			return true;
		}
	}
	for (int i = 0; i < numberOfSpecialInputs; i++)
	{
		if (input.ToLower().EqualTo(specialInputs[i].ToLower()))
		{
			break;
		}
	}
	return false;
}

