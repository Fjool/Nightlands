// (C) 2016 Mesomorphic Ltd

#include "Towers.h"
#include "TowerAimingComponent.h"
#include "Tower_Base.h"

// Sets default values for this component's properties
UTowerAimingComponent::UTowerAimingComponent()
{
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UTowerAimingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UTowerAimingComponent::SetBaseReference(UTower_Base* BaseToSet)
{
	Base = BaseToSet;
	if (!Base) { UE_LOG(LogTemp, Warning, TEXT("No base provded to tower")) }
}

void UTowerAimingComponent::AimAt(FVector TargetLocation)
{
	// rotate tower to face target
	RotateBaseTowards(TargetLocation.GetSafeNormal());
}

void UTowerAimingComponent::RotateBaseTowards(FVector AimDirection)
{
	if (!Base) { UE_LOG(LogTemp, Warning, TEXT("NO BASE"))
				 return;
	}
	else
	{	auto  BaseRotator = Base->GetForwardVector().Rotation();
		auto AimAsRotator = AimDirection.Rotation();
		auto DeltaRotator = AimAsRotator - BaseRotator;

		Base->Rotate(DeltaRotator.Yaw);
	}
}