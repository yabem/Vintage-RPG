#include "ChangeCharacterHeight.h"

//Constructor.
ChangeCharacterHeight::ChangeCharacterHeight(Character *character,
    int height){

    this->character = character;
    this->height = height;
}

//Destructor.
ChangeCharacterHeight::~ChangeCharacterHeight(){

    //Default destructor is fine.
}

//Changes the Character's width.
//Pre:  None.
//Post: The Character's height is set to the inputted width..
bool ChangeCharacterHeight::play(){

    character->setH(height);

    return true;
}