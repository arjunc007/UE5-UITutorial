// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "SHealthBarWidget.h"
#include "HealthBarWidgetWrapper.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API UHealthBarWidgetWrapper : public UWidget
{
	GENERATED_BODY()
protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
};
