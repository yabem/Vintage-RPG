#include "PlayerEntity.h"

//Constructor.
PlayerEntity::PlayerEntity(){

    this->backpack = NULL;
}

//Destructor.    
PlayerEntity::~PlayerEntity(){
    
    delete backpack;
}

//Pre:  None.
//Post: Dynamically allocates a backpack.
void PlayerEntity::loadBackpack(){

    backpack = new Backpack();
}
    
//Returns a pointer to the player's inventory.
//Pre:  None.
//Post: Returns a Backpack pointer that stores all the player's inventory.
Backpack* PlayerEntity::getPlayerInventory(){

    return backpack;
}