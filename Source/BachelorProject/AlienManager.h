// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AlienManager.generated.h"

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

	UPROPERTY(EditAnywhere, BluePrintReadWrite)
		FText mySpecialInput;
	UPROPERTY(EditAnywhere, BluePrintReadWrite)
		FText mySpecialOutput;

	UFUNCTION(BlueprintCallable, Meta = (DefaultToSelf))
		void ManageAlien();

	void testFunction();
};
