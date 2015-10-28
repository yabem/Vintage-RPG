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
    lancer->loadLevelStats(1 , 50 , 1 , 10 , 5 , 0 , 2.5 , 200);
    lancer->loadLevelStats(2 , 90 , 1 , 15 , 8 , 0 , 2.4 , 600);
    lancer->loadLevelStats(3 , 130 , 2 , 20 , 11 , 0 , 2.4 , 1200);
    lancer->loadLevelStats(4 , 170 , 2 , 25 , 14 , 0 , 2.4 , 2000);
    lancer->loadLevelStats(5 , 210 , 3 , 30 , 17 , 0 , 2.3 , 3000);
    lancer->loadLevelStats(6 , 250 , 3 , 35 , 20 , 0 , 2.3 , 4100);
    lancer->loadLevelStats(7 , 290 , 4 , 40 , 23 , 0 , 2.2 , 5300);
    lancer->loadLevelStats(8 , 330 , 4 , 45 , 26 , 0 , 2.2 , 6600);
    lancer->loadLevelStats(9 , 370 , 5 ,  50, 30 , 0 , 2.1 , 8000);
    lancer->loadLevelStats(10 , 410 , 5 , 55 , 35 , 0 , 2.0 , 9500);
    this->_statsStore.insert(std::pair<std::string , StatsByLevel*>("Lancer",lancer));

    StatsByLevel *warrior = new StatsByLevel();
    warrior->resizeWithNulls();
    warrior->loadLevelStats(1 , 50 , 1 , 10 , 8 , 0 , 3.0 , 200);
    warrior->loadLevelStats(2 , 100 , 1 , 13 , 16 , 0 , 2.9 , 600);
    warrior->loadLevelStats(3 , 150 , 2 , 16 , 24 , 0 , 2.8 , 1200);
    warrior->loadLevelStats(4 , 200 , 2 , 19 , 32 , 0 , 2.8 , 2000);
    warrior->loadLevelStats(5 , 250 , 3 , 22 , 40 , 0 , 2.7 , 3000);
    warrior->loadLevelStats(6 , 300 , 3 , 25 , 48 , 0 , 2.7 , 4100);
    warrior->loadLevelStats(7 , 350 , 4 , 28 , 56 , 0 , 2.6 , 5300);
    warrior->loadLevelStats(8 , 400 , 4 , 31 , 64 , 0 , 2.6 , 6600);
    warrior->loadLevelStats(9 , 450 , 5 , 34 , 72 , 0 , 2.5 , 8000);
    warrior->loadLevelStats(10 , 500 , 5 , 37 , 80 , 0 , 2.5 , 9500);
    this->_statsStore.insert(std::pair<std::string , StatsByLevel*>("Warrior",warrior));

    StatsByLevel *thief = new StatsByLevel();
    thief->resizeWithNulls();
    thief->loadLevelStats(1 , 50 , 1 , 10 , 10 , 0 , 2.2 , 200);
    thief->loadLevelStats(2 , 75 , 1 , 18 , 16 , 0 , 2.1 , 600);
    thief->loadLevelStats(3 , 100 , 2 , 26 , 19 , 0 , 2.0 , 1200);
    thief->loadLevelStats(4 , 125 , 2 , 34 , 22 , 0 , 2.0 , 2000);
    thief->loadLevelStats(5 , 150 , 3 , 42 , 25 , 0 , 1.9 , 3000);
    thief->loadLevelStats(6 , 175 , 3 , 50 , 28 , 0 , 1.8 , 4100);
    thief->loadLevelStats(7 , 200 , 4 , 58 , 31 , 0 , 1.7 , 5300);
    thief->loadLevelStats(8 , 225 , 4 , 66, 34 , 0 , 1.7 , 6600);
    thief->loadLevelStats(9 , 250 , 5 , 74 , 37 , 0 , 1.6 , 8000);
    thief->loadLevelStats(10 , 275 , 5 , 82 , 40 , 0 , 1.5 , 9500);
    this->_statsStore.insert(std::pair<std::string , StatsByLevel*>("Thief",thief));

    StatsByLevel *mage = new StatsByLevel();
    mage->resizeWithNulls();
    mage->loadLevelStats(1 , 50 , 1 , 10 , 10 , 0 , 4.0 , 200);
    mage->loadLevelStats(2 , 70 , 1 , 11 , 20 , 0 , 3.9 , 600);
    mage->loadLevelStats(3 , 90 , 2 , 12 , 30 , 0 , 3.8 , 1200);
    mage->loadLevelStats(4 , 110 , 2 , 13 , 40 , 0 , 3.7 , 2000);
    mage->loadLevelStats(5 , 130 , 3 , 14 , 50 , 0 , 3.6 , 3000);
    mage->loadLevelStats(6 , 150 , 3 , 15 , 60 , 0 , 3.5 , 4100);
    mage->loadLevelStats(7 , 170 , 4 , 16 , 70 , 0 , 3.4 , 5300);
    mage->loadLevelStats(8 , 190 , 4 , 17 , 80 , 0 , 3.3 , 6600);
    mage->loadLevelStats(9 , 210 , 5 , 18 , 90 , 0 , 3.2 , 8000);
    mage->loadLevelStats(10 , 230 , 5 , 19 , 100 , 0 , 3.0 , 9500);
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

//Gets the Mgc for that character's level.
//Pre:  The level must be within the range of the StatsByLevel.
//Post: Returns the Mgc for that level.
int StatsByLevelStore::getMgcForClassLevel(std::string characterClass , int level){

    return _statsStore.at(characterClass)->getMgcAtLevel(level);
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