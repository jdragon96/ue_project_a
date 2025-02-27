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
  /// �׼� �ʱ�ȭ, �����ڿ��� ȣ��
  /// </summary>
  virtual void InitAction() override;

  /// <summary>
  /// �׼� �ݹ��Լ� ����, SetupInputComponent���� ȣ��
  /// </summary>
  virtual void BindAction(UEnhancedInputComponent* Component) override;

  /// <summary>
  /// �Է� ���� �ʱ�ȭ, PreProcessInput���� ȣ��
  /// </summary>
  virtual void ClearInputState() override;

  /// <summary>
  /// �Է� ���� ������Ʈ, PostProcessInput���� ȣ��
  /// </summary>
  virtual void UpdateInputState() override;

public:

private:
  DECLARE_INPUT_ACTION(MoveForwardAction)
  DECLARE_INPUT_ACTION(MoveRightAction)
};
