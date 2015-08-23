#include "NPCWithDialogueAndQuestWithItemReward.h"

NPCWithDialogueAndQuestWithItemReward::NPCWithDialogueAndQuestWithItemReward(
    ALLEGRO_BITMAP *image , int sx , int sy ,
    DrawRepository *drawRepository , GameManager *gameManager ,
    ALLEGRO_FONT *font , PlayerEntity *playerEntity) : 
    NPCWithDialogueAndGift(image , sx , sy , drawRepository , gameManager , "" , font ,
        playerEntity){

        this->quest = NULL;
        this->questExplanation = "";
        this->questReminderExplanation = "";
        this->questCompleteMessage = "";
}

NPCWithDialogueAndQuestWithItemReward::~NPCWithDialogueAndQuestWithItemReward(){

}

void NPCWithDialogueAndQuestWithItemReward::loadQuest(Quest *quest){

    this->quest = quest;
}

void NPCWithDialogueAndQuestWithItemReward::setQuestExplanation(
    std::string questExplanation){
    
        this->questExplanation = questExplanation;
}

void NPCWithDialogueAndQuestWithItemReward::setQuestReminder(
    std::string questReminderExplanation){

        this->questReminderExplanation = questReminderExplanation;
}
    
void NPCWithDialogueAndQuestWithItemReward::setQuestCompleteMessage(
    std::string questCompleteMessage){

        this->questCompleteMessage = questCompleteMessage;
}

void NPCWithDialogueAndQuestWithItemReward::setQuestAfterCompleteMessage(
    std::string questAfterCompleteMessage){

        this->questAfterCompleteMessage = questAfterCompleteMessage;
}

void NPCWithDialogueAndQuestWithItemReward::setAmountGained(int amount){
    
    amountGained = amount;
}

void NPCWithDialogueAndQuestWithItemReward::setItemReward(std::string itemReward){

    this->reward = itemReward;
}

void NPCWithDialogueAndQuestWithItemReward::playCutscene(int pressedKey){

    if(!quest->isActiveForPlayer()){

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

    else if(!giftDelivered){

        Dialogue *deliverGift = new Dialogue(gameManager , font);
        deliverGift->setText(questCompleteMessage);
        this->drawRepository->loadCutscene(deliverGift);

        RewardItem *rewardItem = new RewardItem(
            gameManager , font , reward , amountGained);
        rewardItem->setText(rewardNotification);
        this->drawRepository->loadCutscene(rewardItem);

        quest->makeInactiveForPlayer();
        quest->removeQuestItemsFromBackPack();
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