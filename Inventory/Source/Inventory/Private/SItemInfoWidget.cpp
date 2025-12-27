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
					.Font(FCoreStyle::GetDefaultFontStyle("BoldItalic", 24))
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
					.FillHeight(0.3f)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Center)
					.Padding(20.f, 0.f, 0.f, 0.f)
					[
						SNew(SImage)
						.Image(InArgs._ItemTypeImage)
					]
					+ SHorizontalBox::Slot()
					.Padding(10.f, 0.f, 0.f, 5.f)
					.AutoWidth()
					[
						SNew(SBox)
						.WidthOverride(70.f)
						.HeightOverride(50.f)
						[
							SNew(SBorder)
							[
								SNew(SBorder)
								.HAlign(HAlign_Center)
								.VAlign(VAlign_Center)
								[
									SNew(STextBlock)
									.Text(InArgs._CurrentItemPower)
									.Font(FCoreStyle::GetDefaultFontStyle("Italic", 20))
								]
							]
						]
					]
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.Padding(30.f, 0.f, 0.f, 0.f)
					[
						SNew(SImage)
						.Image(FCoreStyle::Get().GetBrush("WhiteBrush"))
						.ColorAndOpacity(FLinearColor(1.f, 1.f, 1.f, 1.f))
					]
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.Padding(10.f, 0.f, 0.f, 5.f)
					[
						SNew(SBox)
						.WidthOverride(70.f)
						.HeightOverride(50.f)
						[
							SNew(SBorder)
							.Padding(1.f)
							[
								SNew(SBorder)
								.HAlign(HAlign_Center)
								.VAlign(VAlign_Center)
								[
									SNew(STextBlock)
									.Text(InArgs._NewItemPower)
									.Font(FCoreStyle::GetDefaultFontStyle("Italic", 20))
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
					.Font(FCoreStyle::GetDefaultFontStyle("Bold", 24))
					.AutoWrapText(true)
				]
			]
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
