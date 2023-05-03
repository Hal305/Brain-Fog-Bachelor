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

bool AAlienManager::FindQuote(FString text, int index)
{
	for (int i = index; i < text.Len(); i++)
		if(text[i] == '\"')
			return true;
	return false;
}

TArray<FString> AAlienManager::SplitOutput(FString text)
{
	//Based on this tutorial:
	//https://jiyuututorials.wixsite.com/home/substring-fstring-operator
			
	bool quote = false;

	TArray<FString> partitionedOutput;
	if (!FindQuote(text, 0))
	{
		partitionedOutput.Add(text);
		//UE_LOG(LogTemp, Warning, TEXT("Exerpt: %s"), *text);
		return partitionedOutput;
	}
	
	int32 startIndex = 0;
	int32 endIndex = 0;

	if (text[0] == '\"')
		quote = true;
	else
	{
		partitionedOutput.Add(ExtractNarration(text, startIndex));
	}
	
	for (int i = startIndex; i < text.Len(); i = startIndex)
	{
		// if (quote)
		// {
		// 	ExtractNarration(text, startIndex);
		// }
		// else
		// {
		if (text[i] == '\"')
			startIndex -= 1;
		partitionedOutput.Add(ExtractNarration(text, startIndex));
		// }
	}
	return partitionedOutput;
}

FString AAlienManager::ExtractNarration(FString text, int32 &startIndex)
{
	int32 endIndex = text.Find("\"", ESearchCase::IgnoreCase,
		ESearchDir::Type::FromStart, startIndex) - 1;
	int32 exerptLength = endIndex - startIndex + 1;
	FString exerpt = text.Mid(startIndex, exerptLength);
	UE_LOG(LogTemp, Warning, TEXT("Index: %i"), startIndex);
	UE_LOG(LogTemp, Warning, TEXT("Exerpt: %s"), *exerpt);
	startIndex += exerpt.Len();
	
	return exerpt;
}

// FString AAlienManager::ExtractDialogue(FString text, int32 &startIndex)
// {
// 	int32 endIndex = text.Find("\"", ESearchCase::IgnoreCase,
// 	ESearchDir::Type::FromStart, startIndex + 1);
// 	int32 exerptLength = endIndex - startIndex + 1;
// 	FString exerpt = text.Mid(startIndex, exerptLength);
// 	UE_LOG(LogTemp, Warning, TEXT("Exerpt: %s"), *exerpt);
// 	startIndex += exerptLength;
// 	return exerpt;
// }

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



