// (C) 2016 Mesomorphic Ltd

#pragma once
// (C) 2016 Mesomorphic Ltd

// TODO Should be called simply Tower, not TowerActor

#include "GameFramework/Actor.h"
#include "TowerActor.generated.h"

class AMonsterActor;
class UTower_Base;
class UTower_Tower;
class UTower_Turret;
class UTower_Barrel;
class UTowerAimingComponent;
class ALevelController;

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

	void SetTarget(AMonsterActor* Monster);
	bool IsTarget( AMonsterActor* Monster);
	bool HasTarget();

	UPROPERTY(EditAnywhere) ALevelController* Controller = nullptr;
	
	UFUNCTION(BlueprintCallable, Category = Setup) void SetReferences( UTower_Base*     BaseToSet
																	 , UTower_Tower*   TowerToSet
																	 , UTower_Turret* TurretToSet
																	 , UTower_Barrel* BarrelToSet
																	 );
	
	// instruct the tower to hurt the monster, if possible
	UFUNCTION(BlueprintCallable, Category = Action) bool HurtTarget();

private:
	UPROPERTY(EditDefaultsonly) float LaunchSpeed = 100;		// TODO Set sensible default
	UPROPERTY(EditDefaultsOnly) float ReloadTimeInSeconds = 2;	// TODO Set sensible default
	UPROPERTY(EditDefaultsOnly) float Range = 500;				// TODO Set sensible default
	UPROPERTY(EditDefaultsOnly) float Damage = 10;				// TODO Defaults

	AMonsterActor* Target = nullptr;
	UTowerAimingComponent* TowerAimingComponent = nullptr;

	float LastFireTime = 0;
	
	bool TargetInRange();
};
