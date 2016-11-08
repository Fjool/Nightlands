// (C) 2016 Mesomorphic Ltd

#include "Towers.h"
#include "TowerActor.h"

// Sets default values
ATowerActor::ATowerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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
}

