// (C) 2016 Mesomorphic Ltd

#include "Towers.h"
#include "Tower_Tower.h"
#include "Tower_Turret.h"

void UTower_Tower::SetTurretReference(UTower_Turret* TurretToSet)
{
	Turret = TurretToSet;
}

void UTower_Tower::Rotate(float Difference)
{	
	SetRelativeRotation(FRotator(0, RelativeRotation.Yaw + Difference, 0));
}