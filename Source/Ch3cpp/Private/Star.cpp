#include "Star.h"

AStar::AStar()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Star_B.SM_Star_B"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialAsset(TEXT("/Game/Resources/Materials/M_Armor.M_Armor"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
}

void AStar::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	StartScale = GetActorScale3D();

	MovementDirection.Normalize();
}

void AStar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Sin 함수 활용
	RunningTime += DeltaTime;

	/*float DeltaHeight = FMath::Sin(RunningTime * Speed) * MaxHeight;

	FVector NewLocation = StartLocation;
	NewLocation.Z += DeltaHeight;

	SetActorLocation(NewLocation);*/

	if (!FMath::IsNearlyZero(Speed))
	{
		AddActorLocalRotation(FRotator(0.0f, Speed * DeltaTime, 0.0f));
	}

	float Time = GetWorld()->GetTimeSeconds();
	float ScaleFactor = (FMath::Sin(ScaleSpeed * RunningTime/*Time * PI * 2*/) + 1.0f) * 0.5f;
	float CurrentScale = FMath::Lerp(MinScale, MaxScale, ScaleFactor);

	FVector NewScale = StartScale * CurrentScale;
	SetActorScale3D(NewScale);
	
	// 선형 이동 방법
	/*FVector CurrentLocation = GetActorLocation();

	float DeltaHeight = Speed * DeltaTime;

	if (bIsMovingUp)
	{
		CurrentLocation.Z += DeltaHeight;

		if (CurrentLocation.Z >= StartLocation.Z + MaxHeight)
		{
			CurrentLocation.Z = StartLocation.Z + MaxHeight;
			bIsMovingUp = false;
		}
	}
	else
	{
		CurrentLocation.Z -= DeltaHeight;

		if (CurrentLocation.Z <= StartLocation.Z)
		{
			CurrentLocation.Z = StartLocation.Z;
			bIsMovingUp = true;
		}
	}
	SetActorLocation(CurrentLocation);*/

	FVector DeltaLocation = MovementDirection * MovementSpeed * DeltaTime;
	AddActorWorldOffset(DeltaLocation);

	FVector CurrentLocation = GetActorLocation();
	if (CurrentLocation.X > 500.f || CurrentLocation.X < -500.f)
	{
		MovementDirection *= -1.0f;
	}
}

