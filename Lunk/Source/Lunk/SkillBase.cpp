// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillBase.h"
#include "SkillManagerComponent.h"
#include "GameFramework/Character.h"



bool USkillBase::RequestExecution()
{
	// test cooldown
	if (currentCooldownTimer <= 0.0f)
	{
		//Test cast Time
		if (castTime <= 0.0f)
			Execute();
		else
		{
			isExecuting = true;
			currentCastTimer = castTime;
			//Start Animation to match with gameplay, according to castTime
			Event_OnRequestExecutionBP();
		}

		return true;
	}

	return false;
}

void USkillBase::TickSkill(float _deltaTime)
{
	//-- Update Cooldown
	if (currentCooldownTimer > 0.0f)
		currentCooldownTimer -= _deltaTime;

	if (currentCooldownTimer < 0.0f)
	{
		currentCooldownTimer = 0.0f;
	}

	//-- Update cast time
	if (currentCastTimer > 0.0f)
	{
		currentCastTimer -= _deltaTime;

		if (currentCastTimer <= 0.0f)
			Execute();
	}

	Event_TickSkillBP(_deltaTime);
}

void USkillBase::DetectionMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Event_DetectionMeshBeginOverlapBP(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

void USkillBase::DetectionMeshEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Event_DetectionMeshEndOverlapBP(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}

void USkillBase::ProjectileBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Event_ProjectileBeginOverlapBP(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

void USkillBase::ProjectileEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Event_ProjectileEndOverlapBP(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}

void USkillBase::Execute()
{
	isExecuting = true;
	currentCastTimer = -1.0f;


	Event_OnExecuteBP();

	EndExecution();
}

void USkillBase::EndExecution()
{
	currentCooldownTimer = cooldown;

	Event_OnEndExecutionBP();

	isExecuting = false;
}

