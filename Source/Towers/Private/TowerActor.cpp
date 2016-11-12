// (C) 2016 Mesomorphic Ltd

#include "Towers.h"
#include "TowerActor.h"
#include "MonsterActor.h"

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

	// locate a random monster and hurt it
	TSubclassOf<AMonsterActor> ClassToFind;
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundActors);

	if (FoundActors.Num() == 0)
	{	
		UE_LOG(LogTemp, Warning, TEXT("No monsters found")) 
	}
	else
	{	UE_LOG(LogTemp, Warning, TEXT("Found a monster"))
	//	Cast<AMonsterActor>(FoundActors[0])->Hurt(1);
	}
	

	
}

