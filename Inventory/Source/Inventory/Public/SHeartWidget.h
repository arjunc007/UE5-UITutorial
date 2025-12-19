// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class INVENTORY_API SHeartWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SHeartWidget)
	{}
		SLATE_ATTRIBUTE(const FSlateBrush*, CurrentBrush)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	TAttribute<const FSlateBrush*> CurrentBrush;
};
