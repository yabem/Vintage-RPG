#include "StatsByLevelStore.h"

//Constructor.
StatsByLevelStore::StatsByLevelStore(){

}

//Destructor.
StatsByLevelStore::~StatsByLevelStore(){

    removeAllCharacterStats();
}

//Loads all the character stats.
//Pre:  The stats are not already loaded.
//Post: Allocates memory for each of the character stats.
void StatsByLevelStore::loadAllCharacterStats(){

    StatsByLevel *lancer = new StatsByLevel();
    lancer->resizeWithNulls();
    lancer->loadLevelStats(1 , 10 , 1 , 5 , 4 , 2 , 0);
    lancer->loadLevelStats(2 , 20 , 1 , 7 , 5 , 1.9 , 200);
    lancer->loadLevelStats(3 , 30 , 2 , 9 , 6 , 1.8 , 500);
    lancer->loadLevelStats(4 , 40 , 2 , 11 , 7 , 1.8 , 800);
    lancer->loadLevelStats(5 , 50 , 3 , 13 , 8 , 1.7 , 1100);
    lancer->loadLevelStats(6 , 60 , 3 , 15 , 9 , 1.6 , 1400);
    lancer->loadLevelStats(7 , 70 , 4 , 17 , 10 , 1.5 , 1700);
    lancer->loadLevelStats(8 , 80 , 4 , 19 , 11 , 1.4 , 2000);
    lancer->loadLevelStats(9 , 90 , 5 , 21 , 12 , 1.3 , 2300);
    lancer->loadLevelStats(10 , 100 , 5 , 23 , 13 , 1.2 , 2600);
    this->_statsStore.insert(std::pair<std::string , StatsByLevel*>("Lancer",lancer));

    StatsByLevel *warrior = new StatsByLevel();
    warrior->resizeWithNulls();
    warrior->loadLevelStats(1 , 10 , 1 , 5 , 4 , 2 , 0);
    warrior->loadLevelStats(2 , 20 , 1 , 7 , 5 , 1.9 , 200);
    warrior->loadLevelStats(3 , 30 , 2 , 9 , 6 , 1.8 , 500);
    warrior->loadLevelStats(4 , 40 , 2 , 11 , 7 , 1.8 , 800);
    warrior->loadLevelStats(5 , 50 , 3 , 13 , 8 , 1.7 , 1100);
    warrior->loadLevelStats(6 , 60 , 3 , 15 , 9 , 1.6 , 1400);
    warrior->loadLevelStats(7 , 70 , 4 , 17 , 10 , 1.5 , 1700);
    warrior->loadLevelStats(8 , 80 , 4 , 19 , 11 , 1.4 , 2000);
    warrior->loadLevelStats(9 , 90 , 5 , 21 , 12 , 1.3 , 2300);
    warrior->loadLevelStats(10 , 100 , 5 , 23 , 13 , 1.2 , 2600);
    this->_statsStore.insert(std::pair<std::string , StatsByLevel*>("Warrior",warrior));

    StatsByLevel *thief = new StatsByLevel();
    thief->resizeWithNulls();
    thief->loadLevelStats(1 , 10 , 1 , 5 , 4 , 2 , 0);
    thief->loadLevelStats(2 , 20 , 1 , 7 , 5 , 1.9 , 200);
    thief->loadLevelStats(3 , 30 , 2 , 9 , 6 , 1.8 , 500);
    thief->loadLevelStats(4 , 40 , 2 , 11 , 7 , 1.8 , 800);
    thief->loadLevelStats(5 , 50 , 3 , 13 , 8 , 1.7 , 1100);
    thief->loadLevelStats(6 , 60 , 3 , 15 , 9 , 1.6 , 1400);
    thief->loadLevelStats(7 , 70 , 4 , 17 , 10 , 1.5 , 1700);
    thief->loadLevelStats(8 , 80 , 4 , 19 , 11 , 1.4 , 2000);
    thief->loadLevelStats(9 , 90 , 5 , 21 , 12 , 1.3 , 2300);
    thief->loadLevelStats(10 , 100 , 5 , 23 , 13 , 1.2 , 2600);
    this->_statsStore.insert(std::pair<std::string , StatsByLevel*>("Thief",thief));

    StatsByLevel *mage = new StatsByLevel();
    mage->resizeWithNulls();
    mage->loadLevelStats(1 , 10 , 1 , 5 , 4 , 2 , 0);
    mage->loadLevelStats(2 , 20 , 1 , 7 , 5 , 1.9 , 200);
    mage->loadLevelStats(3 , 30 , 2 , 9 , 6 , 1.8 , 500);
    mage->loadLevelStats(4 , 40 , 2 , 11 , 7 , 1.8 , 800);
    mage->loadLevelStats(5 , 50 , 3 , 13 , 8 , 1.7 , 1100);
    mage->loadLevelStats(6 , 60 , 3 , 15 , 9 , 1.6 , 1400);
    mage->loadLevelStats(7 , 70 , 4 , 17 , 10 , 1.5 , 1700);
    mage->loadLevelStats(8 , 80 , 4 , 19 , 11 , 1.4 , 2000);
    mage->loadLevelStats(9 , 90 , 5 , 21 , 12 , 1.3 , 2300);
    mage->loadLevelStats(10 , 100 , 5 , 23 , 13 , 1.2 , 2600);
    this->_statsStore.insert(std::pair<std::string , StatsByLevel*>("Mage",mage));
}

