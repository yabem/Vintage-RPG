//NPC says a message then a battle ensues.

#pragma once
#include "NPCWithDialogue.h"
#include "RewardAbility.h"
#include "PlayerEntity.h"

class NPCWithDialogueAndGift : public NPCWithDialogue{

protected:

    ALLEGRO_FONT *font;
    PlayerEntity *playerEntity;
    std::string playerToReward;
    std::string reward;
    bool giftDelivered;
    std::string messageAfterGiftDelivery;
    std::string rewardNotification;

public:

    NPCWithDialogueAndGift(ALLEGRO_BITMAP *image , int sx , int sy ,
        DrawRepository *drawRepository , GameManager *gameManager , 
        std::string message , ALLEGRO_FONT *font , PlayerEntity *playerEntity);

    virtual void setGift(std::string playerToReward , std::string reward);
    virtual void setMessageAfterGiftDelivery(std::string messageAfterGiftDelivery);
    virtual void setRewardNotification(std::string rewardNotification);
    virtual ~NPCWithDialogueAndGift();
    virtual void playCutscene(int pressedKey);
};