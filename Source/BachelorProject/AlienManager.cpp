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

void AAlienManager::SetAlien(FAlienList aliensIn)
{
	aliens = aliensIn;
	//aliens.alienData = aliensIn.alienData;
	
	alienClone = UGameplayStatics::GetActorOfClass(GetWorld(), AAlienActor::StaticClass());
	currentAlien = Cast<AAlienActor>(alienClone);
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

FString AAlienManager::ExtractDialogue(FString text)
{
	//Based on this tutorial:
	//https://jiyuututorials.wixsite.com/home/substring-fstring-operator
	int32 startIndex = text.Find("\"", ESearchCase::IgnoreCase,
	ESearchDir::Type::FromStart, 0);
	int32 endIndex = text.Find("\"", ESearchCase::IgnoreCase,
	ESearchDir::Type::FromStart, startIndex + 1);
	int32 colorLength = endIndex - startIndex + 1;

	FString colorText = text.Mid(startIndex, colorLength);
	//UE_LOG(LogTemp, Warning, TEXT("Color: %s"), *colorText);
	// for (int i = startIndex + 1; i < endIndex + 1; i++)
	// 	;
	return colorText;
}

FString AAlienManager::ManageAlien(FString playerTextInput)
{
	//UE_LOG(LogTemp, Warning, TEXT("Player text input: %s"), *playerTextInput.ToString());
	phaseChange = CheckPlayerTextInput(playerTextInput, alienTextOutput);
	return alienTextOutput;
}

void AAlienManager::SetupLevelPhase(FAlienData alienDataIn)
{
	alienData = alienDataIn;
	phaseChange = false;
}



