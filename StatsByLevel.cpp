#include "StatsByLevel.h"

//Constructor
StatsByLevel::StatsByLevel(){

    _maxLevel = MAX_LEVEL_INDEX;
}

//Destructor
StatsByLevel::~StatsByLevel(){

    _maxLevel = 0;
    removeAllStats();
}

//Loads a list of stats for a particular level.
//Pre:  The level is below the max level possible.
//Post: Inserts a StatSheetForLevel object into the _listOfStats using the
//      level as the index.
void StatsByLevel::loadLevelStats(int level , int HP , int MP , int atk ,
        int def , float speed , int XPToAchieveLevel){

    std::vector<std::string> listOfRewards;

    StatSheetForLevel *statSheetForLevel = new StatSheetForLevel();
    statSheetForLevel->_level = level;
    statSheetForLevel->_HP = HP;
    statSheetForLevel->_MP = MP;
    statSheetForLevel->_Atk = atk;
    statSheetForLevel->_Def = def;
    statSheetForLevel->_speed = speed;
    statSheetForLevel->_XPToAchieveLevel = XPToAchieveLevel;

    _listOfStats[level] = statSheetForLevel;
}

//Gets the HP at the specified level.
//Pre: The level must be within the range of the vector.
//Post: Returns the HP for that level.
int StatsByLevel::getHPAtLevel(int level){

    return _listOfStats[level]->_HP;
}

//Gets the MP at the specified level.
//Pre: The level must be within the range of the vector.
//Post: Returns the MP for that level.
int StatsByLevel::getMPAtLevel(int level){

    return _listOfStats[level]->_MP;
}

//Gets the Atk at the specified level.
//Pre: The level must be within the range of the vector.
//Post: Returns the Atk for that level.
int StatsByLevel::getAtkAtLevel(int level){

    return _listOfStats[level]->_Atk;
}

//Gets the Def at the specified level.
//Pre: The level must be within the range of the vector.
//Post: Returns the Def for that level.
int StatsByLevel::getDefAtLevel(int level){

    return _listOfStats[level]->_Def;
}

//Gets the Speed at the specified level.
//Pre: The level must be within the range of the vector.
//Post: Returns the Speed for that level.
float StatsByLevel::getSpeedAtLevel(int level){

    return _listOfStats[level]->_speed;
}

//Gets the XPToAchieveLevel at the specified level.
//Pre: The level must be within the range of the vector.
//Post: Returns the XPToAchieveLevel for that level.
int StatsByLevel::getXPToAchieveLevelAtLevel(int level){

    return _listOfStats[level]->_XPToAchieveLevel;
}

//Removes all of the stats objects.
//Pre:  The StatsByLevel is valid.
//Post: Cycles through all of the levels and deletes each StatSheetForLevel object 
//      that is stored in the list.
void StatsByLevel::removeAllStats(){

    std::vector<StatSheetForLevel*>::iterator statsIter = _listOfStats.begin();

    for(statsIter = _listOfStats.begin() ; statsIter != _listOfStats.end() ;
        statsIter++){

        delete (*statsIter);
        (*statsIter) = NULL;
    }

    _listOfStats.clear();
}

//Resizes the _listOfStats to _maxLevel and inserts NULL pointers 
//into each position in the vector.
//Pre:  None.
//Post: Puts StatSheetForLevel pointers that are set to NULL into every available position. 
void StatsByLevel::resizeWithNulls(){

    StatSheetForLevel *statSheetForLevel = NULL;
    _listOfStats.resize(_maxLevel , statSheetForLevel);
}