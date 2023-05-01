// Fill out your copyright notice in the Description page of Project Settings.


#include "AlienActor.h"

#include "Engine/SkeletalMesh.h"

// Sets default values
AAlienActor::AAlienActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AAlienActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAlienActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


