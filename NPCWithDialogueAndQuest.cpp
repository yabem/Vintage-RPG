#include "NPCWithDialogueAndQuest.h"

NPCWithDialogueAndQuest::NPCWithDialogueAndQuest(ALLEGRO_BITMAP *image , int sx , int sy ,
    DrawRepository *drawRepository , GameManager *gameManager ,
    ALLEGRO_FONT *font , PlayerEntity *playerEntity) : 
    NPCWithDialogueAndGift(image , sx , sy , drawRepository , gameManager , "" , font ,
        playerEntity){

        this->quest = NULL;
        this->questExplanation = "";
        this->questReminderExplanation = "";
        this->questCompleteMessage = "";
}

NPCWithDialogueAndQuest::~NPCWithDialogueAndQuest(){

}

void NPCWithDialogueAndQuest::loadQuest(Quest *quest){

    this->quest = quest;
}

void NPCWithDialogueAndQuest::setQuestExplanation(
    std::string questExplanation){
    
        this->questExplanation = questExplanation;
}

void NPCWithDialogueAndQuest::setQuestReminder(
    std::string questReminderExplanation){

        this->questReminderExplanation = questReminderExplanation;
}
    
void NPCWithDialogueAndQuest::setQuestCompleteMessage(
    std::string questCompleteMessage){

        this->questCompleteMessage = questCompleteMessage;
}

void NPCWithDialogueAndQuest::setQuestAfterCompleteMessage(
    std::string questAfterCompleteMessage){

        this->questAfterCompleteMessage = questAfterCompleteMessage;
}

void NPCWithDialogueAndQuest::playCutscene(int pressedKey){

    if(!quest->isActiveForPlayer()){

        Dialogue *explainQuest = new Dialogue(gameManager , font);
        explainQuest->setText(questExplanation);
        this->drawRepository->loadCutscene(explainQuest);

        quest->makeActiveForPlayer();
    }

    else if(!quest->completedByPlayer()){

        Dialogue *remindAboutQuest = new Dialogue(gameManager , font);
        remindAboutQuest->setText(questReminderExplanation);
        this->drawRepository->loadCutscene(remindAboutQuest);
    }

    else if(!giftDelivered){

        Dialogue *deliverGift = new Dialogue(gameManager , font);
        deliverGift->setText(questCompleteMessage);
        this->drawRepository->loadCutscene(deliverGift);

        RewardAbility *rewardAbility = new RewardAbility(gameManager , font ,
            playerToReward , playerEntity->getThePlayers() , abilityToReward);
        rewardAbility->setText(rewardNotification);
        this->drawRepository->loadCutscene(rewardAbility);

        quest->makeInactiveForPlayer();
        quest->completedByPlayer();
        giftDelivered = true;
    }

    else{

        Dialogue *cutscene = new Dialogue(gameManager , font);
        cutscene->setText(questAfterCompleteMessage);
        this->drawRepository->loadCutscene(cutscene);
    }

    gameManager->resetPressedKey();
}