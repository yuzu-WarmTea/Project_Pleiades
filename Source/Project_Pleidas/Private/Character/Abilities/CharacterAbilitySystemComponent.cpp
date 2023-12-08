// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Abilities/CharacterAbilitySystemComponent.h"

void UCharacterAbilitySystemComponent::RecieveDamage(UCharacterAbilitySystemComponent* SourceASC, float UnmitigatedDamage, float MitigatedDamage)
{
	RecievedDamage.Broadcast(SourceASC, UnmitigatedDamage, MitigatedDamage);
}
