#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Star.generated.h"

UCLASS()
class CH3CPP_API AStar : public AActor
{
	GENERATED_BODY()
	
public:	
	AStar();

protected:
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	FVector StartLocation;
	FVector StartScale;
	FVector MovementDirection = FVector(1.0f, 0.0f, 0.0f);

	float Speed = 10.0f;
	float RunningTime = 0.0f;
	float MaxHeight = 200.0f;

	float ScaleSpeed = 0.5f;
	float MaxScale = 2.0f;
	float MinScale = 0.5f;

	float MovementSpeed = 200.0f;

	bool bIsMovingUp = true;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
