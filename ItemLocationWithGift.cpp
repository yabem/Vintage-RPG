#include "ItemLocationWithGift.h"

ItemLocationWithGift::ItemLocationWithGift(ALLEGRO_BITMAP *image , int sx , int sy ,
    DrawRepository *drawRepository , GameManager *gameManager ,
    ALLEGRO_FONT *font , PlayerEntity *playerEntity) : 
    NPCWithDialogueAndGift(image , sx , sy , drawRepository , gameManager , 
    "" , font , playerEntity){

}

ItemLocationWithGift::~ItemLocationWithGift(){

}

void ItemLocationWithGift::draw(){

    al_draw_bitmap_region(image , 
    0 , 0 ,     //X and y draw from on bitmap.
    w , h ,     //X and y draw to on bitmap.
    dx , dy , 0);              
}

void ItemLocationWithGift::playCutscene(int pressedKey){

    if(!this->giftDelivered){

        RewardAbility *rewardAbility = new RewardAbility(gameManager , font ,
            playerToReward , playerEntity->getThePlayers() , reward);
        rewardAbility->setText(rewardNotification);
        this->drawRepository->loadCutscene(rewardAbility);

        giftDelivered = true;
    }
    else{

        Dialogue *cutscene = new Dialogue(gameManager , font);
        cutscene->setText(messageAfterGiftDelivery);
        this->drawRepository->loadCutscene(cutscene);
    }

    gameManager->resetPressedKey();
}