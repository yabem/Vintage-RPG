#include "RewardAbility.h"

RewardAbility::RewardAbility(GameManager *gameManager , ALLEGRO_FONT *introFont ,
    std::string playerToReward ,CharacterList *characterList ,
    std::string abilityToReward) : Dialogue(gameManager , introFont){

    this->characterList = characterList;
    this->playerToReward = playerToReward;
    this->abilityToReward = abilityToReward;
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
        this->playerToReward , this->characterList , this->abilityToReward);
        
        return true;
    }

    else return false;
}
