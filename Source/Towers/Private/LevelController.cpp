// (C) 2016 Mesomorphic Ltd

#include "Towers.h"
#include "LevelController.h"
#include "MonsterActor.h"

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
}

// Called every frame
void ALevelController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void ALevelController::RegisterMonster(AMonsterActor* Monster)
{
	Monster->Controller = this;
	// TODO Store a list of monsters
}

void ALevelController::ReachedTarget(AMonsterActor* Monster)
{
	UE_LOG(LogTemp, Warning, TEXT("Monster reached target : %s"), *Monster->GetName())
	Monster->Destroy();
}