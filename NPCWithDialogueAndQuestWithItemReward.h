//NPC says a message then a battle ensues.

#pragma once
#include "NPCWithDialogueAndGift.h"
#include "RewardItem.h"
#include "PlayerEntity.h"
#include "KillQuest.h"

class NPCWithDialogueAndQuestWithItemReward : public NPCWithDialogueAndGift{

protected:

    Quest *quest;
    std::string questExplanation;
    std::string questReminderExplanation;
    std::string questCompleteMessage;
    std::string questAfterCompleteMessage;
    int amountGained;

public:

    NPCWithDialogueAndQuestWithItemReward(ALLEGRO_BITMAP *image , int sx , int sy ,
        DrawRepository *drawRepository , GameManager *gameManager , 
        ALLEGRO_FONT *font , PlayerEntity *playerEntity);

    virtual ~NPCWithDialogueAndQuestWithItemReward();
    void loadQuest(Quest *quest);
    void setQuestExplanation(std::string questExplanation);
    void setQuestReminder(std::string questReminderExplanation);
    void setQuestCompleteMessage(std::string questCompleteMessage);
    void setQuestAfterCompleteMessage(std::string questAfterCompleteMessage);
    void setItemReward(std::string itemReward);
    void setAmountGained(int amount);
    virtual void playCutscene(int pressedKey);
};