#include "ChangeCharacterWidth.h"

//Constructor.
ChangeCharacterWidth::ChangeCharacterWidth(Character *character,
    int width){

    this->character = character;
    this->width = width;
}

//Destructor.
ChangeCharacterWidth::~ChangeCharacterWidth(){

    //Default destructor is fine.
}

//Changes the Character's width.
//Pre:  None.
//Post: The Character's width is set to the inputted width..
bool ChangeCharacterWidth::play(){

    character->setW(width);

    return true;
}