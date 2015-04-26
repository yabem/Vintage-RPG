#include "PlayerEntity.h"

//Constructor.
PlayerEntity::PlayerEntity(ImageStore *imageStore){

    this->backpack = NULL;
    this->imageStore = imageStore;
}

//Destructor.    
PlayerEntity::~PlayerEntity(){
    
    delete backpack;
    thePlayers->deleteCharList();
    delete thePlayers;
}

//Pre:  None.
//Post: Dynamically allocates a backpack.
void PlayerEntity::loadBackpack(){

    backpack = new Backpack();
}

//Pre: None.
//Post dynamically allocates the CharacterList and loads the players.
void PlayerEntity::loadDefaultPlayers(){

    this->thePlayers = new CharacterList();

    //Characters
    Character *thePlayer = new Character(imageStore->getBitMap("player")
        , 32 , 32 , 30 , 2 , rate);
    Character *thePlayer2 = new Character(imageStore->getBitMap("warrior") ,
        32 , 32 , 30 , 2 , rate);
    Character *thePlayer3 = new Character(imageStore->getBitMap("thief") ,
        32 , 32 , 30 , 2 , rate);
    Character *thePlayer4 = new Character(imageStore->getBitMap("mage") ,
        32 , 32 , 30 , 2 , rate);

    thePlayer->setFacing(DOWN);

    thePlayer->loadAbilities("Attack,Jump,Item|Potion;Recover;");
    thePlayer2->loadAbilities("Attack,Shield Bash,Item|Potion;Recover;");
    thePlayer3->loadAbilities("Attack,Backstab,Item|Potion;Recover;");
    thePlayer4->loadAbilities("Attack,Magic|Fire1,Fire2,Fire3;Item|Potion;Recover;");
   
    //CharacterList thePlayers;
    this->thePlayers->loadChar(thePlayer);
    this->thePlayers->loadChar(thePlayer2);
    this->thePlayers->loadChar(thePlayer3);
    this->thePlayers->loadChar(thePlayer4);

    std::vector<std::string> emptyStringVector;

    //Character stats
    CharStats *playerStats = new CharStats(1 , 1 , 10 , 100 , 10 , 1 , 100 ,
        10 , 1.8 , 0 , 0 , emptyStringVector);
    CharStats *playerStats2 = new CharStats(1 , 5 , 10 , 100 , 10 , 1 , 100 ,
        10 , 1.9 , 0 , 0 , emptyStringVector);
    CharStats *playerStats3 = new CharStats(1 , 1 , 10 , 100 , 10 , 1 , 100 ,
        10 , 2.0 , 0 , 0, emptyStringVector);
    CharStats *playerStats4 = new CharStats(1 , 5 , 10 , 100 , 10 , 1 , 100 ,
        10 , 1.3 , 0 , 0 , emptyStringVector);

    thePlayer->setStats(playerStats);
    thePlayer2->setStats(playerStats2);
    thePlayer3->setStats(playerStats3);
    thePlayer4->setStats(playerStats4);
}
    
//Returns a pointer to the player's inventory.
//Pre:  None.
//Post: Returns a Backpack pointer that stores all the player's inventory.
Backpack* PlayerEntity::getPlayerInventory(){

    return backpack;
}

//Returns a pointer to the players.
//Pre:  None.
//Post: Returns a pointer to the players.
CharacterList* PlayerEntity::getThePlayers(){

    return thePlayers;
}

//Returns a pointer to the first Character in thePlayers.
//Pre:  None.
//Post: Returns a pointer to the first Character in thePlayers.
Character* PlayerEntity::getFirstPlayer(){

    thePlayers->resetSelection();
    return thePlayers->getCurrSelection();
}