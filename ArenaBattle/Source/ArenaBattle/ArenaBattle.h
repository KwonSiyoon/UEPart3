// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

// 네트워크 로컬 역할 정보.
#define LOG_LOCALROLEINFO *(UEnum::GetValueAsString(TEXT("Engine.ENetRole"),GetLocalRole()))

// 네트워크 리모트 역할 정보.
#define LOG_REMOTEROLEINFO *(UEnum::GetValueAsString(TEXT("Engine.ENetRole"),GetRemoteRole()))

// 컴포넌트에 사용시.
#define LOG_SUBLOCALROLEINFO *(UEnum::GetValueAsString(TEXT("Engine.ENetRole"),GetOwner()->GetLocalRole()))
#define LOG_SUBREMOTEROLEINFO *(UEnum::GetValueAsString(TEXT("Engine.ENetRole"),GetOwner()->GetRemoteRole()))


// 넷모드(네트워크 모드) 정보.
#define LOG_NETMODEINFO ( ( GetNetMode() == ENetMode::NM_Client) ? *FString::Printf(TEXT("CLIENT%d"), (int32)GPlayInEditorID) : ( (GetNetMode() == ENetMode::NM_Standalone) ? TEXT("STANDALONE") : TEXT("SERVER") ) )


// 함수 호출 정보.
#define LOG_CALLINFO ANSI_TO_TCHAR(__FUNCTION__)

// 로그 매크로.
#define AB_LOG(LogCat, Verbosity, Format, ...) UE_LOG(LogCat, Verbosity, TEXT("[%s][%s/%s] %s %s"), LOG_NETMODEINFO, LOG_LOCALROLEINFO, LOG_REMOTEROLEINFO,LOG_CALLINFO,*FString::Printf(Format, ##__VA_ARGS__))

#define AB_SUBLOG(LogCat, Verbosity, Format, ...) UE_LOG(LogCat, Verbosity, TEXT("[%s][%s/%s] %s %s"), LOG_NETMODEINFO, LOG_SUBLOCALROLEINFO, LOG_SUBREMOTEROLEINFO,LOG_CALLINFO,*FString::Printf(Format, ##__VA_ARGS__))


DECLARE_LOG_CATEGORY_EXTERN(LogABNetwork, Log, All);