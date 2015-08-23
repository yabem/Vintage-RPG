#pragma once
#include "Dialogue.h"
#include "CharacterList.h"
#include "AddAbilityToCharacterInList.h"
#include "GenericItem.h"

class RewardItem : public Dialogue{

private:

    CharacterList *characterList;
    std::string itemToReward;
    int amountGained;

public:

    RewardItem(GameManager *gameManager , ALLEGRO_FONT *font ,
        std::string itemToReward , int amountGained);
    ~RewardItem();
    virtual bool play(const int pressedKey); 
};