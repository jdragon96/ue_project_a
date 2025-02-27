#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ControllerBase.generated.h"

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
class UE_PROJECT_A_API AControllerBase : public APlayerController {
  GENERATED_BODY()

public:
  AControllerBase();

protected:
  virtual void BeginPlay() override;
  virtual void SetupInputComponent() override;
  virtual void PreProcessInput(const float DeltaTime,
                               const bool bGamePaused) override;
  virtual void PostProcessInput(const float DeltaTime,
                                const bool bGamePaused) override;
  /// <summary>
  /// �׼� �ʱ�ȭ, �����ڿ��� ȣ��
  /// </summary>
  virtual void InitAction();

  /// <summary>
  /// �׼� �ݹ��Լ� ����, SetupInputComponent���� ȣ��
  /// </summary>
  virtual void BindAction(UEnhancedInputComponent* Component);

  /// <summary>
  /// �Է� ���� �ʱ�ȭ, PreProcessInput���� ȣ��
  /// </summary>
  virtual void ClearInputState();

  /// <summary>
  /// �Է� ���� ������Ʈ, PostProcessInput���� ȣ��
  /// </summary>
  virtual void UpdateInputState();

public:
  /// <summary>
  /// ��???? ??? ??????
  /// </summary>
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
  FVector MoveVector;

  /// <summary>
  /// 
  /// </summary>
  UPROPERTY(EditAnywhere, Category = "Movement")
  double TransitionRate = 0.2;

protected:
  /// <summary>
  /// 
  /// </summary>
  TObjectPtr<UInputMappingContext> PlayerContext;

  /// <summary>
  /// ��????, ??????? ?��???? ??????
  /// </summary>
  TObjectPtr<APlayerCharacter> OwnerActor;

  /// <summary>
  /// 
  /// </summary>
  TObjectPtr<UPlayerAnimation> OwnerAnimation;

private:
};
