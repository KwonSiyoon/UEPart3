// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimNotify_AttackHitCheck.h"
#include "Interface/ABAnimationAttackInterface.h"
#include "ArenaBattle.h"

void UAnimNotify_AttackHitCheck::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
#define LOG_SUBNETMODEINFO ( ( MeshComp->GetOwner()->GetNetMode() == ENetMode::NM_Client) ? *FString::Printf(TEXT("CLIENT%d"), (int32)GPlayInEditorID) : ( (MeshComp->GetOwner()->GetNetMode() == ENetMode::NM_Standalone) ? TEXT("STANDALONE") : TEXT("SERVER") ) )

	UE_LOG(LogABNetwork, Log, TEXT("[%s] %s"), LOG_SUBNETMODEINFO, TEXT("Notify 실행 시작."));
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp/*->GetOwner()->HasAuthority()*/)
	{
		IABAnimationAttackInterface* AttackPawn = Cast<IABAnimationAttackInterface>(MeshComp->GetOwner());
		if (AttackPawn)
		{
			AttackPawn->AttackHitCheck();
			UE_LOG(LogABNetwork, Log, TEXT("[%s] %s"), LOG_SUBNETMODEINFO, TEXT("AttackHitCheck"));

		}
	}
	UE_LOG(LogABNetwork, Log, TEXT("[%s] %s"), LOG_SUBNETMODEINFO, TEXT("Notify 실행 끝."));
}
