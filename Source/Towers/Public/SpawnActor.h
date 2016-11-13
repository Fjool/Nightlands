// (C) 2016 Mesomorphic Ltd

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnActor.generated.h"

class AMonsterActor;

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
	
	void SpawnWave();

private:
	UPROPERTY(EditAnywhere, Category = Setup) TSubclassOf<AMonsterActor> MonsterBlueprint = nullptr;
	UPROPERTY(EditAnywhere, Category = Setup) AActor* Exit = nullptr;
	UPROPERTY(EditAnywhere, Category = Setup) float SpawnRate = 1;
	
	float LastSpawnTime = 0.f;
};
