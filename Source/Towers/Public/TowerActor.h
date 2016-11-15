// (C) 2016 Mesomorphic Ltd

#pragma once
// (C) 2016 Mesomorphic Ltd

// TODO Should be called simply Tower, not TowerActor

#include "GameFramework/Actor.h"
#include "TowerActor.generated.h"

class AMonsterActor;
class UTower_Base;
class UTower_Tower;
class UTowerAimingComponent;
class ALevelController;

UCLASS()
class TOWERS_API ATowerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere) ALevelController* Controller = nullptr;

	// Sets default values for this actor's properties
	ATowerActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void SetTarget(AMonsterActor* Monster);
	bool HasTarget();

private:
	UPROPERTY(EditAnywhere) AMonsterActor* Target = nullptr;
	UPROPERTY(EditAnywhere) float LaunchSpeed = 100;	// TODO Set sensible default
	UFUNCTION(BlueprintCallable, Category = Setup) void  SetBaseReference(UTower_Base*  BaseToSet);
	UFUNCTION(BlueprintCallable, Category = Setup) void SetTowerReference(UTower_Tower* TowerToSet);

	UTowerAimingComponent* TowerAimingComponent = nullptr;
	
};
