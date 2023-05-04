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
	for (int i = index; i < text.Len() - 1; i++)
	{
		if(text[i] == '\n' && text[i+1] == '\"'
			|| text[i] == '\"' && text[i+1] == '\n')
			return true;
	}
	return false;
}

FText AAlienManager::ExcludeCharacters(FText text)
{
	FString newString = "", tempString = text.ToString();
	//Prevents leading spaces and crashing from a negative index
	tempString = tempString.TrimStart(); 
	for (int i = 0; i < tempString.Len(); i++)
	{	//Prevents consecutive spaces
		if(tempString[i] == ' ' && tempString[i-1] != ' ') 
				newString += tempString[i];
		else
			for (int j = 0; j < lowerAlphabet.Len(); j++)
				if (lowerAlphabet[j] == tempString[i] || upperAlphabet[j] == tempString[i])
					newString += tempString[i];
	}
	FText out = FText::FromString(newString);
	//UE_LOG(LogTemp, Warning, TEXT("Exerpt: %s"), *out.ToString());
	return out;
}

TArray<FString> AAlienManager::SplitOutput(FString text)
{
	//Based on this tutorial:
	//https://jiyuututorials.wixsite.com/home/substring-fstring-operator
	int startIndex = 0, endIndex = 0, exerptLength = 0;
	FString exerpt;
	TArray<FString> partitionedOutput;
	for(int i = 0; i < text.Len(); i = startIndex)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Index: %i"), startIndex);
		if (FindQuote(text, startIndex))
		{
			endIndex = text.Find("\n", ESearchCase::IgnoreCase,
		ESearchDir::Type::FromStart, startIndex + 1);
			
			exerptLength = endIndex - startIndex + 1;
			exerpt = text.Mid(startIndex, exerptLength);
	
			// UE_LOG(LogTemp, Warning, TEXT("Size: %i"), exerptLength);
			// UE_LOG(LogTemp, Warning, TEXT("Index: %i"), endIndex);
			UE_LOG(LogTemp, Warning, TEXT("Exerpt: %s"), *exerpt);
			startIndex += exerptLength;
		}
		else
			break;
	}
	
	endIndex = text.Len() - 1;
	exerptLength = endIndex - startIndex + 1;
	exerpt = text.Mid(startIndex, exerptLength);
	
	// UE_LOG(LogTemp, Warning, TEXT("Size: %i"), exerptLength);
	// UE_LOG(LogTemp, Warning, TEXT("Index: %i"), endIndex);
	// UE_LOG(LogTemp, Warning, TEXT("Total size: %i"), text.Len());
	UE_LOG(LogTemp, Warning, TEXT("Exerpt: %s"), *exerpt);
	partitionedOutput.Add(exerpt);
	
	return partitionedOutput;
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



