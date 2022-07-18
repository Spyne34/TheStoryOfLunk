// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillBase.h"
#include "SkillHeal.generated.h"

/**
 * 
 */
UCLASS()
class LUNK_API USkillHeal : public USkillBase
{
	GENERATED_BODY()

public:

	//The amount of HP to recover
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float HealAmount = 10.0f;

protected:
	virtual void Execute() override;

};
