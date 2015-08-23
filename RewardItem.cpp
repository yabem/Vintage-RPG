#include "RewardItem.h"

RewardItem::RewardItem(GameManager *gameManager ,ALLEGRO_FONT *font ,
    std::string itemToReward , int amountGained)
    : Dialogue(gameManager , font){

    this->itemToReward = itemToReward;
    this->amountGained = amountGained;
}

RewardItem::~RewardItem(){
    
}

//Rewards the specified player with a new Item.
bool RewardItem::play(const int pressedKey){

    //Animate player.
    gameManager->player->animate();
            
    //Animate the sceneries. 
    gameManager->currMap->animateSceneries();

    //Draw map.
    Draw::drawArea(*gameManager->currMap , *gameManager->player);

    textBox->draw();

    if(pressedKey == SPACE){
        
        I_InventoryItem *itemToAdd = new GenericItem(itemToReward , amountGained);
        this->gameManager->getPlayerEntity()->getPlayerInventory()->addItem(itemToAdd);
        
        return true;
    }

    else return false;
}
