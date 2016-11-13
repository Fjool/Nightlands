// (C) 2016 Mesomorphic Ltd

#pragma once

#include "Components/ActorComponent.h"
#include "TowerAimingComponent.generated.h"

class UTower_Base;
class UTower_Tower;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOWERS_API UTowerAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	void SetBaseReference(  UTower_Base* BaseToSet);
	void SetTowerReference(UTower_Tower* TowerToSet);

	// Sets default values for this component's properties
	UTowerAimingComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Coordinate the tower to aim at the desired point
	virtual void AimAt(FVector TargetLocation);

private:
	UTower_Base* Base = nullptr;

	void RotateBaseTowards(FVector AimDirection);

};
