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
	playerInput =  playerInput.TrimEnd();
	for (int i = 0; i < alienData.correctInputs.Num(); i++)
	{
		if (playerInput.ToLower().Equals(alienData.correctInputs[i].ToLower()))
		{
			alienOutput = alienData.correctOutput;
			phaseCount++;
			AnimToPlay = 1;
			return true;
		}
	}
	for (int i = 0; i < alienData.specialInputs.Num(); i++)
	{
		if (playerInput.ToLower().Equals(alienData.specialInputs[i].ToLower()))
		{
			alienOutput = alienData.specialOutputs[i];
			AnimToPlay = 3;
			CurrentSpecial = i;
			return false;
		}
	}
	alienOutput = alienData.defaultWrongOutput;
	AnimToPlay = 2;
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

	//Capitalising every first letter in the text input
	// if (!newString.IsEmpty())
	// {
	// 	//This check might cause crashes, comment it out or remove it if so.
	// 	newString = newString.ToLower();
	// 	TCHAR c = newString[0];
	// 	FString upperString = " "; upperString[0] = c; upperString = upperString.ToUpper();
	// 	newString[0] = upperString[0];
	// }	//Alternatively consider capitalising every letter.
	newString = newString.ToUpper();
	
	FText out = FText::FromString(newString);
	//UE_LOG(LogTemp, Warning, TEXT("Exerpt: %s"), *out.ToString());
	return out;
}

TArray<FString> AAlienManager::SplitOutput(FString text)
{
	TArray<FString> outputSnippets;
	int32 startIndex = 0, endIndex = 0, snippetLength = text.Len();
	while(text.Contains("\n"))
	{	//Risky c++ while loop, handle code with care
		endIndex = text.Find("\n");
		FString snippet = text.Left(endIndex).TrimChar('\r').TrimChar('\n');
		UE_LOG(LogTemp, Warning, TEXT(": %s"), *snippet);
		snippet.TrimStartAndEnd().Shrink();
		outputSnippets.Add(snippet);
		text = text.RightChop(endIndex).TrimStartAndEnd();
		//UE_LOG(LogTemp, Warning, TEXT(": %s"), *text);
		//This check should guarantee the loop to always exit
		if(!text.Contains("\n") || !text.Contains("\""))
			break;
	}
	text.TrimStartAndEnd().Shrink();
	text = text.TrimChar('\r').TrimChar('\n');
		UE_LOG(LogTemp, Warning, TEXT(": %s"), *text);
	 	outputSnippets.Add(text);

	//Maybe I didn't have to write my own splitting function after all...
	//Is an O(N^2), might be less resource efficient, but works perfectly
	//This is currently called in the HUD blueprint, in UpdateChatLogALien
	//text.ParseIntoArrayLines(outputSnippets, true);
	
	// for (int i = 0; i< outputSnippets.Num(); i++)
	// 	UE_LOG(LogTemp, Warning, TEXT(": %s"), *outputSnippets[i]);
		
	return outputSnippets;
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



