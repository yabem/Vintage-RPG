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
    lancer->loadLevelStats(1 , 100 , 1 , 10 , 5 , 0 , 2.5 , 200);
    lancer->loadLevelStats(2 , 200 , 1 , 15 , 6 , 0 , 2.4 , 400);
    lancer->loadLevelStats(3 , 300 , 2 , 20 , 7 , 0 , 2.4 , 700);
    lancer->loadLevelStats(4 , 400 , 2 , 25 , 8 , 0 , 2.4 , 1100);
    lancer->loadLevelStats(5 , 500 , 3 , 30 , 10 , 0 , 2.3 , 1600);
    lancer->loadLevelStats(6 , 600 , 3 , 35 , 13 , 0 , 2.3 , 2200);
    lancer->loadLevelStats(7 , 700 , 4 , 40 , 16 , 0 , 2.2 , 2900);
    lancer->loadLevelStats(8 , 800 , 4 , 45 , 19 , 0 , 2.2 , 3700);
    lancer->loadLevelStats(9 , 900 , 5 ,  50, 22 , 0 , 2.1 , 4600);
    lancer->loadLevelStats(10 , 1000 , 5 , 55 , 25 , 0 , 2.0 , 5600);
    this->_statsStore.insert(std::pair<std::string , StatsByLevel*>("Lancer",lancer));

    StatsByLevel *warrior = new StatsByLevel();
    warrior->resizeWithNulls();
    warrior->loadLevelStats(1 , 175 , 1 , 10 , 8 , 0 , 3.0 , 200);
    warrior->loadLevelStats(2 , 250 , 1 , 13 , 16 , 0 , 2.9 , 400);
    warrior->loadLevelStats(3 , 325 , 2 , 16 , 24 , 0 , 2.8 , 700);
    warrior->loadLevelStats(4 , 400 , 2 , 19 , 32 , 0 , 2.8 , 1100);
    warrior->loadLevelStats(5 , 475 , 3 , 22 , 40 , 0 , 2.7 , 1600);
    warrior->loadLevelStats(6 , 450 , 3 , 25 , 48 , 0 , 2.7 , 2200);
    warrior->loadLevelStats(7 , 525 , 4 , 28 , 56 , 0 , 2.6 , 2900);
    warrior->loadLevelStats(8 , 600 , 4 , 31 , 64 , 0 , 2.6 , 3700);
    warrior->loadLevelStats(9 , 675 , 5 , 34 , 72 , 0 , 2.5 , 4600);
    warrior->loadLevelStats(10 , 750 , 5 , 37 , 80 , 0 , 2.5 , 5600);
    this->_statsStore.insert(std::pair<std::string , StatsByLevel*>("Warrior",warrior));

    StatsByLevel *thief = new StatsByLevel();
    thief->resizeWithNulls();
    thief->loadLevelStats(1 , 100 , 1 , 10 , 10 , 0 , 2.2 , 200);
    thief->loadLevelStats(2 , 150 , 1 , 18 , 16 , 0 , 2.1 , 400);
    thief->loadLevelStats(3 , 210 , 2 , 26 , 19 , 0 , 2.0 , 700);
    thief->loadLevelStats(4 , 260 , 2 , 34 , 22 , 0 , 2.0 , 1100);
    thief->loadLevelStats(5 , 300 , 3 , 42 , 25 , 0 , 1.9 , 1600);
    thief->loadLevelStats(6 , 340 , 3 , 50 , 28 , 0 , 1.8 , 2200);
    thief->loadLevelStats(7 , 380 , 4 , 58 , 31 , 0 , 1.7 , 2900);
    thief->loadLevelStats(8 , 420 , 4 , 66, 34 , 0 , 1.7 , 3700);
    thief->loadLevelStats(9 , 460 , 5 , 74 , 37 , 0 , 1.6 , 4600);
    thief->loadLevelStats(10 , 500 , 5 , 82 , 40 , 0 , 1.5 , 5600);
    this->_statsStore.insert(std::pair<std::string , StatsByLevel*>("Thief",thief));

    StatsByLevel *mage = new StatsByLevel();
    mage->resizeWithNulls();
    mage->loadLevelStats(1 , 100 , 1 , 10 , 10 , 0 , 4.0 , 200);
    mage->loadLevelStats(2 , 150 , 1 , 11 , 20 , 0 , 3.9 , 400);
    mage->loadLevelStats(3 , 210 , 2 , 12 , 30 , 0 , 3.8 , 700);
    mage->loadLevelStats(4 , 260 , 2 , 13 , 40 , 0 , 3.7 , 1100);
    mage->loadLevelStats(5 , 300 , 3 , 14 , 50 , 0 , 3.6 , 1600);
    mage->loadLevelStats(6 , 340 , 3 , 15 , 60 , 0 , 3.5 , 2200);
    mage->loadLevelStats(7 , 380 , 4 , 16 , 70 , 0 , 3.4 , 2900);
    mage->loadLevelStats(8 , 420 , 4 , 17 , 80 , 0 , 3.3 , 3700);
    mage->loadLevelStats(9 , 460 , 5 , 18 , 90 , 0 , 3.2 , 4600);
    mage->loadLevelStats(10 , 500 , 5 , 19 , 100 , 0 , 3.0 , 5600);
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