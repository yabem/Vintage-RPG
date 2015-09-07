#include "HomeTownArmory.h"

HomeTownArmory::HomeTownArmory(ImageStore *imageStore ,  DrawRepository *drawRepository ,
        GameManager *gameManager , BattleManager *battleManager , FontStore *fontStore ,
        int layoutSize) : CustomAreaMap(imageStore , drawRepository , gameManager , 
        battleManager , fontStore , layoutSize){
}

HomeTownArmory::~HomeTownArmory(){

}

void HomeTownArmory::loadLayers(){

    Layer *backgroundLayer = new Layer(imageStore->getBitMap("town") ,
        8 , 8 , this->backgroundLayerLayout , 64);
    Layer *shopCollisionLayer = new Layer(imageStore->getBitMap("town") ,
        8 , 8 , this->collisionLayerLayout , 64);

    this->loadLayer(backgroundLayer);
    this->loadLayer(shopCollisionLayer);
}

//Loads all of the map configurations for each of the layers.
void HomeTownArmory::loadAllMapConfigurationsForLayers(){

    loadBackgroundLayerConfiguration();
    loadShopCollisionLayerConfiguration();
}

void HomeTownArmory::loadTheTangibles(){

    ItemLocationWithGift *treasureBarrelWithRecoverForThief = new ItemLocationWithGift(
        imageStore->getBitMap("treasureBox1") ,
        Conversion::convertTilesToPixels(5) , 
        Conversion::convertTilesToPixels(4) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    treasureBarrelWithRecoverForThief->setRewardNotification(
        "Thief learned the Recover ability!");
    treasureBarrelWithRecoverForThief->setGift(
        "thief" , "Recover");
    treasureBarrelWithRecoverForThief->setMessageAfterGiftDelivery(
        "Nothing worth noting.");

    NPCWithDialogue *joanna = new NPCWithDialogue(
        imageStore->getBitMap("joanna") ,
        Conversion::convertTilesToPixels(2) , 
        Conversion::convertTilesToPixels(4) ,        
        this->drawRepository ,
        this->gameManager , 
        "Joanna: Dickle punch with lightning! Oh yeah! Where am I? What's a going on?" ,
        this->fontStore->getFont("default"));
    joanna->createCharacter(32 , 32 , 60 , 2 , 4 , this);
    joanna->setCW(32);
    joanna->setCH(32);
    joanna->setCharacterFacing(DOWN);

    this->loadTangible(treasureBarrelWithRecoverForThief);
    this->loadTangible(joanna);
}

void HomeTownArmory::loadBackgroundLayerConfiguration(){

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

void HomeTownArmory::loadShopCollisionLayerConfiguration(){

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