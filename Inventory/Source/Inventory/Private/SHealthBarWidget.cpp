// Fill out your copyright notice in the Description page of Project Settings.


#include "SHealthBarWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHealthBarWidget::Construct(const FArguments& InArgs)
{
    ChildSlot
        [
            SNew(SVerticalBox)
                + SVerticalBox::Slot()
                .AutoHeight()
                .HAlign(HAlign_Center)
                [
                    SNew(STextBlock).Text(FText::FromString("Hello from C++ Slate!"))
                ]
                + SVerticalBox::Slot()
                .AutoHeight()
                [
                    SNew(SButton)
                        .OnClicked(this, &SHealthBarWidget::OnButtonClick)
                        [
                            SNew(STextBlock).Text(FText::FromString("Click Me"))
                        ]
                ]
        ];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SHealthBarWidget::OnButtonClick()
{
    UE_LOG(LogTemp, Warning, TEXT("Slate Button was clicked!"));
    return FReply::Handled();
}