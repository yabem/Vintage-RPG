#include "BattleTransitionScreen.h"

BattleTransitionScreen::BattleTransitionScreen(ImageStore *imageStore){

    this->imageStore = imageStore;
    this->sizeOfBattleTransitionScreenLayout 
        = BATTLE_TRANSITION_SCREEN_LAYOUT_SIZE;
}

BattleTransitionScreen::~BattleTransitionScreen(){

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

void BattleTransitionScreen::loadLayers(){

    Layer *backgroundLayer = new Layer(imageStore->getBitMap("terrain") ,
        15 , 20 , this->backgroundLayerLayout , 300);

    this->loadLayer(backgroundLayer);
}

void BattleTransitionScreen::loadAllMapConfigurationsForLayers(){

    loadBackgroundLayerConfiguration();
}

void BattleTransitionScreen::loadBackgroundLayerConfiguration(){
    
    int backgroundLayerLayout[] ={
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12
    };

    this->backgroundLayerLayout = 
        new int[this->sizeOfBattleTransitionScreenLayout];

    for(int i = 0 ; i < this->sizeOfBattleTransitionScreenLayout ; i++)    
        this->backgroundLayerLayout[i] = backgroundLayerLayout[i];
}

void BattleTransitionScreen::deleteAllLayerConfigurations(){

    delete this->backgroundLayerLayout;
    this->backgroundLayerLayout = NULL;
}

void BattleTransitionScreen::loadDefaults(){

    this->loadAllMapConfigurationsForLayers();
    this->loadLayers();
}