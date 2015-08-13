#include "HomeTownBar.h"

HomeTownBar::HomeTownBar(ImageStore *imageStore ,  DrawRepository *drawRepository ,
        GameManager *gameManager , BattleManager *battleManager , FontStore *fontStore ,
        int layoutSize) : CustomAreaMap(imageStore , drawRepository , gameManager , 
        battleManager , fontStore , layoutSize){
}

HomeTownBar::~HomeTownBar(){

}

void HomeTownBar::loadLayers(){

    Layer *backgroundLayer = new Layer(imageStore->getBitMap("town") ,
        8 , 8 , this->backgroundLayerLayout , 64);
    Layer *shopCollisionLayer = new Layer(imageStore->getBitMap("town") ,
        8 , 8 , this->collisionLayerLayout , 64);

    this->loadLayer(backgroundLayer);
    this->loadLayer(shopCollisionLayer);
}

//Loads all of the map configurations for each of the layers.
void HomeTownBar::loadAllMapConfigurationsForLayers(){

    loadBackgroundLayerConfiguration();
    loadShopCollisionLayerConfiguration();
}

void HomeTownBar::loadTheTangibles(){

    ItemLocationWithGift *treasureBarrelWithRecoverForWarrior = new ItemLocationWithGift(
        imageStore->getBitMap("treasureBarrel") ,
        Conversion::convertTilesToPixels(6) , 
        Conversion::convertTilesToPixels(5) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    treasureBarrelWithRecoverForWarrior->setRewardNotification(
        "Warrior learned the Recover ability!");
    treasureBarrelWithRecoverForWarrior->setGift(
        "warrior" , "Recover");
    treasureBarrelWithRecoverForWarrior->setMessageAfterGiftDelivery(
        "The barrel is empty, weirdo.");

    this->loadTangible(treasureBarrelWithRecoverForWarrior);
}

void HomeTownBar::loadBackgroundLayerConfiguration(){

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

void HomeTownBar::loadShopCollisionLayerConfiguration(){

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