// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AlienActor.generated.h"

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	TArray<FText> correctInputs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	int numberOfCorrectInputs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	TArray<FText> specialInputs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	int numberOfSpecialInputs;

	FText outPut;
	FText testCorrect = testCorrect.FromString("yopopo");
	
	bool CheckPlayerTextInput(FText playerInput, FText &alienOutput);

	int phaseCount;
};
