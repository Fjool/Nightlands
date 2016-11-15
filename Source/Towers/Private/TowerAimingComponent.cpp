// (C) 2016 Mesomorphic Ltd

#include "Towers.h"
#include "TowerAimingComponent.h"
#include "Tower_Base.h"
#include "Tower_Tower.h"
#include "Tower_Turret.h"
#include "Tower_Barrel.h"

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

void UTowerAimingComponent::SetReferences(UTower_Base* BaseToSet, UTower_Tower* TowerToSet, UTower_Turret* TurretToSet, UTower_Barrel* BarrelToSet)
{
	Base   =   BaseToSet;
	Tower  =  TowerToSet; if (  Base) {   Base->SetTowerReference(  TowerToSet); }
	Turret = TurretToSet; if ( Tower) {  Tower->SetTurretReference(TurretToSet); }
	Barrel = BarrelToSet; if (Turret) { Turret->SetBarrelReference(BarrelToSet); }
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
	{	Base->Rotate(AimDirection);
	}
}