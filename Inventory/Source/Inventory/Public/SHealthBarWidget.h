// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class INVENTORY_API SHealthBarWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SHealthBarWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	FReply OnButtonClick(); // Helper for button interaction
};
