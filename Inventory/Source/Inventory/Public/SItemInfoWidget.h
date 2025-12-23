// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class INVENTORY_API SItemInfoWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SItemInfoWidget)
	{}
		SLATE_ATTRIBUTE(FText, ItemName)
		SLATE_ATTRIBUTE(const FSlateBrush*, ItemTypeImage)
		SLATE_ATTRIBUTE(FText, CurrentItemPower)
		SLATE_ATTRIBUTE(FText, NewItemPower)
		SLATE_ATTRIBUTE(FText, ItemDescription)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
};
