#include "NPCWithDialogueAndGift.h"

NPCWithDialogueAndGift::NPCWithDialogueAndGift(ALLEGRO_BITMAP *image , int sx , int sy ,
    DrawRepository *drawRepository , GameManager *gameManager , 
    std::string message , ALLEGRO_FONT *font , PlayerEntity *playerEntity) : 
    NPCWithDialogue(image , sx , sy , drawRepository , gameManager , message , font){

    this->font = font;
    this->playerEntity = playerEntity;
    this->giftDelivered = false;
    this->messageAfterGiftDelivery = "";
    this->rewardNotification = "";
}

NPCWithDialogueAndGift::~NPCWithDialogueAndGift(){

}

void NPCWithDialogueAndGift::setGift(std::string playerToReward ,
    std::string abilityToReward){

        this->playerToReward = playerToReward;
        this->abilityToReward = abilityToReward;
}

void NPCWithDialogueAndGift::setMessageAfterGiftDelivery(
    std::string messageAfterGiftDelivery){

    this->messageAfterGiftDelivery = messageAfterGiftDelivery; 
}

void NPCWithDialogueAndGift::setRewardNotification(
    std::string rewardNotification){

    this->rewardNotification = rewardNotification;
}

void NPCWithDialogueAndGift::playCutscene(int pressedKey){

    if(!this->giftDelivered){

        Dialogue *cutscene = new Dialogue(gameManager , font);
        cutscene->setText(message);
        this->drawRepository->loadCutscene(cutscene);

        RewardAbility *rewardAbility = new RewardAbility(gameManager , font ,
            playerToReward , playerEntity->getThePlayers() , abilityToReward);
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