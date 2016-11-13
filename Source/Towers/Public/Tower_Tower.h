// (C) 2016 Mesomorphic Ltd

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Tower_Tower.generated.h"

/**
*
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TOWERS_API UTower_Tower : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Rotate(float Difference);

private:

};
