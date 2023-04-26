// Fill out your copyright notice in the Description page of Project Settings.


#include "AlienManager.h"
#include "AlienActor.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAlienManager::AAlienManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAlienManager::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AAlienManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void AAlienManager::SetAlien()
{
	alienClone = UGameplayStatics::GetActorOfClass(GetWorld(), AAlienActor::StaticClass());
	currentAlien = Cast<AAlienActor>(alienClone);
}

FString AAlienManager::ManageAlien(FString playerTextInput)
{
	//UE_LOG(LogTemp, Warning, TEXT("Player text input: %s"), *playerTextInput.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("Running ManageAlien before input check"));
	phaseChange = currentAlien->CheckPlayerTextInput(playerTextInput, alienTextOutput);
	//UE_LOG(LogTemp, Warning, TEXT("Alien text output: %s"), *alienTextOutput.ToString());
	if(currentAlien->phaseCount > currentAlien->maxPhases)
	{
		levelDone = true;
		phaseChange = false;
	}
	return alienTextOutput;
}

void AAlienManager::SetupLevelPhase(TArray<FString> newCorrectInputs, FString newCorrectOutput,
                                    TArray<FString> newSpecialInputs, TArray<FString> newSpecialOutputs,
                                    FString newDefaultWrongOutput, FString startingOutput)
{
	currentAlien->gameplayData.correctInputs = newCorrectInputs;
	currentAlien->gameplayData.correctOutput = newCorrectOutput;
	currentAlien->gameplayData.specialInputs = newSpecialInputs;
	currentAlien->gameplayData.specialOutputs = newSpecialOutputs;
	currentAlien->gameplayData.defaultWrongOutput = newDefaultWrongOutput;
	currentAlien->gameplayData.startingOutput = startingOutput;
	
	phaseChange = false;
}



