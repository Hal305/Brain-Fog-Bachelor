// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TextInputWidget.generated.h"

/**
 * 
 */
UCLASS()
class BACHELORPROJECT_API UTextInputWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
		void SetTextAlignment(class UTextBlock *textblock, int alignment);
	
};
