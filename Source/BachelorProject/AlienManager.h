// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "AlienManager.generated.h"


USTRUCT(BlueprintType)
struct FAlienList : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	FAlienList() {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AlienData")
	TSoftObjectPtr<USkeletalMesh> alienMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AlienData")
	TSoftObjectPtr<UAnimBlueprint> alienAnimBP;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AlienData")
	TSoftObjectPtr<UDataTable> alienData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AlienData")
	FString startingOutput;
	
};
	
UCLASS()
class BACHELORPROJECT_API AAlienManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAlienManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BluePrintReadWrite)
	FAlienList aliens;
	
	UFUNCTION(BlueprintCallable, Meta = (DefaultToSelf))
	void SetAlien(FAlienList aliensIn);

	UFUNCTION(BlueprintCallable, Meta = (DefaultToSelf))
	void SetupLevelPhase(TArray<FString> newCorrectInputs, FString newCorrectOutput,
	TArray<FString> newSpecialInputs, TArray<FString> newSpecialOutputs, FString newDefaultWrongOutput);
	
	UPROPERTY(BluePrintReadWrite)
		FString alienTextOutput;

	UFUNCTION(BlueprintCallable, Meta = (DefaultToSelf))
		FString ManageAlien(FString playerInput);
	
	UPROPERTY(EditAnywhere, BluePrintReadWrite)
		class AAlienActor* currentAlien;
	AActor* alienClone;

	UPROPERTY(BlueprintReadWrite)
	bool phaseChange = false;
	
	UPROPERTY(BlueprintReadWrite)
	bool levelDone = false;
};
