// Fill out your copyright notice in the Description page of Project Settings.


#include "AlienManager.h"
#include "AlienActor.h"
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

bool AAlienManager::CheckPlayerTextInput(FString playerInput, FString& alienOutput)
{
	playerInput = playerInput.TrimStart();
	playerInput =  playerInput.TrimEnd();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *playerInput);
	for (int i = 0; i < alienData.correctInputs.Num(); i++)
	{
		if (playerInput.ToLower().Equals(alienData.correctInputs[i].ToLower()))
		{
			alienOutput = alienData.correctOutput;
			phaseCount++;
			return true;
		}
	}
	for (int i = 0; i < alienData.specialInputs.Num(); i++)
	{
		if (playerInput.ToLower().Equals(alienData.specialInputs[i].ToLower()))
		{
			alienOutput = alienData.specialOutputs[i];
			return false;
		}
	}
	alienOutput = alienData.defaultWrongOutput;
	return false;
}



void AAlienManager::SetAlien(FAlienList aliensIn)
{
	aliens = aliensIn;
	//aliens.alienData = aliensIn.alienData;
	
	alienClone = UGameplayStatics::GetActorOfClass(GetWorld(), AAlienActor::StaticClass());
	currentAlien = Cast<AAlienActor>(alienClone);
}

FString AAlienManager::ManageAlien(FString playerTextInput)
{
	//UE_LOG(LogTemp, Warning, TEXT("Player text input: %s"), *playerTextInput.ToString());
	phaseChange = CheckPlayerTextInput(playerTextInput, alienTextOutput);
	return alienTextOutput;
}

void AAlienManager::SetupLevelPhase(TArray<FString> newCorrectInputs, FString newCorrectOutput,
                                    TArray<FString> newSpecialInputs, TArray<FString> newSpecialOutputs,
                                    FString newDefaultWrongOutput,int newCorrectAnim,
                                    TArray<int> newSpecialAnim, int newWrongAnim)
									//FAlienData alienDataIn)
{
	alienData.correctInputs = newCorrectInputs;
	alienData.correctOutput = newCorrectOutput;
	alienData.specialInputs = newSpecialInputs;
	alienData.specialOutputs = newSpecialOutputs;
	alienData.defaultWrongOutput = newDefaultWrongOutput;
	alienData.correctAnim = newCorrectAnim;
	alienData.specialAnim = newSpecialAnim;
	alienData.wrongAnim = newWrongAnim;

	//alienData = alienDataIn;
	
	phaseChange = false;
}



