// (C) 2016 Mesomorphic Ltd

#include "Towers.h"
#include "TowerActor.h"
#include "MonsterActor.h"
#include "TowerAimingComponent.h"

// Pass on components to aiming system
void ATowerActor::SetBaseReference( UTower_Base*   BaseToSet){ TowerAimingComponent->SetBaseReference(  BaseToSet); }
void ATowerActor::SetTowerReference(UTower_Tower* TowerToSet){ TowerAimingComponent->SetTowerReference(TowerToSet); }

// Sets default values
ATowerActor::ATowerActor()
{
	PrimaryActorTick.bCanEverTick = true;
	TowerAimingComponent = CreateDefaultSubobject<UTowerAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATowerActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATowerActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	// locate closest monster and hurt it
	if (Target) 
	{	
		TowerAimingComponent->AimAt(Target->GetActorLocation());		
	}
}

