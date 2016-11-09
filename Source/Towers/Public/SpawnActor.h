// (C) 2016 Mesomorphic Ltd

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnActor.generated.h"

UCLASS()
class TOWERS_API ASpawnActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	void ASpawnActor::SpawnWave();

private:
	float LastSpawnTime = 0.f;

};
