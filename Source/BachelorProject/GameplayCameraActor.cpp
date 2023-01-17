// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayCameraActor.h"

AGameplayCameraActor::AGameplayCameraActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameplayCameraActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGameplayCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}