// Fill out your copyright notice in the Description page of Project Settings.


#include "SHealthBarWidget.h"
#include "SHeartWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHealthBarWidget::Construct(const FArguments& InArgs)
{
    CurrentHealth = InArgs._CurrentHealth;
    MaxHearts = InArgs._MaxHearts;
    FullBrush = InArgs._FullHeartBrush;
    HalfBrush = InArgs._HalfHeartBrush;
    EmptyBrush = InArgs._EmptyHeartBrush;

    RefreshHearts();

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

void SHealthBarWidget::RefreshHearts()
{
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

    for (int i = 0; i < MaxHearts; i++)
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
}

void SHealthBarWidget::SetHealth(float NewHealth, int NewMaxHealth)
{
    if (NewHealth != CurrentHealth || NewMaxHealth != MaxHearts)
    {
        CurrentHealth = NewHealth;
        MaxHearts = NewMaxHealth;
        RefreshHearts();
    }

    Invalidate(EInvalidateWidgetReason::Paint);
}

const FSlateBrush* SHealthBarWidget::GetBrushForHeartIndex(int HeartIndex) const
{
    float Health = CurrentHealth;

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