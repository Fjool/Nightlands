// (C) 2016 Mesomorphic Ltd

#pragma once

#include "Components/ActorComponent.h"
#include "TowerAimingComponent.generated.h"

class UTower_Base;
class UTower_Tower;
class UTower_Turret;
class UTower_Barrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOWERS_API UTowerAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	void SetReferences( UTower_Base*     BaseToSet
					  , UTower_Tower*   TowerToSet
					  , UTower_Turret* TurretToSet
					  , UTower_Barrel* BarrelToSet
					  );

	// Sets default values for this component's properties
	UTowerAimingComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Coordinate the tower to aim at the desired point
	virtual void AimAt(FVector TargetLocation);

private:
	UTower_Base*     Base = nullptr;
	UTower_Tower*   Tower = nullptr;
	UTower_Turret* Turret = nullptr;
	UTower_Barrel* Barrel = nullptr;

	void RotateBaseTowards(FVector AimDirection);

};
