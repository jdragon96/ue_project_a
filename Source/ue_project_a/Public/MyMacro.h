#pragma once

#include "Delegates/DelegateSignatureImpl.inl"

struct FInputActionValue;

#define DECLARE_ACCESSOR(Type, VarName) \
		FORCEINLINE Type Get##VarName() const { return VarName; }\
    FORCEINLINE void Set##VarName(Type NewValue) { VarName = NewValue; };

#define DECLARE_INPUT_ACTION(VarName) \
    TObjectPtr<UInputAction> VarName; \
    void Execute##VarName(const FInputActionValue& InputActionValue);