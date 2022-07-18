// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillAttackAOE.h"
#include "SkillSphereCollisionDetection.h"
#include "SkillManagerComponent.h"
#include "GameFramework/Character.h"

void USkillAttackAOE::Execute()
{
	if (SkillMgrOwner != nullptr)
	{
		ASkillSphereCollisionDetection* detection = nullptr;
		detection = SkillMgrOwner->GetWorld()->SpawnActorDeferred<ASkillSphereCollisionDetection>(AttackSphereDetection, SkillMgrOwner->GetOwnerCharacter()->GetTransform());
		
		if (detection != nullptr)
		{
			detection->Init(this);
			detection->FinishSpawning(SkillMgrOwner->GetOwnerCharacter()->GetTransform());
		}
	}

	Super::Execute();
}

void USkillAttackAOE::DetectionMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::DetectionMeshBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

