// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillAttack.h"
#include "SkillCollisionDetection.h"
#include "SkillManagerComponent.h"
#include "GameFramework/Character.h"

void USkillAttack::Execute()
{
	if (SkillMgrOwner != nullptr)
	{
		ASkillCollisionDetection* detection = nullptr;
		detection = SkillMgrOwner->GetWorld()->SpawnActorDeferred<ASkillCollisionDetection>(AttackDetection, SkillMgrOwner->GetOwnerCharacter()->GetTransform());

		if (detection != nullptr)
		{
			detection->Init(this);
			detection->FinishSpawning(SkillMgrOwner->GetOwnerCharacter()->GetTransform());
		}
	}

	Super::Execute();
}

void USkillAttack::DetectionMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::DetectionMeshBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}



