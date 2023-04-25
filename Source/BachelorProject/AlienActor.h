// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "AlienActor.generated.h"

USTRUCT(BlueprintType)
struct FAlienData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	FAlienData() : maxPhases(0)
	{}
	
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	// int alienID;
	
	int maxPhases;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	TArray<FString> correctInputs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FString phaseStartOutput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	TArray<FString> specialInputs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	TArray<FString> specialOutputs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FString defaultWrongOutput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FString lastOutput;
};

UCLASS()
class BACHELORPROJECT_API AAlienActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAlienActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FAlienData gameplayData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	int phaseCount = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	int maxPhases;
	
	bool CheckPlayerTextInput(FString playerInput, FString &alienOutput);

	
	UFUNCTION(BlueprintCallable, Meta = (DefaultToSelf))
	void UpdateGameplayText(TArray<FString> newCorrectInputs, FString newPhaseStartOutput,
		TArray<FString> newSpecialInputs, TArray<FString> newSpecialOutputs, FString newDefaultWrongOutput, FString lastOutput);
};
