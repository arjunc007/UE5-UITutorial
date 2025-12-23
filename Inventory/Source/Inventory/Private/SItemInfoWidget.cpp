// Fill out your copyright notice in the Description page of Project Settings.


#include "SItemInfoWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SItemInfoWidget::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(1000.f)
		.HeightOverride(300.f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SOverlay)
				+SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(SImage)
					.Image(FCoreStyle::Get().GetBrush("WhiteBrush"))
					.ColorAndOpacity(FLinearColor(0.f, 0.f, 0.f, 0.1f))
				]
				+ SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(5)
				[
					SNew(SImage)
					.Image(FCoreStyle::Get().GetBrush("WhiteBrush"))
					.ColorAndOpacity(FLinearColor(0.f, 0.f, 0.f, 0.3f))
				]
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(20.f, 5.f, 0.f, 0.f)
				[
					SNew(STextBlock)
					.Text(InArgs._ItemName)
					.ColorAndOpacity(FLinearColor(1.f, 1., 1.f, 0.8f))
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(20.f, 0.f, 250.f, 0.f)
				[
					SNew(SBorder)
					.ColorAndOpacity(FLinearColor(1.f, 1., 1.f, 0.3f))
				]
				+ SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.Padding(20.f, 0.f, 0.f, 0.f)
					[
						SNew(SImage)
						.Image(InArgs._ItemTypeImage)
					]
					+ SHorizontalBox::Slot()
					[
						SNew(SBox)
						.WidthOverride(70.f)
						.HeightOverride(50.f)
						.Padding(10.f, 0.f, 0.f, 5.f)
						[
							SNew(SBorder)
							[
								SNew(SBorder)
								[
									SNew(STextBlock)
									.Text(InArgs._CurrentItemPower)
								]
							]
						]
					]
					+ SHorizontalBox::Slot()
					[
						SNew(SImage)
					]
					+ SHorizontalBox::Slot()
					[
						SNew(SBox)
						.WidthOverride(70.f)
						.HeightOverride(50.f)
						.Padding(10.f, 0.f, 0.f, 5.f)
						[
							SNew(SBorder)
							.Padding(1.f)
							[
								SNew(SBorder)
								[
									SNew(STextBlock)
									.Text(InArgs._NewItemPower)
								]
							]
						]
					]
				]
				+SVerticalBox::Slot()
					.Padding(20.f, 0.f, 300.f, 0.f)
					.FillHeight(0.7f)
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
				[
					SNew(STextBlock)
					.Text(InArgs._ItemDescription)
				]
			]
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
