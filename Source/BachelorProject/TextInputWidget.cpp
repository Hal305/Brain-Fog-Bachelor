// Fill out your copyright notice in the Description page of Project Settings.


#include "TextInputWidget.h"
#include "Components/TextBlock.h"

void UTextInputWidget::SetTextAlignment(UTextBlock *textblock, int alignment)
{
	switch (alignment)
	{
	case 0:
		textblock->SetJustification(ETextJustify::Left);
		break;
	case 1:
		textblock->SetJustification(ETextJustify::Right);
	}
}
