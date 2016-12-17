// Copyright David Thornton 2016

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank Track is use to set max driving fource and apply forces to the tank
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Input")
void SetThrottle(float Throttle);
	//Max Force in Newtons!!!
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float TrackMaxDrivingFource = 40000000;//Assume 40 ton tank and 1 g of exceleration
private:
	UTankTrack();
	void BeginPlay();
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)override;
};
