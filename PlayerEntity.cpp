#include "PlayerEntity.h"

//Constructor.
PlayerEntity::PlayerEntity(ImageStore *imageStore , FontStore *fontStore){

    this->backpack = NULL;
    this->imageStore = imageStore;
    this->questLog = NULL;
    this->fontStore = fontStore;
}

//Destructor.    
PlayerEntity::~PlayerEntity(){
    
    delete backpack;
    delete questLog;
    thePlayers->deleteCharList();
    delete thePlayers;
}

//Pre:  The backpack does not already exist.
//Post: Dynamically allocates a backpack. Returns true if
//      successful. Returns false if the Backpack already exists.
bool PlayerEntity::createBackpack(){

    if(backpack == NULL){

        backpack = new Backpack();
        return true;
    }
    
    else return false;
}

//Pre:  None.
//Post: Displays all the active quests for the player
void PlayerEntity::displayActiveQuestsInQuestLog(){

    this->questLog->displayActiveQuests();
}

//Pre:  None.
//Post: Displays all the completed quests for the player
void PlayerEntity::displayCompletedQuestsInQuestLog(){

    this->questLog->displayCompletedQuests();
}

//Pre:  The QuestLog does not exist.
//Post: Dynamically allocates a QuestLog. Returns true if
//      successful otherwise returns false.
bool PlayerEntity::createQuestLog(){

    if(questLog == NULL){

        questLog = new QuestLog(fontStore);
        return true;
    }

    else return false;
}

//Pre:  The Quest is valid.
//Post: The Quest is added to questLog. Returns true if the addition
//      was successful added and did not exist already. Otherwise returns false.
bool PlayerEntity::addQuest(std::string questName , Quest *quest){

    return questLog->addQuest(questName , quest);
}

//Updates all the quests in the QuestLog.
//Pre:  The list is not NULL.
//Post: Updates every quest in the questLog using the list.
void PlayerEntity::updateQuestLog(std::vector<std::string> list){

    questLog->updateAllQuestObjectives(list);
}

//Pre: None.
//Post dynamically allocates the CharacterList and loads the players.
void PlayerEntity::loadDefaultPlayers(){

    this->thePlayers = new CharacterList();

    //Characters
    Character *thePlayer = new Character(imageStore->getBitMap("player")
        , 32 , 32 , 30 , 2 , rate);
    thePlayer->setIdentifierName("player");
    thePlayer->setFacing(DOWN);

    Character *thePlayer2 = new Character(imageStore->getBitMap("warrior") ,
        32 , 32 , 30 , 2 , rate);
    thePlayer2->setIdentifierName("warrior");
    
    Character *thePlayer3 = new Character(imageStore->getBitMap("thief") ,
        32 , 32 , 30 , 2 , rate);
    thePlayer3->setIdentifierName("thief");
    
    Character *thePlayer4 = new Character(imageStore->getBitMap("mage") ,
        32 , 32 , 30 , 2 , rate);
    thePlayer4->setIdentifierName("mage");

    /*
    thePlayer->loadAbilities("Attack,Jump,Item|Potion;Recover;");
    thePlayer2->loadAbilities("Attack,Shield Bash,Item|Potion;Recover;");
    thePlayer3->loadAbilities("Attack,Backstab,Item|Potion;Recover;");
    thePlayer4->loadAbilities("Attack,Magic|Fire1,Fire2,Fire3;Item|Potion;Recover;");
    */

    thePlayer->loadAbilities("Attack;");
    thePlayer2->loadAbilities("Attack;");
    thePlayer3->loadAbilities("Attack;");
    thePlayer4->loadAbilities("Attack;");
   
    //CharacterList thePlayers;
    this->thePlayers->loadChar(thePlayer);
    this->thePlayers->loadChar(thePlayer2);
    this->thePlayers->loadChar(thePlayer3);
    this->thePlayers->loadChar(thePlayer4);

    //thePlayer->addAbility("Jump");
    //AddAbilityToCharacterInList::AddAbilityToCharacterInList("player",thePlayers,"Jump");
    //AddAbilityToCharacterInList::AddAbilityToCharacterInList("mage",thePlayers,"Jump");

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