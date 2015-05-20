#include "SouthernForestBattle.h"

SouthernForestBattle::SouthernForestBattle(ImageStore *imageStore){

    this->imageStore = imageStore;
    this->sizeOfBattleCutsceneLayout = 
        SOUTHERN_FOREST_BATTLE_SCREEN_LAYOUT_SIZE;
}

SouthernForestBattle::~SouthernForestBattle(){

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

    deleteAllLayerConfigurations();
}

void SouthernForestBattle::loadLayers(){

    Layer *backgroundLayer = new Layer(imageStore->getBitMap("desertRegion") ,
        15 , 20 , this->backgroundLayerLayout , 300);

    this->loadLayer(backgroundLayer);
}

void SouthernForestBattle::loadAllMapConfigurationsForLayers(){

    loadBackgroundLayerConfiguration();
}

void SouthernForestBattle::loadBackgroundLayerConfiguration(){
    
    int backgroundLayerLayout[] ={
        150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,
        150,150,
        114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,
        114,
        152,152,152,152,152,152,152,152,152,152,152,152,152,152,152,152,152,152,152,
        152,
        153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,
        153,
        154,154,154,154,154,154,154,154,154,154,154,154,154,154,154,154,154,154,154,
        154,
        155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,
        155,
        156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,
        156,
        156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,
        156,
        156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,
        156,
        156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,
        156,
        156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,
        156,
        156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,
        156,
        156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,
        156,
        156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,
        156,
        156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,
        156
    };

    this->backgroundLayerLayout = new int[this->sizeOfBattleCutsceneLayout];
    for(int i = 0 ; i < this->sizeOfBattleCutsceneLayout ; i++)    
        this->backgroundLayerLayout[i] = backgroundLayerLayout[i];
}

void SouthernForestBattle::deleteAllLayerConfigurations(){

    delete this->backgroundLayerLayout;
    this->backgroundLayerLayout = NULL;
}

void SouthernForestBattle::loadDefaults(){

    this->loadAllMapConfigurationsForLayers();
    this->loadLayers();
}