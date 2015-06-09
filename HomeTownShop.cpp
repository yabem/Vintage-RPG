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