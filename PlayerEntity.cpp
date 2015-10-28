#include "PlayerEntity.h"

//Constructor.
PlayerEntity::PlayerEntity(ImageStore *imageStore , FontStore *fontStore ,
    StatsByLevelStore *statsByLevelStore){

    this->backpack = NULL;
    this->imageStore = imageStore;
    this->questLog = NULL;
    this->fontStore = fontStore;
    this->partyStatusDisplay = NULL;
    this->statsByLevelStore = statsByLevelStore;
}

//Destructor.    
PlayerEntity::~PlayerEntity(){
    
    delete backpack;
    delete questLog;
    thePlayers->deleteCharList();
    delete thePlayers;
    delete partyStatusDisplay;
}

//Pre:  The backpack does not already exist.
//Post: Dynamically allocates a backpack. Returns true if
//      successful. Returns false if the Backpack already exists.
bool PlayerEntity::createBackpack(){

    if(backpack == NULL){

        backpack = new Backpack(fontStore);
        return true;
    }
    
    else return false;
}

//Pre:  None.
//Post: Displays all the active quests for the player.
void PlayerEntity::displayActiveQuestsInQuestLog(){

    questLog->displayActiveQuests();
}

//Pre:  None.
//Post: Displays all the completed quests for the player.
void PlayerEntity::displayCompletedQuestsInQuestLog(){

    questLog->displayCompletedQuests();
}

//Pre:  None.
//Post: Updates all the quests in the questLog.
void PlayerEntity::updateQuestDisplays(){

    questLog->updateActiveQuestsDisplay();
    questLog->updateCompletedQuestsDisplay();
}

//Pre:  None.
//Post: Displays the player stats of everyone in the party.
void PlayerEntity::displayPlayerStats(){

    partyStatusDisplay->draw();
}

//Recreates the display
//Pre:  None.
//Post: Permanently updates the partyStatusDisplay.
void PlayerEntity::updatePartyStatusDisplay(){

    //Delete existing display.
    delete partyStatusDisplay;
    partyStatusDisplay = NULL;

    std::string allStatuses = 
        "--------------------------------------------Party Status"
        "--------------------------------------------,";

    thePlayers->resetSelection();

    //Get character summary from each character.
    for(int i = 0 ; i < thePlayers->getSize() ; i++){

        allStatuses += thePlayers->getCurrSelection()->getStats()->getSummary();

        //Check if there's another element.
        if(i + 1 != thePlayers->getSize()){

            allStatuses += ",";
        }

        thePlayers->moveSelectionDown();
    }

    thePlayers->resetSelection();
    allStatuses += ";";

    InfoTable *partyStatusDisplay = new InfoTable(allStatuses ,
        fontStore->getFont("default"));
    partyStatusDisplay->formatText();
    this->partyStatusDisplay = partyStatusDisplay;
    centerPartyStatusDisplayToScreen();
}

 //Moves the partyStatusDisplay to the middle of the screen.
