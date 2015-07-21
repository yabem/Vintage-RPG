#include "CustomAreaMap.h"

//Constructor.
CustomAreaMap::CustomAreaMap(ImageStore *imageStore ,  DrawRepository *drawRepository ,
        GameManager *gameManager , BattleManager *battleManager , FontStore *fontStore ,
         int layoutSize){

    this->imageStore = imageStore;
    this->layoutSize = layoutSize;
    this->drawRepository = drawRepository;
    this->gameManager = gameManager;
    this->battleManager = battleManager;
    this->fontStore = fontStore;

    backgroundLayerLayout = NULL;
    collisionLayerLayout = NULL;
    canGoBehindLayerLayout = NULL;

    minEnemyLevel = 0;
    maxEnemyLevel = 0;
}

//Destructor.
CustomAreaMap::~CustomAreaMap(){

    deleteAllLayerConfigurations();
}

//Loads all the default values and objects.
void CustomAreaMap::loadDefaults(){

    this->loadTheSceneries();
    this->loadTheTangibles();
    this->loadAllMapConfigurationsForLayers();
    this->loadLayers();
    this->loadMapEnemies();
}

//Loads all the cloud Scenery objects.
void CustomAreaMap::loadTheSceneries(){}

//Load the interactive models.
void CustomAreaMap::loadTheTangibles(){}

//Loads all the layers to the areaMap.
void CustomAreaMap::loadLayers(){}

//Loads the background layer.
void CustomAreaMap::loadBackgroundLayerMapConfiguration(){}

//Loads the collision layer.
void CustomAreaMap::loadCollisionLayerMapConfiguration(){}
    
//Loads the can go behind layer.
void CustomAreaMap::loadCanGoBehindLayerMapConfiguration(){}

//Loads all of the map configurations for each of the layers.
void CustomAreaMap::loadAllMapConfigurationsForLayers(){

    loadBackgroundLayerMapConfiguration();
    loadCollisionLayerMapConfiguration();
    loadCanGoBehindLayerMapConfiguration();
}

void CustomAreaMap::deleteAllLayerConfigurations(){

    delete this->backgroundLayerLayout;
    this->backgroundLayerLayout = NULL;

    delete this->collisionLayerLayout;
    this->collisionLayerLayout = NULL;

    delete this->canGoBehindLayerLayout;
    this->canGoBehindLayerLayout = NULL;
}