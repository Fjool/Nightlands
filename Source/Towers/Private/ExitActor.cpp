// (C) 2016 Mesomorphic Ltd

#include "Towers.h"
#include "ExitActor.h"

// Sets default values
AExitActor::AExitActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AExitActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExitActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

