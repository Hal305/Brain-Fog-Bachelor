// Fill out your copyright notice in the Description page of Project Settings.


#include "AlienManager.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"

// Sets default values
AAlienManager::AAlienManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAlienManager::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AAlienManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAlienManager::testFunction()
{
	
}

void AAlienManager::ManageAlien()
{
	mySpecialInput = mySpecialOutput.FromString("blah");
}

