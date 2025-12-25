// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryStructs.h"
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
		SLATE_ARGUMENT(const FSItem*, ItemData)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	void SetItemInfo(const FSItem* Data)
	{
		ItemData = Data;
	}

private:
	TAttribute<const FSlateBrush*> BackgroundBrush;
	const FSItem* ItemData;

	FSlateBrush ItemIconBrush;
};
