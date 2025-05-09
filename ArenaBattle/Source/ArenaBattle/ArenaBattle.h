// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

// 로그 매크로.
#define AB_LOG(LogCat, Verbosity, Format, ...) UE_LOG(LogCat, Verbosity, TEXT("%s"), *FString::Printf(Format, ##__VA_ARGS__))


DECLARE_LOG_CATEGORY_EXTERN(LogABNetwork, Log, All);