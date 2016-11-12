// (C) 2016 Mesomorphic Ltd

#include "Towers.h"
#include "SpawnActor.h"


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
	
}

// Called every frame
void ASpawnActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	float WaveTime = 10.f;	// seconds

	if (LastSpawnTime > WaveTime)
	{
		SpawnWave();
		LastSpawnTime = 0;
	}

	LastSpawnTime += DeltaTime;
}