//Pre:  None.
//Post: Gets the difference in width between the partyStatusDisplay and the screen 
//      width. Divides that by two, then adds it to the start position of
//      the partyStatusDisplay.
 void PlayerEntity::centerPartyStatusDisplayToScreen(){

    int totalWidthOfInfoTable = 
        partyStatusDisplay->getDX() - partyStatusDisplay->getSX();
    int amountToAddToInfoTableToCenter = 
        (SCREEN_W - totalWidthOfInfoTable) / 2;

    partyStatusDisplay->setSX(amountToAddToInfoTableToCenter);
    partyStatusDisplay->calculateMenuEndCoordinates();
    partyStatusDisplay->calculateSelectorCoords();
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
    Character *thePlayer = new Character(imageStore->getBitMap("lancer")
        , 32 , 32 , 30 , 2 , PLAYER_MOVE_RATE);
    thePlayer->setIdentifierName("lancer");
    thePlayer->setFacing(DOWN);

    Character *thePlayer2 = new Character(imageStore->getBitMap("warrior") ,
        32 , 32 , 30 , 2 , PLAYER_MOVE_RATE);
    thePlayer2->setIdentifierName("warrior");
    
    Character *thePlayer3 = new Character(imageStore->getBitMap("thief") ,
        32 , 32 , 30 , 2 , PLAYER_MOVE_RATE);
    thePlayer3->setIdentifierName("thief");
    
    Character *thePlayer4 = new Character(imageStore->getBitMap("mage") ,
        32 , 32 , 30 , 2 , PLAYER_MOVE_RATE);
    thePlayer4->setIdentifierName("mage");

    //CharacterList thePlayers;
    this->thePlayers->loadChar(thePlayer);
    this->thePlayers->loadChar(thePlayer2);
    this->thePlayers->loadChar(thePlayer3);
    this->thePlayers->loadChar(thePlayer4);

    std::vector<std::string> emptyStringVector;

    //Character stats
    CharStats *playerStats = new CharStats(1 , 1 , 10 , 100 , 100 , 10 , 1 , 100 ,
        10 , 1 , 0 , 0 , emptyStringVector);
    playerStats->setRole("Lancer");

    CharStats *playerStats2 = new CharStats(1 , 5 , 10 , 100 , 100 ,10 , 1 , 100 ,
        10 , 1 , 0 , 0 , emptyStringVector);
    playerStats2->setRole("Warrior");
    
    CharStats *playerStats3 = new CharStats(1 , 1 , 10 , 100 , 100 , 10 , 1 , 100 ,
        10 , 1 , 0 , 0, emptyStringVector);
    playerStats3->setRole("Thief");

    CharStats *playerStats4 = new CharStats(1 , 5 , 10 , 100 , 100 , 10 , 1 , 100 ,
        10 , 1 , 0 , 0 , emptyStringVector);
    playerStats4->setRole("Mage");

    thePlayer->setStats(playerStats);
    thePlayer2->setStats(playerStats2);
    thePlayer3->setStats(playerStats3);
    thePlayer4->setStats(playerStats4);

    thePlayer->loadAbilities("Lance;");
    thePlayer2->loadAbilities("Sword;");
    thePlayer3->loadAbilities("Dagger;");
    thePlayer4->loadAbilities("Staff;");

#ifdef ADD_TIER_2_ABILITIES
    thePlayer->addAbility("Skewer");
    thePlayer2->addAbility("Headbutt");
    thePlayer3->addAbility("Backstab");
    thePlayer4->addAbility("Fireball");
#endif

#ifdef ADD_TIER_3_ABILITIES
    thePlayer->addAbility("Cure");
    thePlayer2->addAbility("Bandage");
    thePlayer3->addAbility("Potion");
    thePlayer4->addAbility("Heal");
#endif

#ifdef ADD_TIER_4_ABILITIES
    thePlayer->addAbility("Jump");
    thePlayer2->addAbility("Shield Bash");
    thePlayer3->addAbility("Knife Barrage");
    thePlayer4->addAbility("Chain Lightning");
#endif

#ifdef ADD_TIER_5_ABILITIES
    thePlayer->addAbility("Fury of the Fang");
    thePlayer2->addAbility("Earth Shatter");
    thePlayer3->addAbility("Shade of the Crescent");
    thePlayer4->addAbility("Reign of Winter");
#endif

    /*
#ifdef MAX_LEVEL
    LevelUpCalculations::setCharacterToLevel(thePlayer , 10 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer2 , 10 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer3 , 10 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer4 , 10 , statsByLevelStore);
#endif
    */

#ifdef PROMOTE_ALL_PLAYERS_TO_LEVEL_2
    LevelUpCalculations::setCharacterToLevel(thePlayer , 2 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer2 , 2 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer3 , 2 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer4 , 2 , statsByLevelStore);
#endif

#ifdef PROMOTE_ALL_PLAYERS_TO_LEVEL_3
    LevelUpCalculations::setCharacterToLevel(thePlayer , 3 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer2 , 3 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer3 , 3 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer4 , 3 , statsByLevelStore);
#endif

#ifdef PROMOTE_ALL_PLAYERS_TO_LEVEL_4
    LevelUpCalculations::setCharacterToLevel(thePlayer , 4 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer2 , 4 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer3 , 4 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer4 , 4 , statsByLevelStore);
#endif

#ifdef PROMOTE_ALL_PLAYERS_TO_LEVEL_5
    LevelUpCalculations::setCharacterToLevel(thePlayer , 5 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer2 , 5 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer3 , 5 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer4 , 5 , statsByLevelStore);
#endif

#ifdef PROMOTE_ALL_PLAYERS_TO_LEVEL_6
    LevelUpCalculations::setCharacterToLevel(thePlayer , 6 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer2 , 6 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer3 , 6 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer4 , 6 , statsByLevelStore);
#endif

#ifdef PROMOTE_ALL_PLAYERS_TO_LEVEL_7
    LevelUpCalculations::setCharacterToLevel(thePlayer , 7 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer2 , 7 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer3 , 7 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer4 , 7 , statsByLevelStore);
#endif

#ifdef PROMOTE_ALL_PLAYERS_TO_LEVEL_8
    LevelUpCalculations::setCharacterToLevel(thePlayer , 8 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer2 , 8 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer3 , 8 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer4 , 8 , statsByLevelStore);
#endif

#ifdef PROMOTE_ALL_PLAYERS_TO_LEVEL_9
    LevelUpCalculations::setCharacterToLevel(thePlayer , 9 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer2 , 9 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer3 , 9 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer4 , 9 , statsByLevelStore);
#endif

#ifdef PROMOTE_ALL_PLAYERS_TO_LEVEL_10
    LevelUpCalculations::setCharacterToLevel(thePlayer , 10 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer2 , 10 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer3 , 10 , statsByLevelStore);
    LevelUpCalculations::setCharacterToLevel(thePlayer4 , 10 , statsByLevelStore);
#endif

    LevelUpCalculations::setHPToFull(thePlayer);
    LevelUpCalculations::setHPToFull(thePlayer2);
    LevelUpCalculations::setHPToFull(thePlayer3);
    LevelUpCalculations::setHPToFull(thePlayer4);
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