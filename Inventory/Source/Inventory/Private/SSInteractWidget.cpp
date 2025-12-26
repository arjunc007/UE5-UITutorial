// Fill out your copyright notice in the Description page of Project Settings.

#include "SSInteractWidget.h"
#include "SItemInfoWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/SCanvas.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSInteractWidget::Construct(const FArguments& InArgs)
{
	BackgroundBrush = InArgs._BackgroundBrush;
	ItemTypeBrush = InArgs._ItemTypeBrush;

	if (InArgs._ItemData)
	{
		ItemData = InArgs._ItemData;
	}
	else
	{
		FSItem* item = new FSItem();
		item->Name = FText::FromString("Item Name");
		item->Description = FText::FromString("Item Description"); 
		item->Power = 11.f;
		ItemData = item;
	}

	TSharedPtr<SItemInfoWidget> Itemfo = SNew(SItemInfoWidget)
		.ItemName(ItemData->Name)
		.ItemTypeImage(ItemTypeBrush)
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
					.Padding(12.f, 0.f, 0.f, 0.f)
					.HAlign(HAlign_Left)
					.VAlign(VAlign_Center)
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
