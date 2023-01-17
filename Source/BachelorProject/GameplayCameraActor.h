// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "GameplayCameraActor.generated.h"

/**
 * 
 */
UCLASS()
class BACHELORPROJECT_API AGameplayCameraActor : public ACameraActor
{
	GENERATED_BODY()

public:
	AGameplayCameraActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
}; 
