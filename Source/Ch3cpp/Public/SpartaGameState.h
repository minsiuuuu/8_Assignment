#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "SpartaGameState.generated.h"

UCLASS()
class CH3CPP_API ASpartaGameState : public AGameState
{
	GENERATED_BODY()
	
public:
	ASpartaGameState();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Score")
	int32 Score;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 SpawnedCoinCount;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 CollectedCoinCount;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave")
	int32 CurrentWave;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wave")
	int32 MaxWaves;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave")
	float WaveDuration;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wave")
	float DefaultWaveDuration;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wave")
	float WaveDurationStep;

	FTimerHandle WaveTimerHandle;
	FTimerHandle HUDUpdateTimerHandle;
	FTimerHandle WaveTransitionTimerHandle;

	UFUNCTION(BlueprintPure, Category = "Score")
	int32 GetScore() const;
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddScore(int32 Amount);
	UFUNCTION(BlueprintCallable, Category = "Level")
	void OnGameOver();

	void StartWave();
	void OnWaveTimeUp();
	void OnCoinCollected();
	void EndWave();
	void UpdateHUD();
};
