#include "CharFactory.h"
#include "GameConfig.h"


CharFactory::CharFactory(){

    characterList.resize(MAX_ENEMIES);
    characterList.push_back(new Character());
}

//Destructor
CharFactory::~CharFactory(){

    for(std::vector<Character*>::iterator it = characterList.begin(); it != characterList.end() ; it++)
        delete *it;
}

//Return a dynamically allocated character based on the selection.
Character* CharFactory::createChar(int selection){

    switch(selection){
        case RAT:
            return new Character();

        case WOLF:
            return new Character();

        case SOLDIER:
            return new Character();

        default:
            return NULL;
    }
}

