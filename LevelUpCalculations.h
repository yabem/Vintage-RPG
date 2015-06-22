//Calculations for level ups and applies level ups.

#pragma once
#include "Character.h"
#include "CharacterList.h"
#include "StatsByLevelStore.h"

namespace LevelUpCalculations{

    void levelUpListOfCharacters(CharacterList *characterList ,
        StatsByLevelStore *statsByLevelStore);

    void levelUpCharacter(Character *character , 
        StatsByLevelStore *statsByLevelStore);

    void setNewStats(Character *character , 
        StatsByLevelStore *statsByLevelStore);

    void setHPToFull(Character *character);
};