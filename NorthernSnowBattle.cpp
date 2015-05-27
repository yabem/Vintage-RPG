#include "NorthernSnowBattle.h"

NorthernSnowBattle::NorthernSnowBattle(ImageStore *imageStore){

    this->imageStore = imageStore;
    this->sizeOfBattleCutsceneLayout = NORTHERN_SNOW_BATTLE_LAYOUT_SIZE;
}

NorthernSnowBattle::~NorthernSnowBattle(){
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

void NorthernSnowBattle::loadLayers(){

    Layer *backgroundLayer = new Layer(imageStore->getBitMap("terrain") ,
        15 , 20 , this->backgroundLayerLayout , 300);

    this->loadLayer(backgroundLayer);
}

void NorthernSnowBattle::loadAllMapConfigurationsForLayers(){

    loadBackgroundLayerConfiguration();
}

void NorthernSnowBattle::loadBackgroundLayerConfiguration(){
    
    int backgroundLayerLayout[] ={
        35,36,37,37,38,35,36,37,38,35,35,39,39,40,39,39,39,40,39,39,
        37,37,37,37,37,37,37,37,37,37,37,39,39,39,39,39,39,39,39,39,
        37,37,37,37,37,37,37,37,37,37,37,39,39,40,39,39,39,40,39,39,
        41,41,41,41,41,41,41,41,41,41,41,39,39,39,39,39,39,39,39,39,
        42,42,42,42,42,42,42,42,42,42,42,39,39,39,39,39,39,39,39,39,
        42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,
        42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,
        12,42,42,42,42,12,12,12,12,12,12,12,12,12,12,42,42,42,42,12,
        12,42,42,42,42,12,12,12,12,12,12,12,12,12,12,42,42,42,42,12,
        12,42,42,42,42,12,12,12,12,12,12,12,12,12,12,42,42,42,42,12,
        12,42,42,42,42,12,12,12,12,12,12,12,12,12,12,42,42,42,42,12,
        12,42,42,42,42,12,12,12,12,12,12,12,12,12,12,42,42,42,42,12,
        12,42,42,42,42,12,12,12,12,12,12,12,12,12,12,42,42,42,42,12,
        12,42,42,42,42,12,12,12,12,12,12,12,12,12,12,42,42,42,42,12,
        12,42,42,42,42,12,12,12,12,12,12,12,12,12,12,42,42,42,42,12
    };

    this->backgroundLayerLayout = new int[this->sizeOfBattleCutsceneLayout];
    for(int i = 0 ; i < this->sizeOfBattleCutsceneLayout ; i++)    
        this->backgroundLayerLayout[i] = backgroundLayerLayout[i];
}

void NorthernSnowBattle::deleteAllLayerConfigurations(){

    delete this->backgroundLayerLayout;
    this->backgroundLayerLayout = NULL;
}

void NorthernSnowBattle::loadDefaults(){

    this->loadAllMapConfigurationsForLayers();
    this->loadLayers();
}