#include "BattleVictory.h"

//Constructor.
BattleVictory::BattleVictory(){

    frameCount = 0;
}

//Constructor with parameters.
BattleVictory::BattleVictory(AreaMap *currMap , CharacterList *characterList ,
    I_Manager *i_Manager , TreasureBox *treasureBox){

    frameCount = 0;
    mapSwitch = 1;
    this->currMap = currMap;
    this->characterList = characterList;
    this->i_Manager = i_Manager;
    this->treasureBox = treasureBox;

    createVictoryMessage();
    createCelebratingPlayers();
}

//Destructor.
BattleVictory::~BattleVictory(){

    if(playersForVictoryCelebration.size() > 0)
        deletePlayers();
}

//Deletes all of the Characters and reclaims the allocated memory.
void BattleVictory::deletePlayers(){

    std::vector<Character*>::iterator charIter = 
        this->playersForVictoryCelebration.begin();
        
    while(charIter != playersForVictoryCelebration.end()){

        delete (*charIter);
        charIter++;
    }

    playersForVictoryCelebration.clear();
}

//Creates the players for the celebration.
void BattleVictory::createCelebratingPlayers(){

    characterList->resetSelection(); 

    for(int i = 0 ; i < characterList->getSize() ; i++){

        Character *copyOfCharacter = new Character();
        *copyOfCharacter = *characterList->getCurrSelection();
        playersForVictoryCelebration.push_back(copyOfCharacter);

        if(!characterList->currSelectionIsDead()){
            copyOfCharacter->setFacing(CELEBRATE);
        }

        characterList->moveSelectionDown();
    }
}

//Animates all the characters that are still alive.
void BattleVictory::playCelebratingPlayers(){

    std::vector<Character*>::iterator charIter = 
        this->playersForVictoryCelebration.begin();

    while(charIter != playersForVictoryCelebration.end()){

        if(!(*charIter)->isDead()){
            (*charIter)->animate();
        }

        (*charIter)->draw();
        charIter++;
    }
}

//Creates the summary of rewards.
void BattleVictory::createVictoryMessage(){

    std::string victoryMessage = "";
    victoryMessage += "You have slain all the enemies! ";
    victoryMessage += "You gained ";

    int numberOfRewards = treasureBox->getSize();
    char qty[10];
    for(int i = 0 ; i < numberOfRewards ; i++){
    
        _itoa_s(treasureBox->getFrontRewardAmount(), qty , 10);

        if(i == (numberOfRewards - 1) && numberOfRewards >= 2)
            victoryMessage += " and ";

        victoryMessage += qty;
        victoryMessage += " ";
        victoryMessage += treasureBox->getFrontRewardName();

        //Add s when not XP and Gold.
        if(treasureBox->getFrontRewardName() != "XP" && 
            treasureBox->getFrontRewardName() != "Gold" &&
            treasureBox->getFrontRewardAmount() > 1)
            victoryMessage += "s";
        
        treasureBox->removeReward(treasureBox->getFrontRewardName());
        
        if(i != (numberOfRewards - 1) && numberOfRewards > 2)
            victoryMessage += ", ";
    }

    victoryMessage += ".";
    textBox.loadText(victoryMessage);
}

//Plays the battle victory. The cutscene switches back and forth
//between the current map and a white background.
bool BattleVictory::play(const int pressedKey){
    
    frameCount++;

    Draw::drawArea(*currMap);

    playCelebratingPlayers();

    textBox.draw();

    if(pressedKey == SPACE){

        deletePlayers();

        i_Manager->switchVariablesToMap();
        return true;
    }

    else return false;
}