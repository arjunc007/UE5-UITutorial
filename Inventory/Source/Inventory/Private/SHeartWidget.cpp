// Fill out your copyright notice in the Description page of Project Settings.


#include "SHeartWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHeartWidget::Construct(const FArguments& InArgs)
{
    CurrentBrush = InArgs._CurrentBrush;
	
	ChildSlot
	[
		SNew(SBox)
		.HeightOverride(30.f)
		.WidthOverride(30.f)
		.Padding(2)
		[
			SNew(SImage)
			.Image(CurrentBrush.Get())

		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION