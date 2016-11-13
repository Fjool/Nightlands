// (C) 2016 Mesomorphic Ltd

#include "Towers.h"
#include "Tower_Base.h"
#include "Tower_Tower.h"

void UTower_Base::SetTowerReference(UTower_Tower* TowerToSet) { Tower = TowerToSet; }

void UTower_Base::Rotate(FVector AimDirection)
{
	if (Tower)	
	{	auto DeltaRotator = AimDirection.Rotation() - Tower->GetForwardVector().Rotation();
		Tower->Rotate(FMath::Clamp(DeltaRotator.Yaw, -1.0f, 1.0f) * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds);
	}
	else { UE_LOG(LogTemp, Warning, TEXT("No tower")) }
}