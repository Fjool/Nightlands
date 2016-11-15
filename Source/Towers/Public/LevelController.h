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

	// called by generators when they spawn a new monster, so things are kept track of centrally
	void RegisterMonster(AMonsterActor* Monster);
	void ReachedTarget(AMonsterActor* Monster);

private:
	TArray<AMonsterActor*> Monsters;
	ATowerActor* Tower;	// TODO Enable more towers

	UPROPERTY(EditDefaultsOnly, Category = Setup) TSubclassOf<ATowerActor> TowerBlueprint = nullptr;

};
