#include "WesternDesertBattle.h"

WesternDesertBattle::WesternDesertBattle(ImageStore *imageStore){

    this->imageStore = imageStore;
    this->sizeOfBattleCutsceneLayout = 
        WESTERN_DESERT_BATTLE_LAYOUT_SIZE;
}

WesternDesertBattle::~WesternDesertBattle(){

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

void WesternDesertBattle::loadLayers(){

    Layer *backgroundLayer = new Layer(imageStore->getBitMap("terrain") ,
        15 , 20 , this->backgroundLayerLayout , 300);

    this->loadLayer(backgroundLayer);
}

void WesternDesertBattle::loadAllMapConfigurationsForLayers(){

    loadBackgroundLayerConfiguration();
}

void WesternDesertBattle::loadBackgroundLayerConfiguration(){
    
    int backgroundLayerLayout[] ={
        43,43,43,43,43,43,44,45,46,45,16,16,16,16,46,17,47,43,43,43,
        48,48,48,48,48,48,44,17,17,17,17,17,17,17,17,17,47,49,48,48,
        48,48,48,48,48,48,44,17,17,17,17,17,17,17,17,17,47,49,48,48,
        48,48,48,48,48,48,44,17,17,17,17,17,17,17,17,17,47,49,48,48,
        48,48,48,48,48,48,44,17,17,17,17,17,17,17,17,17,47,49,48,48,
        50,51,51,51,51,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,
        50,51,51,51,51,50,50,50,50,50,50,50,50,50,50,51,51,51,51,50,
        50,51,51,51,51,50,50,50,50,50,50,50,50,50,50,51,51,51,51,50,
        50,51,51,51,51,50,50,50,50,50,50,50,50,50,50,51,51,51,51,50,
        50,51,51,51,51,50,50,50,50,50,50,52,53,50,50,51,51,51,51,50,
        50,51,51,51,51,50,50,50,50,50,50,54,55,50,50,51,51,51,51,50,
        50,51,51,51,51,50,50,50,50,50,50,50,50,50,50,51,51,51,51,50,
        52,53,51,51,51,50,50,50,50,50,50,50,50,50,50,51,51,51,51,50,
        54,55,51,51,51,50,50,50,50,50,50,50,50,50,50,51,51,51,51,50,
        50,51,51,51,51,50,50,50,50,50,50,50,50,50,50,51,51,51,52,53
    };

    this->backgroundLayerLayout = new int[this->sizeOfBattleCutsceneLayout];
    for(int i = 0 ; i < this->sizeOfBattleCutsceneLayout ; i++)    
        this->backgroundLayerLayout[i] = backgroundLayerLayout[i];
}

void WesternDesertBattle::deleteAllLayerConfigurations(){

    delete this->backgroundLayerLayout;
    this->backgroundLayerLayout = NULL;
}

void WesternDesertBattle::loadDefaults(){

    this->loadAllMapConfigurationsForLayers();
    this->loadLayers();
}