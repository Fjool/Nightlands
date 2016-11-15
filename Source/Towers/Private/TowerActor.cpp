// (C) 2016 Mesomorphic Ltd

#include "Towers.h"
#include "TowerActor.h"
#include "MonsterActor.h"
#include "TowerAimingComponent.h"
#include "LevelController.h"

// Pass on components to aiming system
void ATowerActor::SetReferences(UTower_Base* BaseToSet, UTower_Tower* TowerToSet, UTower_Turret* TurretToSet, UTower_Barrel* BarrelToSet)
{
	if (TowerAimingComponent)
	{	TowerAimingComponent->SetReferences(  BaseToSet
										   , TowerToSet
										   , TurretToSet
										   , BarrelToSet
										   );
	}
	else { UE_LOG(LogTemp, Warning, TEXT("No TowerAimingComponent")) }
}

// Sets default values
ATowerActor::ATowerActor()
{
	PrimaryActorTick.bCanEverTick = true;
	TowerAimingComponent = CreateDefaultSubobject<UTowerAimingComponent>(FName("Aiming Component"));
}

// Receive instructions on which monster to attack
void ATowerActor::SetTarget(AMonsterActor* Monster) {        Target  = Monster; }
bool ATowerActor::HasTarget(                      ) { return Target != nullptr; }

// Called when the game starts or when spawned
void ATowerActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATowerActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	// try to hurt our target
	if (Target) 
	{	
		TowerAimingComponent->AimAt(Target->GetActorLocation());		
	}
}
