#pragma once
#include "NPCWithDialogueAndGift.h"
#include "RewardAbility.h"
#include "PlayerEntity.h"
#include "KillQuest.h"
#include "RemoveTangible.h"

class NPCWithQuestAndRemoval : public NPCWithDialogueAndGift{

protected:

    Quest *quest;
    std::string questExplanation;
    std::string questReminderExplanation;
    std::string questCompleteMessage;
    std::string nameOfNPC;

public:

    NPCWithQuestAndRemoval(ALLEGRO_BITMAP *image , int sx , int sy ,
        DrawRepository *drawRepository , GameManager *gameManager , 
        ALLEGRO_FONT *font , PlayerEntity *playerEntity , std::string nameOfNPC);

    virtual ~NPCWithQuestAndRemoval();
    void loadQuest(Quest *quest);
    void setQuestExplanation(std::string questExplanation);
    void setQuestReminder(std::string questReminderExplanation);
    void setQuestCompleteMessage(std::string questCompleteMessage);
    virtual void playCutscene(int pressedKey);
};