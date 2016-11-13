// (C) 2016 Mesomorphic Ltd

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Tower_Base.generated.h"

class UTower_Tower;

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TOWERS_API UTower_Base : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Rotate(FVector Direction);
	void SetTowerReference(UTower_Tower* TowerToSet);

private:
	UPROPERTY(EditAnywhere, Category = Setup) float MaxDegreesPerSecond = 20; // TODO Find sensible value
	
	UTower_Tower* Tower = nullptr;

};
