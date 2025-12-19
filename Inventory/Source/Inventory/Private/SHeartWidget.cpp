// Fill out your copyright notice in the Description page of Project Settings.


#include "SHeartWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHeartWidget::Construct(const FArguments& InArgs)
{
	HealthPercent = InArgs._HealthPercent;
    FullBrush = InArgs._FullHeartBrush;
    HalfBrush = InArgs._HalfHeartBrush;
    EmptyBrush = InArgs._EmptyHeartBrush;

	ChildSlot
	[
		SNew(SBox)
		.HeightOverride(30.f)
		.WidthOverride(30.f)
		[
			SNew(SImage)
			.Image(this, &SHeartWidget::GetHeartBrush)
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

const FSlateBrush* SHeartWidget::GetHeartBrush() const
{
    const float Health = HealthPercent.Get();

    if (Health > 0.75f)
    {
        return FullBrush;
    }
    else if (Health > 0.25f)
    {
        return HalfBrush;
    }
    else
    {
        return EmptyBrush;
    }
}