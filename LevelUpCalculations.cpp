#include "LevelUpCalculations.h"

//Levels up the list of characters.
//Pre:  The CharacterList and all Characters in the list are valid.
//Post: All the characters are leveled up until they are at the 
//      apporpriate level.
std::vector<std::string> LevelUpCalculations::levelUpListOfCharacters(
    CharacterList *characterList , StatsByLevelStore *statsByLevelStore
    , DrawRepository *drawRepository){

        std::vector<std::string> allCharactersSummary;

        characterList->resetSelection();

        for(int i = 0 ; i < characterList->getSize() ; i++){
            
            std::vector<std::string> individualCharactersSummary;
            
            individualCharactersSummary = 
                LevelUpCalculations::levelUpCharacter(
                characterList->getCurrSelection(), 
                statsByLevelStore ,
                drawRepository);

            allCharactersSummary.insert(
                allCharactersSummary.end() , 
                individualCharactersSummary.begin() ,
                individualCharactersSummary.end());

            characterList->moveSelectionDown();
        }

        characterList->resetSelection();

        return allCharactersSummary;
}

//Levels up the character if enough xp is reached.
//Pre:  The character and statsByLevelStore are valid.
//Post: Sets the new stats based on the class and level sheet. Continues
//      to level up until the character's currXP is less than the amount
//      required to level.
std::vector<std::string> LevelUpCalculations::levelUpCharacter(Character *character, 
    StatsByLevelStore *statsByLevelStore , DrawRepository *drawRepository){

        std::vector<std::string> levelUpSummary;

        while(character->getStats()->hasLeveledUp()){
           
            std::string levelUpInfo = LevelUpCalculations::getNewStatsSummary(
                character , statsByLevelStore);

            int currLevel = character->getStats()->getLevel();
            int nextLevel = currLevel + 1;

            LevelUpCalculations::setCharacterToLevel(character , nextLevel , 
                statsByLevelStore);
            LevelUpCalculations::setHPToFull(character);

            levelUpSummary.push_back(levelUpInfo);
        }

        return levelUpSummary;
}

//Creates a summary for the level up.
//Pre:  The character must have leveled up.
//Post: The difference between the new stats and the old stats is returned.
std::string LevelUpCalculations::getNewStatsSummary(Character *character , 
    StatsByLevelStore *statsByLevelStore){

        std::string levelUpInfo = "";
        Stats *theStats = character->getStats();

        int currentLevel = theStats->getLevel();
        int nextLevel = theStats->getLevel() + 1;
        std::string theClass = theStats->getRole();

        int hpIncrease = statsByLevelStore->getHPForClassLevel(theClass , nextLevel) -
            theStats->getBaseHP();
            
        int mpIncrease = statsByLevelStore->getMPForClassLevel(theClass , nextLevel) -
            theStats->getBaseMP();

        int atkIncrease = statsByLevelStore->getAtkForClassLevel(theClass , nextLevel) -
            theStats->getBaseAtk();

        int mgcIncrease = statsByLevelStore->getMgcForClassLevel(theClass , nextLevel) -
            theStats->getBaseMgc();

        int defIncrease = statsByLevelStore->getDefForClassLevel(theClass , nextLevel) -
            theStats->getBaseDef();

        float speedIncrease = statsByLevelStore->getSpeedForClassLevel(theClass , nextLevel) -
            theStats->getSpeed();

        levelUpInfo += theClass;
        levelUpInfo += " is now level " + 
            Conversion::convertIntToString(nextLevel); 
        levelUpInfo += "! Hp +" + 
            Conversion::convertIntToString(hpIncrease);
        levelUpInfo += ". Atk +" + 
            Conversion::convertIntToString(atkIncrease);
        levelUpInfo += ". Mgc +" + 
            Conversion::convertIntToString(mgcIncrease);
        levelUpInfo += ". Speed " + 
            Conversion::convertFloatToString(speedIncrease);
        levelUpInfo += ".";

        return levelUpInfo;
}
/*
//Sets all the character's stats to the appropriate level.
//Pre:  None.
//Post: All the character's base stats are set to the 
//      appropriate level and class.
void LevelUpCalculations::setNewStats(Character *character , 
    StatsByLevelStore *statsByLevelStore){

        int currLevel = character->getStats()->getLevel();
        int nextLevel = currLevel + 1;
        
        LevelUpCalculations::setCharacterToLevel(
            character , nextLevel , statsByLevelStore);
        /*
        std::string theClass = character->getStats()->getRole();

        //Sets all of the base stats.
        character->getStats()->setLevel(nextLevel); 
        character->getStats()->setBaseHP(
            statsByLevelStore->getHPForClassLevel(theClass , nextLevel));
        character->getStats()->setBaseMP(
            statsByLevelStore->getMPForClassLevel(theClass , nextLevel));
        character->getStats()->setBaseAtk(
            statsByLevelStore->getAtkForClassLevel(theClass , nextLevel));
        character->getStats()->setBaseDef(
            statsByLevelStore->getDefForClassLevel(theClass , nextLevel));
        character->getStats()->setSpeed(
            statsByLevelStore->getSpeedForClassLevel(theClass , nextLevel));

        character->getStats()->setToLvlXP(
            statsByLevelStore->getXPForClassLevel(theClass , nextLevel));
        
}
*/

//Sets the character to the desired level.
//Pre:  The Character and the StatsByLevelStore are valid. The level
//      is > 0 and < the max level allowed.
//Post: The Character is set to the specified level.  
void LevelUpCalculations::setCharacterToLevel(Character *character , int level , 
    StatsByLevelStore *statsByLevelStore){

        std::string theClass = character->getStats()->getRole();

        //Sets all of the base stats.
        character->getStats()->setLevel(level); 
        character->getStats()->setBaseHP(
            statsByLevelStore->getHPForClassLevel(theClass , level));
        character->getStats()->setBaseMP(
            statsByLevelStore->getMPForClassLevel(theClass , level));
        character->getStats()->setBaseAtk(
            statsByLevelStore->getAtkForClassLevel(theClass , level));
        character->getStats()->setBaseMgc(
            statsByLevelStore->getMgcForClassLevel(theClass , level));
        character->getStats()->setBaseDef(
            statsByLevelStore->getDefForClassLevel(theClass , level));
        character->getStats()->setSpeed(
            statsByLevelStore->getSpeedForClassLevel(theClass , level));

        //Set current level XP to previous level's to level XP.
        if(level != 1){
            character->getStats()->setTtlXPGained(statsByLevelStore->getXPForClassLevel(theClass , level - 1));
        }
        
        character->getStats()->setToLvlXP(
            statsByLevelStore->getXPForClassLevel(theClass , level));
}

//Refills the character's HP.
//Pre:  The character is valid.
//Post: Sets the character's baseHP to ttlHP.
void LevelUpCalculations::setHPToFull(Character *character){

    character->getStats()->setCurrHP(character->getStats()->getTtlHP());
}

