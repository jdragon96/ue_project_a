// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "QuaterViewIMC.generated.h"

class UInputAction;
/**
 * 
 */
UCLASS()
class UE_PROJECT_A_API UQuaterViewIMC : public UInputMappingContext
{
	GENERATED_BODY()

public:
	UQuaterViewIMC();
	

	// ĳ���� �̵� �׼�
	TObjectPtr<UInputAction> MoveAction;
};
