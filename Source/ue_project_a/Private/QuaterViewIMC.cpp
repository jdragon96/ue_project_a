// Fill out your copyright notice in the Description page of Project Settings.


#include "QuaterViewIMC.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "InputModifiers.h"


UQuaterViewIMC::UQuaterViewIMC(): UInputMappingContext()
{
 	MoveAction = NewObject<UInputAction>();
	MoveAction->ValueType = EInputActionValueType::Axis2D;
	FEnhancedActionKeyMapping& MoveUpMapping = MapKey(MoveAction, EKeys::Up);
	FEnhancedActionKeyMapping& MoveDownMapping = MapKey(MoveAction, EKeys::Down);
	FEnhancedActionKeyMapping& MoveRightMapping = MapKey(MoveAction, EKeys::Right);
	FEnhancedActionKeyMapping& MoveLeftMapping = MapKey(MoveAction, EKeys::Left);
	{
		auto upAxisMod = NewObject<UInputModifierSwizzleAxis>();
		upAxisMod->Order = EInputAxisSwizzle::YXZ;
		MoveUpMapping.Modifiers.Add(upAxisMod);
	}
	{
		auto downAxisMod = NewObject<UInputModifierSwizzleAxis>();
		downAxisMod->Order = EInputAxisSwizzle::YXZ;
		auto downNegMod = NewObject<UInputModifierNegate>();
		downNegMod->bX = true;
		downNegMod->bY = true;
		downNegMod->bZ = true;
		MoveDownMapping.Modifiers.Add(downNegMod);
		MoveDownMapping.Modifiers.Add(downAxisMod);
	}
	{
		//auto rightAxisMod = NewObject<UInputModifierSwizzleAxis>();
		//rightAxisMod->Order = EInputAxisSwizzle::X;
		//MoveRightMapping.Modifiers.Add(rightAxisMod);
	}
	{
		auto leftNegMod = NewObject<UInputModifierNegate>();
		leftNegMod->bX = true;
		leftNegMod->bY = false;
		leftNegMod->bZ = false;
		MoveLeftMapping.Modifiers.Add(leftNegMod);
	}
}