#include "LevelUpCalculations.h"

//Levels up the list of characters.
//Pre:  The CharacterList and all Characters in the list are valid.
//Post: All the characters are leveled up until they are at the 
//      apporpriate level.
void LevelUpCalculations::levelUpListOfCharacters(
    CharacterList *characterList , StatsByLevelStore *statsByLevelStore){

        characterList->resetSelection();

        for(int i = 0 ; i < characterList->getSize() ; i++){
            
            LevelUpCalculations::levelUpCharacter(
                characterList->getCurrSelection(), statsByLevelStore);

            characterList->moveSelectionDown();
        }

        characterList->resetSelection();
}

//Levels up the character if enough xp is reached.
//Pre:  The character and statsByLevelStore are valid.
//Post: Sets the new stats based on the class and level sheet. Continues
//      to level up until the character's currXP is less than the amount
//      required to level.
void LevelUpCalculations::levelUpCharacter(Character *character, 
    StatsByLevelStore *statsByLevelStore){

        while(character->getStats()->hasLeveledUp()){
            
            LevelUpCalculations::setNewStats(character , statsByLevelStore);
            LevelUpCalculations::setHPToFull(character);
        }
}

//Sets all the character's stats to the appropriate level.
//Pre:  None.
//Post: All the character's base stats are set to the 
//      appropriate level and class.
void LevelUpCalculations::setNewStats(Character *character , 
    StatsByLevelStore *statsByLevelStore){

        int currLevel = character->getStats()->getLevel();
        int nextLevel = currLevel + 1;
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

//Refills the character's HP.
//Pre:  The character is valid.
//Post: Sets the character's baseHP to ttlHP.
void LevelUpCalculations::setHPToFull(Character *character){

    character->getStats()->setCurrHP(character->getStats()->getTtlHP());
}