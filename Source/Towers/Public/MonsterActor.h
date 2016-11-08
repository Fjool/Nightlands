// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ExitActor.h"
#include "GameFramework/Actor.h"
#include "MonsterActor.generated.h"

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

	UPROPERTY(EditAnywhere)
	float Speed = 1.0f;

	// Process the movement of the monster
	void Move();
	bool ReachedTarget();
	void RemoveFromGame();

private:
	UPROPERTY(EditAnywhere)
	AActor* Target = nullptr;

};
