// Fill out your copyright notice in the Description page of Project Settings.


#include "SHealthBarWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHealthBarWidget::Construct(const FArguments& InArgs)
{
    if (WrapBox)
    {
        WrapBox->ClearChildren();
    }
    else
    {
        WrapBox = SNew(SWrapBox);
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
                    SAssignNew(WrapBox, SWrapBox)
                ]
            ]
        ];

    WrapBox->AddSlot()
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Fill);
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SHealthBarWidget::OnButtonClick()
{
    UE_LOG(LogTemp, Warning, TEXT("Slate Button was clicked!"));
    return FReply::Handled();
}