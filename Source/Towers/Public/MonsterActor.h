// (C) 2016 Mesomorphic Ltd

#pragma once

#include "GameFramework/Actor.h"
#include "MonsterActor.generated.h"

class ALevelController;

UCLASS()
class TOWERS_API AMonsterActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMonsterActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Process the movement of the monster
	void Move();

	// Receive damage
	void Hurt(float damage);
	void SetTarget(AActor* inTarget);

	UPROPERTY(EditAnywhere) ALevelController* Controller = nullptr;

private:
	UPROPERTY(EditAnywhere) AActor* Target = nullptr;
	UPROPERTY(EditAnywhere) float Speed  = 1;
	UPROPERTY(EditAnywhere) float Health = 100;

	bool ReachedTarget();

};
