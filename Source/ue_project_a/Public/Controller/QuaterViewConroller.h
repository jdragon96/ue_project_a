#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Controller/ControllerBase.h"
#include "MyMacro.h"
#include "QuaterViewConroller.generated.h"

class UInputAction;
struct FInputActionValue;
class UInputMappingContext;
class UQuaterViewIMC;
class APlayerCharacter;
class UPlayerAnimation;
class UEnhancedInputComponent;

/**
 *
 */
UCLASS()
class UE_PROJECT_A_API AQuaterViewConroller : public AControllerBase {
  GENERATED_BODY()

public:
  AQuaterViewConroller();

private:
  /// <summary>
  /// 액션 초기화, 생성자에서 호출
  /// </summary>
  virtual void InitAction() override;

  /// <summary>
  /// 액션 콜백함수 연결, SetupInputComponent에서 호출
  /// </summary>
  virtual void BindAction(UEnhancedInputComponent* Component) override;

  /// <summary>
  /// 입력 상태 초기화, PreProcessInput에서 호출
  /// </summary>
  virtual void ClearInputState() override;

  /// <summary>
  /// 입력 상태 업데이트, PostProcessInput에서 호출
  /// </summary>
  virtual void UpdateInputState() override;

public:

private:
  DECLARE_INPUT_ACTION(MoveForwardAction)
  DECLARE_INPUT_ACTION(MoveRightAction)
};
