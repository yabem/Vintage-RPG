//Calculations for level ups and applies level ups.

#pragma once
#include "Character.h"
#include "CharacterList.h"
#include "StatsByLevelStore.h"
#include "DrawRepository.h"
#include "Conversion.h"

namespace LevelUpCalculations{

    std::vector<std::string> levelUpListOfCharacters(CharacterList *characterList ,
        StatsByLevelStore *statsByLevelStore , DrawRepository *drawRepository);

    std::vector<std::string> levelUpCharacter(Character *character , 
        StatsByLevelStore *statsByLevelStore , DrawRepository *drawRepository);

    std::string getNewStatsSummary(Character *character , 
        StatsByLevelStore *statsByLevelStore);

    void setCharacterToLevel(Character *character , int level , 
        StatsByLevelStore *statsByLevelStore);

    void setHPToFull(Character *character);
};