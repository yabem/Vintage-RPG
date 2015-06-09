//Initiates a battle.

#pragma once
#include "Dialogue.h"
#include "CharacterList.h"
#include "AddAbilityToCharacterInList.h"

class RewardAbility : public Dialogue{

private:

    CharacterList *characterList;
    std::string playerToReward;
    std::string abilityToReward;

public:

    RewardAbility(GameManager *gameManager , ALLEGRO_FONT *introFont ,
        std::string playerToReward ,CharacterList *characterList ,
        std::string abilityToReward);
    ~RewardAbility();
    virtual bool play(const int pressedKey); 
};