// (C) 2016 Mesomorphic Ltd

#include "Towers.h"
#include "Tower_Base.h"

void UTower_Base::Rotate(float Direction)
{
	UE_LOG(LogTemp, Warning, TEXT("Rotate called : %f @ %f "), UGameplayStatics::GetRealTimeSeconds(GetWorld()), Direction)

	SetRelativeRotation( FRotator( 0
								 , RelativeRotation.Yaw + FMath::Clamp(Direction, -1.0f, 1.0f) * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds
								 , 0
								 )
	);
}