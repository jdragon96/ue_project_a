#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Controller/ControllerBase.h"
#include "MyMacro.h"
#include "FirstPersonController.generated.h"

class UInputAction;
struct FInputActionValue;
class UInputMappingContext;
class UQuaterViewIMC;
class APlayerCharacter;
class UPlayerAnimation;
/**
 *
 */
UCLASS()
class UE_PROJECT_A_API AFirstPersonController : public AControllerBase {
  GENERATED_BODY()

public:
  AFirstPersonController();

protected:

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
  DECLARE_INPUT_ACTION(ShotAction)
  DECLARE_INPUT_ACTION(LookUpAction)
  DECLARE_INPUT_ACTION(LookRightAction)
  DECLARE_INPUT_ACTION(MoveForwardAction)
  DECLARE_INPUT_ACTION(MoveRightAction)
};
