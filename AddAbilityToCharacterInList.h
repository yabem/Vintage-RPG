//Adds an ability to a Character in a CharacterList

#pragma once
#include "CharacterList.h"

namespace AddAbilityToCharacterInList{

    bool AddAbilityToCharacterInList(std::string identifierName , 
        CharacterList *characterList , std::string ability); 
};