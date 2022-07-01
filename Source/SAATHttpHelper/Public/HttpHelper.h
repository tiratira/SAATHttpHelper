// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HttpHelper.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FHttpRequestResponse, FString, Response);

/**
 * Saat Http helper
 * by luyangbin
 */
UCLASS()
class SAATHTTPHELPER_API UHttpHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category="SAAT")
	static void FetchString(const FString& URL, const FHttpRequestResponse& OnResponse);
};
