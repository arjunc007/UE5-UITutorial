// Fill out your copyright notice in the Description page of Project Settings.


#include "HeartWidgetWrapper.h"

TSharedRef<SWidget> UHeartWidgetWrapper::RebuildWidget()
{
    MySlateHeart = SNew(SHeartWidget)
        .FullHeartBrush(&FullHeart)
        .HalfHeartBrush(&HalfHeart)
        .EmptyHeartBrush(&EmptyHeart)
        // Bind the float using a Lambda or direct function
        .HealthPercent_UObject(this, &UHeartWidgetWrapper::GetHealthPercent);

    return MySlateHeart.ToSharedRef();
}