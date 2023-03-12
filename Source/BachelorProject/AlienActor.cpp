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
	for (int i = 0; i < correctInputs.Num(); i++)
	{
		if (playerInput.ToLower().EqualTo(correctInputs[i].ToLower()))
		{
			alienOutput = correctOutput;
			phaseCount++;
			return true;
		}
	}
	for (int i = 0; i < specialInputs.Num(); i++)
	{
		if (playerInput.ToLower().EqualTo(specialInputs[i].ToLower()))
		{
			alienOutput = specialOutputs[i];
			return false;
		}
	}
	alienOutput = defaultWrongOutput;
	return false;
}

void AAlienActor::UpdateGameplayText(TArray<FText> newCorrectInputs, FText newCorrectOutput,
	TArray<FText> newSpecialInputs, TArray<FText> newSpecialOutputs, FText newDefaultWrongOutput)
{
	correctInputs = newCorrectInputs;
	correctOutput = newCorrectOutput;
	specialInputs = newSpecialInputs;
	specialOutputs = newSpecialOutputs;
	defaultWrongOutput = newDefaultWrongOutput; 
}

