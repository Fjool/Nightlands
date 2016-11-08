// (C) 2016 Mesomorphic Ltd

#pragma once

#include "GameFramework/Actor.h"
#include "TowerActor.generated.h"

UCLASS()
class TOWERS_API ATowerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATowerActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


	
};
