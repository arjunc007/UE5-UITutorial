// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBarWidgetWrapper.h"

TSharedRef<SWidget> UHealthBarWidgetWrapper::RebuildWidget()
{
	return SNew(SHealthBarWidget);
}