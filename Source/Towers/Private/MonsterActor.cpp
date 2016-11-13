// (C) 2016 Mesomorphic Ltd

#include "Towers.h"
#include "MonsterActor.h"
#include "ExitActor.h"

// Sets default values
AMonsterActor::AMonsterActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMonsterActor::BeginPlay()
{
	Super::BeginPlay();

}

void AMonsterActor::Move()
{
	if (Target == nullptr) { UE_LOG(LogTemp, Error, TEXT("No target specified")) }
	else
	{
		// Calculate difference between where we are now and the exits and move Speed units towards it
		FVector OurLocation = GetActorLocation();

		SetActorLocation( OurLocation + (Target->GetActorLocation() - OurLocation).GetSafeNormal() * Speed
						, false
						);
	}
}
void AMonsterActor::SetTarget(AActor* inTarget)
{
	Target = inTarget;
}

bool AMonsterActor::ReachedTarget()
{
	return false;
}

void AMonsterActor::RemoveFromGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Goodbye cruel world..."))
}

// Called every frame
void AMonsterActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	Move();

	if (ReachedTarget())
	{
		RemoveFromGame();
	}
}

void AMonsterActor::Hurt(float damage)
{
	Health -= damage;
}