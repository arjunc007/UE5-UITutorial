// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBarWidgetWrapper.h"

TSharedRef<SWidget> UHealthBarWidgetWrapper::RebuildWidget()
{
	SlateHealthBar = SNew(SHealthBarWidget)
		.FullHeartBrush(&FullHeart)
		.HalfHeartBrush(&HalfHeart)
		.EmptyHeartBrush(&EmptyHeart)
        .MaxHearts_UObject(this, &UHealthBarWidgetWrapper::GetMaxHealthFromComponent)
        .CurrentHealth_UObject(this, &UHealthBarWidgetWrapper::GetHealthFromComponent);

	return SlateHealthBar.ToSharedRef();
}

void UHealthBarWidgetWrapper::SetSourceComponent(UInventoryComponent* InComp)
{
    SourceComp = InComp;
}

float UHealthBarWidgetWrapper::GetHealthFromComponent() const
{
    if (SourceComp.IsValid())
    {
        return SourceComp->Health;
    }
    return 0.0f;
}

int UHealthBarWidgetWrapper::GetMaxHealthFromComponent() const
{
    if (SourceComp.IsValid())
    {
        return SourceComp->MaxHealth;
    }
    return 0.0f;
}

void UHealthBarWidgetWrapper::ReleaseSlateResources(bool bReleaseChildren)
{
    Super::ReleaseSlateResources(bReleaseChildren);

    // This effectively says: "I am dying, so I am letting go of the Slate widget."
    SlateHealthBar.Reset();
}