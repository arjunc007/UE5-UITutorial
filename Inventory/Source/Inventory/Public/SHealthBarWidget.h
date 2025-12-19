// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "Widgets/Layout/SWrapBox.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class INVENTORY_API SHealthBarWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SHealthBarWidget) : _CurrentHealth(20.0f), _MaxHearts(20)
	{}
		SLATE_ATTRIBUTE(float, CurrentHealth)
		SLATE_ATTRIBUTE(int, MaxHearts)
		SLATE_ARGUMENT(const FSlateBrush*, FullHeartBrush)
		SLATE_ARGUMENT(const FSlateBrush*, HalfHeartBrush)
		SLATE_ARGUMENT(const FSlateBrush*, EmptyHeartBrush)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	TSharedPtr<SWrapBox> WrapBox;
private:
	const FSlateBrush* GetBrushForHeartIndex(int HeartIndex) const;

	TAttribute<float> CurrentHealth;
	TAttribute<int> MaxHealth;
	const FSlateBrush* FullBrush;
	const FSlateBrush* HalfBrush;
	const FSlateBrush* EmptyBrush;
};
