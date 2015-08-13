#include "HomeTownShop.h"

HomeTownShop::HomeTownShop(ImageStore *imageStore ,  DrawRepository *drawRepository ,
        GameManager *gameManager , BattleManager *battleManager , FontStore *fontStore ,
        int layoutSize) : CustomAreaMap(imageStore , drawRepository , gameManager , 
        battleManager , fontStore , layoutSize){
}

HomeTownShop::~HomeTownShop(){

}

void HomeTownShop::loadLayers(){

    Layer *backgroundLayer = new Layer(imageStore->getBitMap("town") ,
        8 , 8 , this->backgroundLayerLayout , 64);
    Layer *shopCollisionLayer = new Layer(imageStore->getBitMap("town") ,
        8 , 8 , this->collisionLayerLayout , 64);

    this->loadLayer(backgroundLayer);
    this->loadLayer(shopCollisionLayer);
}

//Loads all of the map configurations for each of the layers.
void HomeTownShop::loadAllMapConfigurationsForLayers(){

    loadBackgroundLayerConfiguration();
    loadShopCollisionLayerConfiguration();
}

void HomeTownShop::loadTheTangibles(){

    NPCWithDialogueAndQuest *timberMan = new NPCWithDialogueAndQuest(
        imageStore->getBitMap("friendlyGentleman") ,
        Conversion::convertTilesToPixels(4) , 
        Conversion::convertTilesToPixels(4) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    timberMan->createCharacter(32 , 32 , 60 , 2 , 4 , this);
    timberMan->setCW(32);
    timberMan->setCH(32);
    timberMan->setCharacterFacing(DOWN);
    timberMan->setQuestExplanation(
        "Timber Man: It's a secret to most people but you. Anyway. "  
        "There's a goo problem in my building. I think it's coming from "
        "the goo monsters in the south. If you're traveling in the forest, can "
        "you kill a bunch of them to show just how mean I am? You know, cause that "
        "will make me feel better. Bring back some goo clumps as proof." );
    timberMan->setQuestReminder(
        "Timber Man: How is the gooooooos the hunting, get it? ");
    timberMan->setQuestCompleteMessage(
        "Timber Man: Fantastic! You did it! You look pretty filthy now so, just "
        "take this and leave.");
    timberMan->setRewardNotification(
        "Thief received the Backstab ability!");
    timberMan->setGift("thief" , "Backstab");
    timberMan->setQuestAfterCompleteMessage(
        "Timber Man: Great job, now get out!"
        );

    GatherQuest *questObjectives = new GatherQuest(
        gameManager->getPlayerEntity()->getPlayerInventory());
    questObjectives->setQuestDisplayName("Timber Man and My Goo");
    questObjectives->addObjective("Small Goo" , 10);
    questObjectives->addObjective("Medium Goo" , 5);
    questObjectives->addObjective("Large Goo" , 2);
    timberMan->loadQuest(questObjectives);
    gameManager->getPlayerEntity()->addQuest("gooQuest" , questObjectives);

    ItemLocationWithGift *treasureBarrelWithRecoverForMage = new ItemLocationWithGift(
        imageStore->getBitMap("treasureBox1") ,
        Conversion::convertTilesToPixels(1) , 
        Conversion::convertTilesToPixels(4) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    treasureBarrelWithRecoverForMage->setRewardNotification(
        "Mage learned the Recover ability!");
    treasureBarrelWithRecoverForMage->setGift(
        "mage" , "Recover");
    treasureBarrelWithRecoverForMage->setMessageAfterGiftDelivery(
        "Nothing is inside you thief!");

    this->loadTangible(timberMan);
    this->loadTangible(treasureBarrelWithRecoverForMage);
}

void HomeTownShop::loadBackgroundLayerConfiguration(){

    int backgroundLayerLayout[] ={
        28,28,28,28,28,28,28,28,
        28,28,28,28,28,28,28,28,
        125,125,125,125,125,125,125,125,
        126,126,126,126,126,126,126,126,
        126,126,126,126,126,126,126,126,
        126,126,126,126,126,126,126,126,
        126,126,126,126,126,126,126,126,
        126,126,126,126,126,126,126,126
    };

    this->backgroundLayerLayout = new int[this->layoutSize];

    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->backgroundLayerLayout[i] = backgroundLayerLayout[i];
}

void HomeTownShop::loadShopCollisionLayerConfiguration(){

    int shopCollisionLayerLayout[] ={
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        127,127,127,127,127,127,127,127,
        127, 0, 0, 0, 0, 0, 0, 127,
        127, 0, 0, 0, 0, 0, 0, 127,
        127, 0, 0, 0, 0, 0, 0, 127,
        127, 0, 0, 0, 0, 0, 0, 127
    };

    this->collisionLayerLayout = new int[this->layoutSize];

    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->collisionLayerLayout[i] = shopCollisionLayerLayout[i];
}