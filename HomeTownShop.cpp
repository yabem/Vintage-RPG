#include "HomeTownShop.h"

HomeTownShop::HomeTownShop(ImageStore *imageStore){

    this->imageStore = imageStore;
    this->sizeHomeTownShopLayout = HOME_TOWN_SHOP_LAYOUT_SIZE;
}

HomeTownShop::~HomeTownShop(){

    /*
    vector<Scenery*>::iterator sceneryIter = sceneries.begin();

    while(sceneryIter != sceneries.end()){

        delete (*sceneryIter);
        (*sceneryIter) = NULL;
        sceneryIter++;
    }

    sceneries.clear();

    vector<Layer*>::iterator layerIter = layers.begin();

    while(layerIter != layers.end()){

        delete (*layerIter);
        (*layerIter) = NULL;
        layerIter++;
    }
    layers.clear();
    */
    deleteAllLayerConfigurations();
}

void HomeTownShop::loadDefaults(){

    this->loadAllMapConfigurationsForLayers();
    this->loadLayers();
}

void HomeTownShop::loadLayers(){

    Layer *backgroundLayer = new Layer(imageStore->getBitMap("town") ,
        8 , 8 , this->backgroundLayerLayout , 64);
    Layer *shopCollisionLayer = new Layer(imageStore->getBitMap("town") ,
        8 , 8 , this->shopCollisionLayerLayout , 64);

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

    this->backgroundLayerLayout = new int[this->sizeHomeTownShopLayout];

    for(int i = 0 ; i < this->sizeHomeTownShopLayout ; i++)    
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

    this->shopCollisionLayerLayout = new int[this->sizeHomeTownShopLayout];

    for(int i = 0 ; i < this->sizeHomeTownShopLayout ; i++)    
        this->shopCollisionLayerLayout[i] = shopCollisionLayerLayout[i];
}

void HomeTownShop::deleteAllLayerConfigurations(){

    delete this->backgroundLayerLayout;
    this->backgroundLayerLayout = NULL;

    delete this->shopCollisionLayerLayout;
    this->shopCollisionLayerLayout = NULL;
}