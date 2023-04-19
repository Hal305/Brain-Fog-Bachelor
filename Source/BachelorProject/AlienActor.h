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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FText alienID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	int maxPhases;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	TArray<FText> correctInputs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FText correctOutput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	TArray<FText> specialInputs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	TArray<FText> specialOutputs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FText defaultWrongOutput;
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

	FAlienData gameData;
	int phaseCount = 1;
	
	bool CheckPlayerTextInput(FText playerInput, FText &alienOutput);

	
	UFUNCTION(BlueprintCallable, Meta = (DefaultToSelf))
	void UpdateGameplayText(TArray<FText> newCorrectInputs, FText newCorrectOutput,
		TArray<FText> newSpecialInputs, TArray<FText> newSpecialOutputs, FText newDefaultWrongOutput);
};
