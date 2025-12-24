// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"
#include "HealthBarContainer.h"
#include "InteractWidgetWrapper.h"
#include "Item.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	controller->SetInputMode(FInputModeGameOnly());

	if (HealthBarClassToSpawn && IsValid(GetOwner()))
	{
		HealthBarWidget = CreateWidget<UUserWidget>(GetWorld(), HealthBarClassToSpawn);

		if (HealthBarWidget)
		{
			UHealthBarContainer* HealthBar = Cast<UHealthBarContainer>(HealthBarWidget);
			HealthBar->InitializeHealthBar(this);
			HealthBarWidget->SetPositionInViewport(FVector2D(5, 5));
			HealthBarWidget->AddToViewport();
		}
	}

	if (InteractClassToSpawn)
	{
		InteractWidget = CreateWidget<UUserWidget>(GetWorld(), InteractClassToSpawn);
	}

	APawn* OwningPawn = Cast<APawn>(GetOwner());

	if (OwningPawn && OwningPawn->IsLocallyControlled())
	{
		UInputComponent* InputComp = OwningPawn->FindComponentByClass<UInputComponent>();

		if (InputComp)
		{
			InputComp->BindKey(EKeys::N, IE_Pressed, this, &UInventoryComponent::OnDebugDamage);

			InputComp->BindKey(EKeys::M, IE_Pressed, this, &UInventoryComponent::OnDebugHeal);
		}
	}
}

void UInventoryComponent::OnDebugHeal()
{
	ModifyHealth(0.5f);
}
void UInventoryComponent::OnDebugDamage()
{
	ModifyHealth(-0.5f);
}

void UInventoryComponent::ModifyHealth(float Delta)
{
	Health = FMath::Clamp(Health + Delta, 0.0f, (float)MaxHealth);

	if (OnHealthChanged.IsBound())
	{
		OnHealthChanged.Broadcast(Health, MaxHealth);
	}
}

// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	bool showInteract = false;
	FHitResult hitResult;
	if (TraceItemToPickup(hitResult))
	{
		AItem* item = Cast<AItem>(hitResult.GetActor());
		if (item)
		{
			showInteract = true;
		}
	}

	if (showInteract && InteractWidget)
	{
		UInteractWidgetWrapper* interactWidget = Cast<UInteractWidgetWrapper>(InteractWidget);
		InteractWidget->AddToViewport();
	}
	else
	{
		InteractWidget->RemoveFromParent();
	}
}

bool UInventoryComponent::TraceItemToPickup(FHitResult& hitResult) const
{
	AActor* Owner = GetOwner();
	TArray<AActor*> actorsToIgnore;
	FVector start = Owner->GetActorLocation() - FVector(0.f, 0.f, 60.f);
	FVector end = start + Owner->GetActorForwardVector() * 120.f;
	auto channel = UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_Visibility);
	auto isHit = UKismetSystemLibrary::SphereTraceSingle(
	this,
	start,
	end,
	30.f,
	channel,
	false,
	actorsToIgnore,
	EDrawDebugTrace::Type::ForOneFrame,
	hitResult,
	true);
	return isHit;
}