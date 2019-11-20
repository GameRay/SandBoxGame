// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiPlayerState.h"
ASlAiPlayerState::ASlAiPlayerState()
{

}
void ASlAiPlayerState::RegisterShortCutContainer(TArray<TSharedPtr<ShortcutContainer>>* ContainerList, TSharedPtr<STextBlock> ShortcutInfoTextBlock)
{
	for (TArray<TSharedPtr<ShortcutContainer>>::TIterator It(*ContainerList);It;++It)
	{
		ShortcutContainerList.Add(*It);
		
	}
	ShortcutInfoTextAttr.BindUObject(this,&ASlAiPlayerState::GetShortcutInfoText);
	ShortcutInfoTextBlock->SetText(ShortcutInfoTextAttr);
}

FText ASlAiPlayerState::GetShortcutInfoText() const
{
	return FText();
}
