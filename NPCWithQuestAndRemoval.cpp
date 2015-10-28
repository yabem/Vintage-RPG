#include "NPCWithQuestAndRemoval.h"

NPCWithQuestAndRemoval::NPCWithQuestAndRemoval(ALLEGRO_BITMAP *image , int sx , int sy ,
    DrawRepository *drawRepository , GameManager *gameManager ,
    ALLEGRO_FONT *font , PlayerEntity *playerEntity , std::string nameOfNPC) : 
    NPCWithDialogueAndGift(image , sx , sy , drawRepository , gameManager , "" , font ,
        playerEntity){

        this->quest = NULL;
        this->questExplanation = "";
        this->questReminderExplanation = "";
        this->questCompleteMessage = "";
        this->nameOfNPC = nameOfNPC;
}

NPCWithQuestAndRemoval::~NPCWithQuestAndRemoval(){

}

void NPCWithQuestAndRemoval::loadQuest(Quest *quest){

    this->quest = quest;
}

void NPCWithQuestAndRemoval::setQuestExplanation(
    std::string questExplanation){
    
        this->questExplanation = questExplanation;
}

void NPCWithQuestAndRemoval::setQuestReminder(
    std::string questReminderExplanation){

        this->questReminderExplanation = questReminderExplanation;
}
    
void NPCWithQuestAndRemoval::setQuestCompleteMessage(
    std::string questCompleteMessage){

        this->questCompleteMessage = questCompleteMessage;
}

void NPCWithQuestAndRemoval::playCutscene(int pressedKey){

    if(!quest->isActiveForPlayer() && !quest->isTurnedInByPlayer()){

        Dialogue *explainQuest = new Dialogue(gameManager , font);
        explainQuest->setText(questExplanation);
        this->drawRepository->loadCutscene(explainQuest);

        Dialogue *questNotification = new Dialogue(gameManager , font);

        std::string questNotificationText = "You received the quest ---" +
            quest->getQuestDisplayName() + "---!";
        questNotification->setText(questNotificationText);
        this->drawRepository->loadCutscene(questNotification);

        quest->makeActiveForPlayer();
    }

    else if(!quest->completedByPlayer()){

        Dialogue *remindAboutQuest = new Dialogue(gameManager , font);
        remindAboutQuest->setText(questReminderExplanation);
        this->drawRepository->loadCutscene(remindAboutQuest);
    }

    else{

        Dialogue *questComplete = new Dialogue(gameManager , font);
        questComplete->setText(questCompleteMessage);
        this->drawRepository->loadCutscene(questComplete);

        Dialogue *rewardDelivery = new Dialogue(gameManager , font);
        rewardDelivery->setText(rewardNotification);
        this->drawRepository->loadCutscene(rewardDelivery);

        quest->makeInactiveForPlayer();
        quest->removeQuestItemsFromBackPack();
        quest->makeTurnedInByPlayer();

        RemoveTangible *removeTangible = new RemoveTangible(this->gameManager ,
            this->nameOfNPC);
        this->drawRepository->loadCutscene(removeTangible);
    }

    gameManager->resetPressedKey();
}