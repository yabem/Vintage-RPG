#include "EasternCastleBattle.h"

EasternCastleBattle::EasternCastleBattle(ImageStore *imageStore){

    this->imageStore = imageStore;
    this->sizeOfBattleCutsceneLayout = BATTLE_SCREEN_LAYOUT_SIZE;
}

EasternCastleBattle::~EasternCastleBattle(){

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

void EasternCastleBattle::loadLayers(){

    Layer *backgroundLayer = new Layer(imageStore->getBitMap("terrain") ,
        15 , 20 , this->backgroundLayerLayout , 300);

    this->loadLayer(backgroundLayer);
}

void EasternCastleBattle::loadAllMapConfigurationsForLayers(){

    loadBackgroundLayerConfiguration();
}

void EasternCastleBattle::loadBackgroundLayerConfiguration(){
    
    int backgroundLayerLayout[] ={
        12,12,12,13,12,12,13,12,13,14,15,15,15,12,12,12,13,14,14,13,
        16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
        17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
        18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,19,20,20,21,1,1,1,10,8,10,1,1,1,1,1,1,1,1,3,
        1,22,23,23,24,1,3,1,1,10,1,1,1,1,1,19,20,20,21,1,
        3,22,25,26,24,1,1,1,1,1,1,1,1,1,1,22,23,23,24,1,
        1,22,27,28,24,1,1,29,1,1,1,30,1,1,1,22,23,23,24,1,
        1,22,23,23,24,1,1,2,1,1,1,1,1,1,1,22,23,23,24,1,
        1,22,23,23,24,1,1,1,1,1,1,1,1,6,1,22,23,23,24,1,
        1,22,23,23,24,1,31,30,1,1,1,1,1,1,1,22,23,23,24,1,
        2,22,23,23,24,1,1,1,5,1,1,1,1,1,11,22,23,23,24,31,
        1,22,25,26,24,1,1,1,1,1,1,1,11,1,11,22,23,23,24,4,
        1,22,27,28,24,1,1,1,1,1,11,7,3,7,11,22,23,23,24,8
    };

    this->backgroundLayerLayout = new int[this->sizeOfBattleCutsceneLayout];
    for(int i = 0 ; i < this->sizeOfBattleCutsceneLayout ; i++)    
        this->backgroundLayerLayout[i] = backgroundLayerLayout[i];
}

void EasternCastleBattle::deleteAllLayerConfigurations(){

    delete this->backgroundLayerLayout;
    this->backgroundLayerLayout = NULL;
}

void EasternCastleBattle::loadDefaults(){

    this->loadAllMapConfigurationsForLayers();
    this->loadLayers();
}