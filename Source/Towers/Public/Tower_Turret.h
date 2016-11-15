// (C) 2016 Mesomorphic Ltd

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Tower_Turret.generated.h"

class UTower_Barrel;

UCLASS(meta = (BlueprintSpawnableComponent))
class TOWERS_API UTower_Turret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void SetBarrelReference(UTower_Barrel* BarrelToSet);

private:
	UTower_Barrel* Barrel = nullptr;
	
	
};
