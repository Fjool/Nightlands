// (C) 2016 Mesomorphic Ltd

#include "Towers.h"
#include "LevelController.h"
#include "MonsterActor.h"
#include "TowerActor.h"

// LevelController is responsible for:
//  - Removing dead monsters
//	- Starting/Stopping generators
//	- Instructing towers to attack

// Sets default values
ALevelController::ALevelController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALevelController::BeginPlay()
{
	Super::BeginPlay();

	// one lonely tower
	Tower = GetWorld()->SpawnActor<ATowerActor>(TowerBlueprint, FVector(0), FRotator(0));
	Tower->Controller = this;
}

// Called every frame
void ALevelController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (!Tower->HasTarget())
	{
		if (Monsters.Num() > 0)
		{	Tower->SetTarget(Monsters[0]);
		}
	}
}

void ALevelController::RegisterMonster(AMonsterActor* Monster)
{
	Monster->Controller = this;
	Monsters.Add(Monster);
}

// Called by a monster when it reaches its target
void ALevelController::ReachedTarget(AMonsterActor* Monster)
{
	Monsters.Remove(Monster);
	Monster->Destroy();		
}