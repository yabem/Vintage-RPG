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
    lancer->loadLevelStats(1 , 100 , 1 , 100 , 4 , .5 , 0);
    lancer->loadLevelStats(2 , 150 , 1 , 150 , 5 , .5 , 200);
    lancer->loadLevelStats(3 , 200 , 2 , 21 , 6 , .5 , 500);
    lancer->loadLevelStats(4 , 250 , 2 , 28 , 7 , .5 , 800);
    lancer->loadLevelStats(5 , 300 , 3 , 36 , 8 , 1.7 , 1100);
    lancer->loadLevelStats(6 , 350 , 3 , 45 , 9 , 1.6 , 1400);
    lancer->loadLevelStats(7 , 400 , 4 , 55 , 10 , 1.5 , 1700);
    lancer->loadLevelStats(8 , 450 , 4 , 66 , 11 , 1.4 , 2000);
    lancer->loadLevelStats(9 , 500 , 5 , 78 , 12 , 1.3 , 2300);
    lancer->loadLevelStats(10 , 550 , 5 , 91 , 13 , 1.2 , 2600);
    this->_statsStore.insert(std::pair<std::string , StatsByLevel*>("Lancer",lancer));

    StatsByLevel *warrior = new StatsByLevel();
    warrior->resizeWithNulls();
    warrior->loadLevelStats(1 , 100 , 1 , 100 , 4 , 1.5 , 0);
    warrior->loadLevelStats(2 , 200 , 1 , 140 , 5 , 1.9 , 200);
    warrior->loadLevelStats(3 , 300 , 2 , 18 , 6 , 1.8 , 500);
    warrior->loadLevelStats(4 , 400 , 2 , 23, 7 , 1.8 , 800);
    warrior->loadLevelStats(5 , 500 , 3 , 28 , 8 , 1.7 , 1100);
    warrior->loadLevelStats(6 , 600 , 3 , 34 , 9 , 1.6 , 1400);
    warrior->loadLevelStats(7 , 700 , 4 , 40 , 10 , 1.5 , 1700);
    warrior->loadLevelStats(8 , 800 , 4 , 47 , 11 , 1.4 , 2000);
    warrior->loadLevelStats(9 , 900 , 5 , 55 , 12 , 1.3 , 2300);
    warrior->loadLevelStats(10 , 1000 , 5 , 64 , 13 , 1.2 , 2600);
    this->_statsStore.insert(std::pair<std::string , StatsByLevel*>("Warrior",warrior));

    StatsByLevel *thief = new StatsByLevel();
    thief->resizeWithNulls();
    thief->loadLevelStats(1 , 100 , 1 , 200 , 4 , 1.4 , 0);
    thief->loadLevelStats(2 , 130 , 1 , 300 , 5 , 1.9 , 200);
    thief->loadLevelStats(3 , 160 , 2 , 40 , 6 , 1.8 , 500);
    thief->loadLevelStats(4 , 190 , 2 , 50 , 7 , 1.8 , 800);
    thief->loadLevelStats(5 , 220 , 3 , 60 , 8 , 1.7 , 1100);
    thief->loadLevelStats(6 , 250 , 3 , 70 , 9 , 1.6 , 1400);
    thief->loadLevelStats(7 , 280 , 4 , 80 , 10 , 1.5 , 1700);
    thief->loadLevelStats(8 , 310 , 4 , 90 , 11 , 1.4 , 2000);
    thief->loadLevelStats(9 , 340 , 5 , 110 , 12 , 1.3 , 2300);
    thief->loadLevelStats(10 , 370 , 5 , 120 , 13 , 1.2 , 2600);
    this->_statsStore.insert(std::pair<std::string , StatsByLevel*>("Thief",thief));

    StatsByLevel *mage = new StatsByLevel();
    mage->resizeWithNulls();
    mage->loadLevelStats(1 , 100 , 1 , 200 , 4 , 1.2 , 0);
    mage->loadLevelStats(2 , 125 , 1 , 270 , 5 , 1.9 , 200);
    mage->loadLevelStats(3 , 150 , 2 , 34 , 6 , 1.8 , 500);
    mage->loadLevelStats(4 , 175 , 2 , 41 , 7 , 1.8 , 800);
    mage->loadLevelStats(5 , 200 , 3 , 48 , 8 , 1.7 , 1100);
    mage->loadLevelStats(6 , 225 , 3 , 59 , 9 , 1.6 , 1400);
    mage->loadLevelStats(7 , 250 , 4 , 70 , 10 , 1.5 , 1700);
    mage->loadLevelStats(8 , 275 , 4 , 81 , 11 , 1.4 , 2000);
    mage->loadLevelStats(9 , 300 , 5 , 92 , 12 , 1.3 , 2300);
    mage->loadLevelStats(10 , 325 , 5 , 103 , 13 , 1.2 , 2600);
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
float StatsByLevelStore::getSpeedForClassLevel(std::string characterClass , int level){

    return _statsStore.at(characterClass)->getSpeedAtLevel(level);
}

//Gets the XPForClassLevel for that character's level.
//Pre:  The level must be within the range of the StatsByLevel.
//Post: Returns the XPForClassLevel for that level.
int StatsByLevelStore::getXPForClassLevel(std::string characterClass , int level){

    return _statsStore.at(characterClass)->getXPToAchieveLevelAtLevel(level);
}