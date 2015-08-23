#pragma once
#include "Dialogue.h"
#include "CharacterList.h"
#include "AddAbilityToCharacterInList.h"

class RewardAbility : public Dialogue{

private:

    CharacterList *characterList;
    std::string playerToReward;
    std::string reward;

public:

    RewardAbility(GameManager *gameManager , ALLEGRO_FONT *font ,
        std::string playerToReward ,CharacterList *characterList ,
        std::string reward);
    ~RewardAbility();
    virtual bool play(const int pressedKey); 
};