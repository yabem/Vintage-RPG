#include "RewardAbility.h"

RewardAbility::RewardAbility(GameManager *gameManager , ALLEGRO_FONT *font ,
    std::string playerToReward ,CharacterList *characterList ,
    std::string reward) : Dialogue(gameManager , font){

    this->characterList = characterList;
    this->playerToReward = playerToReward;
    this->reward = reward;
}

RewardAbility::~RewardAbility(){

}

//Rewards the specified player with a new ability.
bool RewardAbility::play(const int pressedKey){

    //Animate player.
    gameManager->player->animate();
            
    //Animate the sceneries. 
    gameManager->currMap->animateSceneries();

    //Draw map.
    Draw::drawArea(*gameManager->currMap , *gameManager->player);

    textBox->draw();

    if(pressedKey == SPACE){
        
        AddAbilityToCharacterInList::AddAbilityToCharacterInList(
        this->playerToReward , this->characterList , this->reward);
        
        return true;
    }

    else return false;
}
