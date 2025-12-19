// Fill out your copyright notice in the Description page of Project Settings.


#include "SHealthBarWidget.h"
#include "SHeartWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHealthBarWidget::Construct(const FArguments& InArgs)
{
    CurrentHealth = InArgs._CurrentHealth;
    FullBrush = InArgs._FullHeartBrush;
    HalfBrush = InArgs._HalfHeartBrush;
    EmptyBrush = InArgs._EmptyHeartBrush;

    if (WrapBox)
    {
        WrapBox->ClearChildren();
    }
    else
    {
        WrapBox = SNew(SWrapBox)
            .UseAllottedSize(true)
            .HAlign(HAlign_Left)
            .Orientation(Orient_Horizontal);
    }

    for (int i = 0; i < InArgs._MaxHearts.Get(); i++)
    {
        WrapBox->AddSlot()
        [
            SNew(SHeartWidget)
            .CurrentBrush_Lambda([this, i]()
            {
                return GetBrushForHeartIndex(i);
            })
        ];
    }

    ChildSlot
        [
            SNew(SBox)
            .WidthOverride(600)
            .HeightOverride(80)
            [
                SNew(SOverlay)
                + SOverlay::Slot()
                .HAlign(HAlign_Fill)
                .VAlign(VAlign_Fill)
                [
                    WrapBox.ToSharedRef()
                ]
            ]
        ];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

const FSlateBrush* SHealthBarWidget::GetBrushForHeartIndex(int HeartIndex) const
{
    float Health = CurrentHealth.Get();

    float HeartValue = Health - (float)HeartIndex;

    if (HeartValue >= 1.f)
    {
        return FullBrush;
    }
    else if (HeartValue >= 0.5f)
    {
        return HalfBrush;
    }

    return EmptyBrush;
}