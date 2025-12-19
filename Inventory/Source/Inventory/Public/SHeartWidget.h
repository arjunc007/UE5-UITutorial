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
	SLATE_BEGIN_ARGS(SHeartWidget) : _HealthPercent(1.0f)
	{}
		SLATE_ATTRIBUTE(float, HealthPercent)
		SLATE_ARGUMENT(const FSlateBrush*, FullHeartBrush)
		SLATE_ARGUMENT(const FSlateBrush*, HalfHeartBrush)
		SLATE_ARGUMENT(const FSlateBrush*, EmptyHeartBrush)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	const FSlateBrush* GetHeartBrush() const;
	TAttribute<float> HealthPercent;
	const FSlateBrush* FullBrush;
	const FSlateBrush* HalfBrush;
	const FSlateBrush* EmptyBrush;
};
