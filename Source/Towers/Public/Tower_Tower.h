// (C) 2016 Mesomorphic Ltd

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Tower_Tower.generated.h"

class UTower_Turret;

/**
* Defines the tower portion of the overall tower actor 
* TODO De-overload the use of the word 'Tower' 
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TOWERS_API UTower_Tower : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Rotate(float Difference);

	void SetTurretReference(UTower_Turret* TurretToSet);

private:
	UTower_Turret* Turret = nullptr;

};
