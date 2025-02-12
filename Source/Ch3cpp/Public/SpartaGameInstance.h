#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SpartaGameInstance.generated.h"


UCLASS()
class CH3CPP_API USpartaGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	USpartaGameInstance();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameData")
	int32 TotalScore;

	UFUNCTION(BlueprintCallable, Category = "GameData")
	void AddToScore(int32 Amount);
};
