// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "EnhancedInputLibrary.h"
#include "Project_Pleidas.h"

#include "Mage.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterDiedDelegate, AMage*, Character);


UCLASS()
class PROJECT_PLEIDAS_API AMage : public ACharacter
{
	GENERATED_BODY()

public:
	AMage(const class FObjectInitializer& ObjectInitializer);


	

	UPROPERTY(BlueprintAssignable, Category = "Demo|Character")
	FCharacterDiedDelegate OnCharacterDied;


	UFUNCTION(BlueprintCallable, Category = "Demo|Character")
	virtual bool isAlive() const;


	UFUNCTION(BlueprintCallable, Category = "Demo|Character")
	virtual int32 GetAbilityLevel(DemoAbilityID AbilityID) const;


	virtual void RemoveCharacterAbilities();


	virtual void Die();
	 
	UFUNCTION(BlueprintCallable, Category = "Demo|Character")
	virtual void FinishDying();


	UFUNCTION(BlueprintCallable, Category = "Demo|Character|Attributes")
	float GetCharacterLevel() const;


	UFUNCTION(BlueprintCallable, Category = "Demo|Character|Attributes")
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Demo|Character|Attributes")
	float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Demo|Character|Attributes")
	float GetMana() const;

	UFUNCTION(BlueprintCallable, Category = "Demo|Character|Attributes")
	float GetMaxMana() const;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PawnClientRestart() override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;


protected:
	//Movement
	void MovementInputHandler(const FInputActionValue& Value);
	void LookInputHandler(const FInputActionValue& inputActionValue);

	UPROPERTY(EditAnywhere, Category = "Input|Binding")
	UInputMappingContext* InputMappingContext{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Input|Binding")
	UInputAction* MovementAction{ nullptr };

	UPROPERTY(EditAnywhere, Category="Input|Binding")
	UInputAction* LookAction{ nullptr };

	//Abilities and Attributes

	TWeakObjectPtr<class UCharacterAbilitySystemComponent> AbilitySystemComponent;
	TWeakObjectPtr<class UCharacterAttributeSet> AttributeSet;

	FGameplayTag DeadTag;
	FGameplayTag EffectRemoveOnDeathTag;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Demo|Character")
	FText CharacterName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Demo|Animation")
	UAnimMontage* DeathMontage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Demo|Animation")
	TArray<TSubclassOf<class UCharacterGameplayAbility>> CharacterAbilities;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Demo|Abilities")
	TSubclassOf<class UGameplayEffect> DefaultAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Demo|Abilities")
	TArray<TSubclassOf<class UGameplayEffect>> StartupEffects;

	virtual void AddCharacterAbilities();

	virtual void InitializeAttributes();

	virtual void AddStartupEffects();

	virtual void SetHealth(float Health);

	virtual void SetMana(float Mana);



};




