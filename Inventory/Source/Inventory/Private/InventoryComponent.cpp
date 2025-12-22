// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"
#include "HealthBarContainer.h"
#include "Kismet/GameplayStatics.h"

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
		
		if (InteractWidget)
		{
			InteractWidget->AddToViewport();
		}
	}

	APawn* OwningPawn = Cast<APawn>(GetOwner());

	if (OwningPawn && OwningPawn->IsLocallyControlled())
	{
		UInputComponent* InputComp = OwningPawn->FindComponentByClass<UInputComponent>();

		if (InputComp)
		{
			InputComp->BindKey(EKeys::N, IE_Pressed, this, &UInventoryComponent::OnDebugDamage);

			InputComp->BindKey(EKeys::M, IE_Pressed, this, &UInventoryComponent::OnDebugHeal);

			UE_LOG(LogTemp, Log, TEXT("UI Component: Debug Keys N/M Bound Successfully"));
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

// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

