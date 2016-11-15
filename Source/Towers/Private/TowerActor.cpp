// (C) 2016 Mesomorphic Ltd

#include "Towers.h"
#include "TowerActor.h"
#include "MonsterActor.h"
#include "TowerAimingComponent.h"
#include "LevelController.h"

// Pass on components to aiming system
void ATowerActor::SetBaseReference( UTower_Base*   BaseToSet){ TowerAimingComponent->SetBaseReference(  BaseToSet); }
void ATowerActor::SetTowerReference(UTower_Tower* TowerToSet){ TowerAimingComponent->SetTowerReference(TowerToSet); }

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
