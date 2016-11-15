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
	bool HasTarget();

	UPROPERTY(EditAnywhere) ALevelController* Controller = nullptr;

	UFUNCTION(BlueprintCallable, Category = Setup) void SetReferences( UTower_Base*     BaseToSet
																	 , UTower_Tower*   TowerToSet
																	 , UTower_Turret* TurretToSet
																	 , UTower_Barrel* BarrelToSet
																	 );
private:
	UPROPERTY(EditAnywhere) AMonsterActor* Target = nullptr;
	UPROPERTY(EditAnywhere) float LaunchSpeed = 100;	// TODO Set sensible default

	UTowerAimingComponent* TowerAimingComponent = nullptr;
	
};
