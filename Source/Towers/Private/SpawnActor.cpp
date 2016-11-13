// (C) 2016 Mesomorphic Ltd

#include "Towers.h"
#include "SpawnActor.h"
#include "MonsterActor.h"

// Sets default values
ASpawnActor::ASpawnActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnActor::BeginPlay()
{
	Super::BeginPlay();
}

void ASpawnActor::SpawnWave()
{
	if (!Exit) { UE_LOG(LogTemp, Warning, TEXT("No exit spefied for generator: %s"), *GetName())
				 return; 
			   }
	else
	{
		// boring, single monster, once per second (configurable)
		AMonsterActor* NewMonster = GetWorld()->SpawnActor<AMonsterActor>( MonsterBlueprint
																		 , GetActorLocation()
																		 , GetActorRotation()
																		 );
		NewMonster->SetTarget(Exit);
	}
}

// Called every frame
void ASpawnActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (LastSpawnTime > SpawnRate)
	{
		SpawnWave();
		LastSpawnTime = 0;
	}

	LastSpawnTime += DeltaTime;
}