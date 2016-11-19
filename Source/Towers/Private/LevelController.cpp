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

void ALevelController::SpawnTowers()
{
	int i;

	for (i=0; i < 3; i++)
	{
		auto Location = FVector(100*i, 0, 0);

		Towers.Add(GetWorld()->SpawnActor<ATowerActor>(TowerBlueprint, Location, FRotator(0)));
		Towers[i]->Controller = this;
	}
}

// Called when the game starts or when spawned
void ALevelController::BeginPlay()
{
	Super::BeginPlay();
	SpawnTowers();
}

// Called every frame
void ALevelController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	for (ATowerActor* Tower : Towers)
	{
		// UE_LOG(LogTemp, Warning, TEXT("Tower iterator : %s"), *Tower->GetName())
		if (!Tower->HasTarget() && (Monsters.Num() > 0))
		{	Tower->SetTarget(Monsters[0]);
		}

		Tower->HurtTarget();
	}

}

void ALevelController::RegisterMonster(AMonsterActor* Monster)
{
	Monster->Controller = this;
	Monsters.Add(Monster);
}

void ALevelController::RemoveMonsterFromGame(AMonsterActor* Monster)
{
	// stop any towers that were aiming at it
	for (ATowerActor* Tower : Towers)
	{
		if (Tower->IsTarget(Monster))
		{	Tower->SetTarget(nullptr);
		}
	}

	Monsters.Remove(Monster);
	Monster->Destroy();
}

// Called by a monster when it reaches its target
void ALevelController::ReachedTarget(AMonsterActor* Monster)
{
	RemoveMonsterFromGame(Monster);
}

// Called by a monster when it dies
void ALevelController::Died(AMonsterActor* Monster)
{
	RemoveMonsterFromGame(Monster);
}