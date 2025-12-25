// Fill out your copyright notice in the Description page of Project Settings.

#include "SSInteractWidget.h"
#include "SItemInfoWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/SCanvas.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSInteractWidget::Construct(const FArguments& InArgs)
{
	BackgroundBrush = InArgs._BackgroundBrush;
	ItemData = InArgs._ItemData;

	ItemIconBrush.ImageSize = FVector2D(100.f, 100.f);
	ItemIconBrush.DrawAs = ESlateBrushDrawType::Image;
	ItemIconBrush.TintColor = FLinearColor::White;

	if (ItemData->Thumbnail)
	{
		ItemIconBrush.SetResourceObject(ItemData->Thumbnail);
	}
	else
	{
		ItemIconBrush.SetResourceObject(nullptr);
		ItemIconBrush.TintColor = FLinearColor::Transparent;
	}

	TSharedPtr<SItemInfoWidget> Itemfo = SNew(SItemInfoWidget)
		.ItemName(ItemData->Name)
		.ItemTypeImage(&ItemIconBrush)
		.CurrentItemPower(ItemData->Name)
		.NewItemPower(FText::AsNumber(ItemData->Power))
		.ItemDescription(ItemData->Description);

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Bottom)
		.Padding(0.f, 0.f, 100.f, 100.f)
		[
			SNew(SBox)
			.WidthOverride(250.f)
			.HeightOverride(80.f)
			[
				SNew(SOverlay)
				+ SOverlay::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
				[
					SNew(SImage)
						.Image(BackgroundBrush.Get())
				]
				+ SOverlay::Slot()
				[
					SNew(SButton)
				]
				+ SOverlay::Slot()
				.Padding(26.f, 0.f, 0.f, 0.f)
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(FText::FromString("E"))
				]
				+ SOverlay::Slot()
				.Padding(90.f, 0.f, 0.f, 0.f)
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(FText::FromString("Take"))
				]
			]
		]
		+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Bottom)
		.Padding(0.f, 0.f, -100.f, 200.f)
		[
			Itemfo.ToSharedRef()
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