//Removes all the character stats.
//Pre:  The StatsByLevelStore is already loaded.
//Post: Loops through and deallocates all each of the StatsByLevel.
void StatsByLevelStore::removeAllCharacterStats(){

    std::map<std::string , StatsByLevel*>::iterator statsIter;

    for(statsIter = _statsStore.begin() ; statsIter != _statsStore.end() ;
        statsIter++){

            delete (*statsIter).second;
            (*statsIter).second = NULL;
    }

    _statsStore.clear();
}

//Gets the HP for that character's level.
//Pre:  The level must be within the range of the StatsByLevel.
//Post: Returns the HP for that level.
int StatsByLevelStore::getHPForClassLevel(std::string characterClass , int level){

    return _statsStore.at(characterClass)->getHPAtLevel(level);
}

//Gets the MP for that character's level.
//Pre:  The level must be within the range of the StatsByLevel.
//Post: Returns the MP for that level.
int StatsByLevelStore::getMPForClassLevel(std::string characterClass , int level){

    return _statsStore.at(characterClass)->getMPAtLevel(level);
}

//Gets the Atk for that character's level.
//Pre:  The level must be within the range of the StatsByLevel.
//Post: Returns the Atk for that level.
int StatsByLevelStore::getAtkForClassLevel(std::string characterClass , int level){

    return _statsStore.at(characterClass)->getAtkAtLevel(level);
}

//Gets the Def for that character's level.
//Pre:  The level must be within the range of the StatsByLevel.
//Post: Returns the Def for that level.
int StatsByLevelStore::getDefForClassLevel(std::string characterClass , int level){
    
    return _statsStore.at(characterClass)->getDefAtLevel(level);
}

//Gets the Speed for that character's level.
//Pre:  The level must be within the range of the StatsByLevel.
//Post: Returns the Speed for that level.
int StatsByLevelStore::getSpeedForClassLevel(std::string characterClass , int level){

    return _statsStore.at(characterClass)->getSpeedAtLevel(level);
}

//Gets the XPForClassLevel for that character's level.
//Pre:  The level must be within the range of the StatsByLevel.
//Post: Returns the XPForClassLevel for that level.
int StatsByLevelStore::getXPForClassLevel(std::string characterClass , int level){

    return _statsStore.at(characterClass)->getXPToAchieveLevelAtLevel(level);
}