// (C) 2016 Mesomorphic Ltd

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Tower_Base.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TOWERS_API UTower_Base : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Rotate(float Direction);

private:
	UPROPERTY(EditAnywhere, Category = Setup) float RotationSpeed		= 100; // TODO Find sensible value
	UPROPERTY(EditAnywhere, Category = Setup) float MaxDegreesPerSecond =  20; // TODO Find sensible value
};
