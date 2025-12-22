// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractWidgetWrapper.h"

TSharedRef<SWidget> UInteractWidgetWrapper::RebuildWidget()
{
	SlateInteractWidget = SNew(SSInteractWidget)
		.BackgroundBrush(&BackgroundBrush);

	//TSharedRef<SWidget> RootWidget = SNew(SOverlay)
	//	+ SOverlay::Slot()
	//	.HAlign(HAlign_Fill)
	//	.VAlign(VAlign_Fill)
	//	[
	//		SlateInteractWidget.ToSharedRef()
	//	];

	return SlateInteractWidget.ToSharedRef();
}

void UInteractWidgetWrapper::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	SlateInteractWidget.Reset();
}