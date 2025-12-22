// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class INVENTORY_API SSInteractWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSInteractWidget)
	{}
		SLATE_ATTRIBUTE(const FSlateBrush*, BackgroundBrush)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	TAttribute<const FSlateBrush*> BackgroundBrush;
};
