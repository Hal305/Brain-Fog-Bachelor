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
	FAlienData() : maxPhases(correctInputs.Num())
	{}
	
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	// int alienID;
	
	int maxPhases;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	TArray<FText> correctInputs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FText phaseStartOutput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	TArray<FText> specialInputs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	TArray<FText> specialOutputs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FText defaultWrongOutput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FText lastOutput;
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
	
	bool CheckPlayerTextInput(FText playerInput, FText &alienOutput);

	
	UFUNCTION(BlueprintCallable, Meta = (DefaultToSelf))
	void UpdateGameplayText(TArray<FText> newCorrectInputs, FText newPhaseStartOutput,
		TArray<FText> newSpecialInputs, TArray<FText> newSpecialOutputs, FText newDefaultWrongOutput);
};
