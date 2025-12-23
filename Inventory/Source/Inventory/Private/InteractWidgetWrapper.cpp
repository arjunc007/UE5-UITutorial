// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractWidgetWrapper.h"

TSharedRef<SWidget> UInteractWidgetWrapper::RebuildWidget()
{
	SlateInteractWidget = SNew(SSInteractWidget)
		.BackgroundBrush(&BackgroundBrush);

	return SlateInteractWidget.ToSharedRef();
}

void UInteractWidgetWrapper::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	SlateInteractWidget.Reset();
}