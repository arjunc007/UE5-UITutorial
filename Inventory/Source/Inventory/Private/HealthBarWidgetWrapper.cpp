// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBarWidgetWrapper.h"

TSharedRef<SWidget> UHealthBarWidgetWrapper::RebuildWidget()
{
	SlateHealthBar = SNew(SHealthBarWidget)
		.FullHeartBrush(&FullHeart)
		.HalfHeartBrush(&HalfHeart)
		.EmptyHeartBrush(&EmptyHeart)
        .MaxHearts(GetMaxHealthFromComponent())
        .CurrentHealth(GetHealthFromComponent());

	return SlateHealthBar.ToSharedRef();
}

void UHealthBarWidgetWrapper::SetSourceComponent(UInventoryComponent* InComp)
{
    if (SourceComp.IsValid())
    {
        SourceComp->OnHealthChanged.RemoveDynamic(this, &UHealthBarWidgetWrapper::OnHealthUpdate);
    }

    SourceComp = InComp;

    if (InComp)
    {
        InComp->OnHealthChanged.AddDynamic(this, &UHealthBarWidgetWrapper::OnHealthUpdate);
        OnHealthUpdate(InComp->Health, InComp->MaxHealth);
    }
}

float UHealthBarWidgetWrapper::GetHealthFromComponent() const
{
    if (SourceComp.IsValid())
    {
        return SourceComp->Health;
    }
    return 0.0f;
}

void UHealthBarWidgetWrapper::OnHealthUpdate(float NewHealth, int MaxHearts)
{
    if (SlateHealthBar.IsValid())
    {
        SlateHealthBar->SetHealth(NewHealth, MaxHearts);
    }
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