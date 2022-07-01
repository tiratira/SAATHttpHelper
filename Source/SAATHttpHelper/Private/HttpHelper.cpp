// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpHelper.h"
#include "Http.h"


void UHttpHelper::FetchString(const FString& URL, const FHttpRequestResponse& OnResponse)
{
	const auto HTTPRequest = FHttpModule::Get().CreateRequest();
	HTTPRequest->SetVerb("GET");
	HTTPRequest->SetURL(URL);
	HTTPRequest->OnProcessRequestComplete().BindLambda(
		[OnResponse](FHttpRequestPtr request, FHttpResponsePtr response, bool success)
		{
			if (success && OnResponse.IsBound())
			{
				auto Data = response->GetContentAsString();
				OnResponse.Execute(Data);
			}
		});
	HTTPRequest->ProcessRequest();
}
