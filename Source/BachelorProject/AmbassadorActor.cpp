// Fill out your copyright notice in the Description page of Project Settings.


#include "AmbassadorActor.h"

// Sets default values
AAmbassadorActor::AAmbassadorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAmbassadorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAmbassadorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

