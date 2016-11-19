// (C) 2016 Mesomorphic Ltd

#pragma once

#include "GameFramework/Actor.h"
#include "LevelController.generated.h"

class AMonsterActor;
class ATowerActor;

UCLASS()
class TOWERS_API ALevelController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelController();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	void RegisterMonster(AMonsterActor* Monster); // called by generators when they spawn a new monster, so things are kept track of centrally
	void ReachedTarget(  AMonsterActor* Monster); // called by monsters when they reach their target
	void Died(			 AMonsterActor* Monster); // called by monsters when they die

	bool IsTarget(		AMonsterActor* Monster);

private:
	TArray<AMonsterActor*>	Monsters;
	TArray<  ATowerActor*>    Towers;
	
	// Activate tower spawning for level
	void SpawnTowers();

	void RemoveMonsterFromGame(AMonsterActor* Monster);

	UPROPERTY(EditDefaultsOnly, Category = Setup) TSubclassOf<ATowerActor> TowerBlueprint = nullptr;

};
