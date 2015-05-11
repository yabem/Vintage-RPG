#include "SouthernForest.h"

//Constructor.
SouthernForest::SouthernForest(ImageStore *imageStore){

    this->imageStore = imageStore;
    this->layoutSize = SOUTHERN_FOREST_LAYOUT_SIZE;

    backgroundLayerLayout = NULL;
    collisionLayerLayout = NULL;
    canGoBehindLayerLayout = NULL;
}

//Destructor.
SouthernForest::~SouthernForest(){

    vector<Scenery*>::iterator sceneryIter = sceneries.begin();

    while(sceneryIter != sceneries.end()){

        delete (*sceneryIter);
        (*sceneryIter) = NULL;
        sceneryIter++;
    }

    sceneries.clear();

    vector<Tangible*>::iterator tangiblesIter = tangibles.begin();

    while(tangiblesIter != tangibles.end()){

        delete (*tangiblesIter);
        (*tangiblesIter) = NULL;
        tangiblesIter++;
    }

    tangibles.clear();

    vector<Layer*>::iterator layerIter = layers.begin();

    while(layerIter != layers.end()){

        delete (*layerIter);
        (*layerIter) = NULL;
        layerIter++;
    }
    layers.clear();

    deleteAllLayerConfigurations();
}

//Loads all the default values and objects.
void SouthernForest::loadDefaults(){

    this->loadTheSceneries();
    this->loadAllMapConfigurationsForLayers();
    this->loadLayers();
}

//Loads all the cloud Scenery objects.
void SouthernForest::loadTheSceneries(){

    FilterImage *fog = new FilterImage(imageStore->getBitMap("fog") , 0 , 0 , 0 , 0);
    PulsingImage *fogInner = new PulsingImage(imageStore->getBitMap("fogInner") , 0 , 0 , 0 , 0);

    fogInner->setMinTransparency(.35);
    fogInner->setMaxTransparency(.65);
    fogInner->setTransparencyIncrementer(.0025);

    this->loadScenery(fog);
    this->loadScenery(fogInner);
}

//Loads all the layers to the areaMap.
void SouthernForest::loadLayers(){

    Layer *backgroundLayer = new Layer(imageStore->getBitMap("snowTerrain") ,
        50 , 50 , this->backgroundLayerLayout , 2500);
    Layer *collisionLayer = new Layer(imageStore->getBitMap("southernForest") ,
        50 , 50 , this->collisionLayerLayout , 2500);
    Layer *canGoBehindLayer = new Layer(imageStore->getBitMap("southernForest") ,
        50 , 50 , this->canGoBehindLayerLayout , 2500);
   
    this->loadLayer(backgroundLayer);
    this->loadLayer(collisionLayer);
    this->loadLayer(canGoBehindLayer);
}

//Loads all of the map configurations for each of the layers.
void SouthernForest::loadAllMapConfigurationsForLayers(){

    loadBackgroundLayerMapConfiguration();
    loadCollisionLayerMapConfiguration();
    loadCanGoBehindLayerMapConfiguration();
}

void SouthernForest::loadBackgroundLayerMapConfiguration(){

    int backgroundLayerLayout[] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 2, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1,
        1, 1, 2, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1,
        1, 1, 3, 5, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1,
        1, 1, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 3, 3, 3, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 4, 4, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 4, 4, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 3, 3, 3, 5, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 5, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 6, 3, 3, 3, 3, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 6, 3, 3, 3, 3, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 4, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 4, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1,
        1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 2, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1,
        1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 3, 5, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
        1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3,
        5, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1,
        1, 1, 3, 3, 3, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3,
        3, 3, 3, 3, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 4, 4, 1, 4, 4, 1, 1, 1, 1, 1, 1, 3,
        3, 3, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7, 1, 1,
        1, 1, 3, 3, 3, 5, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3,
        3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 4, 4, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 6, 3, 3, 3, 3, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3,
        3, 3, 5, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7, 4, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 4, 1, 1, 6,
        3, 3, 3, 3, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 4, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 4, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    }; 

    this->backgroundLayerLayout = new int[this->layoutSize];
    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->backgroundLayerLayout[i] = backgroundLayerLayout[i];
}

void SouthernForest::loadCollisionLayerMapConfiguration(){

    int collisionLayerLayout[] ={
        99,100,101,99,100,101,99,100,101,99,100,101,99,100,101, 0, 0, 0, 0, 0,99,
        100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,
        99,100,101,99,100,101,99,100,101,
        102,103,104,102,103,104,102,103,104,102,103,104,102,103,104, 0, 0, 0, 0, 0,
        102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,
        103,104,102,103,104,102,103,104,102,103,104,
        105,106,107,105,106,107,105,106,107,105,106,107,105,106,107, 0, 0, 0, 0, 0,
        105,106,107,105,106,107,105,106,107,105,106,107,105,106,107,105,106,107,105,
        106,107,105,106,107,105,106,107,105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,
        101,
        102,103,104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,102,
        103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,108,109, 0, 0, 0, 0, 0,108,109,
        105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,105,106,107, 0, 0, 0, 0, 0, 0,108,109,110,111,112,31,
        34,99,100,101,
        102,103,104, 0, 0, 0, 0, 0,105,106,107,113,114,115, 0, 0, 0, 0, 0,105,106,
        107, 0, 0, 0,105,106,107, 0, 0, 0,99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0,116,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,99,100,101,
        105,106,107,99,100,101,105,106,107,102,103,104, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0,105,106,107,
        99,100,101, 0, 0,105,106,107, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,102,103,104,
        99,100,101,102,103,104,99,100,101,105,106,107, 0, 0, 0, 0, 0, 0, 0,108,109,
        108,109, 0, 0,99,100,101,
        102,103,104, 0, 0, 0, 0, 0,105,106,107,105,106,107, 0, 0,102,103,104,105,
        106,107,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,108,109,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,99,100,101,
        105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0, 0, 0,
        0, 0, 0, 0, 0,105,106,107,
        99,100,101, 0, 0,105,106,107, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,102,103,104,
        99,100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0, 0, 0,
        0, 0, 0, 0, 0,99,100,101,
        102,103,104, 0, 0, 0, 0, 0,105,106,107,105,106,107, 0, 0,102,103,104,105,
        106,107,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101, 0, 0,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,99,100,101,
        105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0, 0, 0,
        102,103,104, 0, 0,105,106,107,
        99,100,101, 0, 0,105,106,107, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,102,103,104,
        99,100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0, 0, 0,
        105,106,107, 0, 0,99,100,101,
        102,103,104, 0, 0, 0, 0, 0,113,114,115,105,106,107, 0, 0,102,103,104,102,
        103,104,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101, 0, 0,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,105,106,107,
        105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0, 0, 0,
        102,103,104, 0, 0,105,106,107,
        99,100,101, 0, 0,105,106,107, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,99,100,101,
        99,100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0, 0, 0,
        105,106,107, 0, 0,99,100,101,
        102,103,104, 0, 0, 0, 0, 0,105,106,107,113,114,115, 0, 0,102,103,104,102,
        103,104,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101, 0, 0,102,103,104,
        105,106,107, 0, 0,117,118,118,118,118,118,118,118,119, 0, 0,105,106,107,105,
        106,107,105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0,
        0, 0,102,103,104, 0, 0,105,106,107,
        99,100,101, 0, 0,120,121,121,121,121,121,121,121,122, 0, 0,99,100,101,99,
        100,101,99,100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0,
        0, 0,105,106,107, 0, 0,99,100,101,
        102,103,104, 0, 0,123,124,124,124,124,124,124,124,125, 0, 0,102,103,104,102,
        103,104,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101, 0, 0,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,105,106,107,
        105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0, 0, 0,
        102,103,104, 0, 0,105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,99,100,101,99,
        100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0, 0, 0,105,
        106,107, 0, 0,99,100,101,
        102,103,104, 0, 0,105,106,107,105,106,107,105,106,107, 0, 0,102,103,104,102,
        103,104,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101, 0, 0,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,105,106,107,
        105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0, 0, 0,
        102,103,104,108,109,105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,99,
        100,101,102,103,104, 0, 0, 0,105,106,107, 0, 0,102,103,104, 0, 0, 0,105,106,
        107,126,127,99,100,101,
        102,103,104, 0, 0,105,106,107,105,106,107,105,106,107, 0, 0, 0, 0, 0,102,
        103,104,102,103,104,105,106,107, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,105,106,
        107, 0,128,128,129,130,102,103,104,
        105,106,107, 0, 0,117,118,118,118,118,118,118,118,118,118,118,118,118,119,
        105,106,107,105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0,128,128,108,109,105,106,107,
        99,100,101, 0, 0,120,121,121,121,121,121,121,121,121,121,121,121,121,122,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0,99,100,101,99,100,101,
        102,103,104, 0, 0,123,124,124,124,124,124,124,124,124,124,124,124,124,125,
        102,103,104, 0, 0, 0, 0, 0, 0, 0,108,109, 0, 0,108,109, 0, 0,108,109, 0, 0,
        108,109, 0,102,103,104,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,
        105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,
        99,100,101,
        102,103,104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,102,103,104,
        105,106,107, 0, 0, 0, 0,108,109, 0, 0,108,109, 0, 0,108,109, 0, 0,108,109,
        0,102,103,104,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,
        105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,
        99,100,101,
        102,103,104, 0, 0, 0, 0, 0, 0,117,118,118,118,118,118,118,119, 0, 0,102,103,
        104,105,106,107, 0, 0, 0, 0,108,109, 0, 0,108,109, 0, 0,108,109, 0, 0,108,
        109, 0,102,103,104,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0,120,121,121,121,121,121,121,122, 0, 0,105,106,
        107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,
        106,107,105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0,123,124,124,124,124,124,124,125, 0, 0,99,100,
        101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,
        100,101,99,100,101,
        102,103,104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,102,103,104,105,
        106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,102,103,
        104,102,103,104,
        105,106,107,110,111,112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,131, 0, 0, 0, 0,105,106,
        107,105,106,107,
        99,100,101,117,118,119,34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107, 0, 0, 0,132,128, 0, 0, 0,99,
        100,101,99,100,101,
        102,103,104,120,121,122,35,32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,34,128,128,110,111,112,
        102,103,104,102,103,104,
        105,106,107,123,124,125,35,34,35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,
        133,35,133, 0, 0, 0, 0, 0,105,106,107, 0, 0, 0, 0, 0,128,128,128,134,135,
        136,105,106,107,105,106,107,
        99,100,101,117,118,119,117,118,119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,
        99,100,101,105,106,107, 0, 0,99,100,101,105,106,107, 0, 0,128,128,128,137,
        138,139,99,100,101,99,100,101,
        102,103,104,120,121,122,120,121,122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,102,103,
        104,102,103,104,35,35,35,35,35,102,103,104,140,141,51, 0, 0,128,128,128,142,
        143,144,102,103,104,102,103,104,
        105,106,107,123,124,125,123,124,125,110,111,112,110,111,112,110,111,112, 0,
        105,106,107,105,106,107,35,35,35,35,35,105,106,107,140,145,53, 0, 0,128,128,
        128,110,111,112,105,106,107,105,106,107,
        99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,
        101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,
        100,101,99,100,101,99,100,101,99,100,
        102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,
        103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,103,
        104,102,103,104,102,103,104,102,103,104,102,103
    };

    this->collisionLayerLayout = new int[this->layoutSize];
    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->collisionLayerLayout[i] = collisionLayerLayout[i];
}

void SouthernForest::loadCanGoBehindLayerMapConfiguration(){

    int canGoBehindLayerLayout[] ={
        99,100,101,99,100,101,99,100,101,99,100,101,99,100,101, 0, 0, 0, 0, 0,99,
        100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,
        99,100,101,99,100,101,99,100,101,
        102,103,104,102,103,104,102,103,104,102,103,104,102,103,104, 0, 0, 0, 0, 0,
        102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,
        103,104,102,103,104,102,103,104,102,103,104,
        105,106,107,105,106,107,105,106,107,105,106,107,105,106,107, 0, 0, 0, 0, 0,
        105,106,107,105,106,107,105,106,107,105,106,107,105,106,107,105,106,107,105,
        106,107,105,106,107,105,106,107,105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,126,127, 0, 0,134,135,136,126,127,
        99,100,101,
        102,103,104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,99,100,101, 0, 0, 0, 0,129,130,126,127,137,138,139,129,
        130,102,103,104,
        105,106,107, 0, 0, 0, 0, 0,99,100,101,146,147,148, 0, 0, 0, 0, 0,99,100,101,
        0, 0, 0,99,100,101, 0, 0, 0,102,103,104, 0, 0, 0, 0,108,109,129,130,142,
        143,144,108,109,105,106,107,
        99,100,101, 0, 0, 0, 0, 0,102,103,104,149,150,151, 0, 0,99,100,101,102,103,
        104,99,100,101,102,103,104,99,100,101,105,106,107, 0, 0, 0, 0, 0, 0,108,109,
        110,111,112,31,34,99,100,101,
        102,103,104, 0, 0,99,100,101,105,106,107,113,114,115, 0, 0,102,103,104,105,
        106,107,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0, 0, 0, 0, 0,
        0,126,127,126,127, 0,116,102,103,104,
        105,106,107, 0, 0,102,103,104,99,100,101,99,100,101, 0, 0,105,106,107,99,
        100,101,105,106,107,99,100,101,105,106,107,102,103,104, 0, 0, 0, 0, 0, 0,
        0,129,130,129,130,126,127,105,106,107,
        99,100,101, 0, 0,105,106,107,102,103,104,102,103,104, 0, 0,99,100,101,102,
        103,104,99,100,101,102,103,104,99,100,101,105,106,107, 0, 0, 0, 0, 0, 0, 0,
        108,109,108,109,129,130,99,100,101,
        102,103,104, 0, 0,99,100,101,105,106,107,105,106,107, 0, 0,102,103,104,105,
        106,107,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,108,109,102,103,104,
        105,106,107, 0, 0,102,103,104,99,100,101,99,100,101, 0, 0,105,106,107,99,
        100,101,105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0,
        0, 0, 0, 0, 0, 0, 0,105,106,107,
        99,100,101, 0, 0,105,106,107,102,103,104,102,103,104, 0, 0,99,100,101,102,
        103,104,99,100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0,
        0, 0, 0, 0, 0, 0, 0,99,100,101,
        102,103,104, 0, 0,99,100,101,105,106,107,105,106,107, 0, 0,102,103,104,105,
        106,107,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101, 0, 0,102,103,104,
        105,106,107, 0, 0,102,103,104,146,147,148,99,100,101, 0, 0,105,106,107,99,
        100,101,105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0,
        0, 0,102,103,104, 0, 0,105,106,107,
        99,100,101, 0, 0,105,106,107,149,150,151,102,103,104, 0, 0,99,100,101,102,
        103,104,99,100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0,
        0, 0,105,106,107, 0, 0,99,100,101,
        102,103,104, 0, 0,99,100,101,113,114,115,105,106,107, 0, 0,102,103,104,102,
        103,104,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101, 0, 0,102,103,104,
        105,106,107, 0, 0,102,103,104,99,100,101,146,147,148, 0, 0,105,106,107,105,
        106,107,105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0,
        0, 0,102,103,104, 0, 0,105,106,107,
        99,100,101, 0, 0,105,106,107,102,103,104,149,150,151, 0, 0,99,100,101,99,
        100,101,99,100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0,
        0, 0,105,106,107, 0, 0,99,100,101,
        102,103,104, 0, 0, 0, 0, 0,105,106,107,113,114,115, 0, 0,102,103,104,102,
        103,104,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101, 0, 0,102,103,104,
        105,106,107, 0, 0,117,118,118,118,118,118,118,118,119, 0, 0,105,106,107,105,
        106,107,105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0,
        0, 0,102,103,104, 0, 0,105,106,107,
        99,100,101, 0, 0,120,121,121,121,121,121,121,121,122, 0, 0,99,100,101,99,
        100,101,99,100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0,
        0, 0,105,106,107, 0, 0,99,100,101,
        102,103,104, 0, 0,123,124,124,124,124,124,124,124,125, 0, 0,102,103,104,102,
        103,104,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101, 0, 0,102,103,104,
        105,106,107, 0, 0,99,100,101,99,100,101,99,100,101, 0, 0,105,106,107,105,
        106,107,105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0,
        0, 0,102,103,104, 0, 0,105,106,107,
        99,100,101, 0, 0,102,103,104,102,103,104,102,103,104, 0, 0,99,100,101,99,
        100,101,99,100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0,
        0, 0,105,106,107,126,127,99,100,101,
        102,103,104, 0, 0,105,106,107,105,106,107,105,106,107, 0, 0,102,103,104,102,
        103,104,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101,129,130,102,103,104,
        105,106,107, 0, 0,99,100,101,99,100,101,99,100,101, 0, 0,105,106,107,105,
        106,107,105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101,99,
        100,101,102,103,104,108,109,105,106,107,
        99,100,101, 0, 0,102,103,104,102,103,104,102,103,104, 0, 0, 0, 0, 0,99,100,
        101,99,100,101,102,103,104, 0, 0, 0,105,106,107, 0, 0,102,103,104,102,103,
        104,105,106,107,126,127,99,100,101,
        102,103,104, 0, 0,105,106,107,105,106,107,105,106,107, 0, 0, 0, 0, 0,102,
        103,104,102,103,104,105,106,107, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,105,106,
        107, 0,128,128,129,130,102,103,104,
        105,106,107, 0, 0,117,118,118,118,118,118,118,118,118,118,118,118,118,119,
        105,106,107,105,106,107, 0, 0, 0, 0,126,127, 0, 0,126,127, 0, 0,126,127, 0,
        0,126,127,128,128,108,109,105,106,107,
        99,100,101, 0, 0,120,121,121,121,121,121,121,121,121,121,121,121,121,122,
        99,100,101, 0, 0, 0, 0, 0, 0, 0,129,130, 0, 0,129,130, 0, 0,129,130, 0, 0,
        129,130, 0,99,100,101,99,100,101,
        102,103,104, 0, 0,123,124,124,124,124,124,124,124,124,124,124,124,124,125,
        102,103,104, 0, 0, 0, 0, 0, 0, 0,108,109, 0, 0,108,109, 0, 0,108,109, 0, 0,
        108,109, 0,102,103,104,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,105,106,107,
        99,100,101, 0, 0, 0, 0,126,127, 0, 0,126,127, 0, 0,126,127, 0, 0,126,127,
        0,105,106,107,105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,102,103,104,99,100,101,
        102,103,104, 0, 0, 0, 0,129,130, 0, 0,129,130, 0, 0,129,130, 0, 0,129,130,
        0,99,100,101,99,100,101,
        102,103,104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,102,103,104,
        105,106,107, 0, 0, 0, 0,108,109, 0, 0,108,109, 0, 0,108,109, 0, 0,108,109,
        0,102,103,104,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,99,
        100,101, 0, 0, 0, 0,126,127, 0, 0,126,127, 0, 0,126,127, 0, 0,126,127, 0,
        105,106,107,105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,102,
        103,104, 0, 0, 0, 0,129,130, 0, 0,129,130, 0, 0,129,130, 0, 0,129,130, 0,
        99,100,101,99,100,101,
        102,103,104, 0, 0, 0, 0, 0, 0,117,118,118,118,118,118,118,119, 0, 0,102,103,
        104,105,106,107, 0, 0, 0, 0,108,109, 0, 0,108,109, 0, 0,108,109, 0, 0,108,
        109, 0,102,103,104,102,103,104,
        105,106,107,134,135,136, 0, 0, 0,120,121,121,121,121,121,121,122, 0, 0,105,
        106,107,99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0,105,106,107,105,106,107,
        99,100,101,137,138,139, 0, 0, 0,123,124,124,124,124,124,124,125, 0, 0,99,
        100,101,102,103,104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0,99,100,101,99,100,101,
        102,103,104,142,143,144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101, 0, 0, 0, 0, 0,134,135,136,
        102,103,104,102,103,104,
        105,106,107,110,111,112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0,102,103,104, 0, 0, 0,131, 0,137,138,139,
        105,106,107,105,106,107,
        99,100,101,117,118,119,34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,
        102,103,104, 0, 0, 0, 0, 0,99,100,101,105,106,107, 0, 0, 0,132,128,142,143,
        144,99,100,101,99,100,101,
        102,103,104,120,121,122,35,32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,102,103,104,
        105,106,107,99,100,101, 0, 0,102,103,104,99,100,101, 0, 0,34,128,128,110,
        111,112,102,103,104,102,103,104,
        105,106,107,123,124,125,35,34,35,134,135,136,134,135,136,134,135,136, 0,105,
        106,107,133,35,133,102,103,104, 0, 0,105,106,107,102,103,104, 0, 0,128,128,
        128,134,135,136,105,106,107,105,106,107,
        99,100,101,117,118,119,117,118,119,137,138,139,137,138,139,137,138,139, 0,
        99,100,101,99,100,101,105,106,107, 0, 0,99,100,101,105,106,107, 0, 0,128,
        128,128,137,138,139,99,100,101,99,100,101,
        102,103,104,120,121,122,120,121,122,142,143,144,142,143,144,142,143,144, 0,
        102,103,104,102,103,104,35,35,35,35,35,102,103,104,140,141,51, 0, 0,128,128,
        128,142,143,144,102,103,104,102,103,104,
        105,106,107,123,124,125,123,124,125,110,111,112,110,111,112,110,111,112, 0,
        105,106,107,105,106,107,35,35,35,35,35,105,106,107,140,145,53, 0, 0,128,128,
        128,110,111,112,105,106,107,105,106,107,
        99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,
        101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,
        100,101,99,100,101,99,100,101,99,100,
        102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,
        103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,103,
        104,102,103,104,102,103,104,102,103,104,102,103
    };

    this->canGoBehindLayerLayout = new int[this->layoutSize];

    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->canGoBehindLayerLayout[i] = canGoBehindLayerLayout[i];
}

void SouthernForest::deleteAllLayerConfigurations(){

    delete this->backgroundLayerLayout;
    this->backgroundLayerLayout = NULL;

    delete this->collisionLayerLayout;
    this->collisionLayerLayout = NULL;

    delete this->canGoBehindLayerLayout;
    this->canGoBehindLayerLayout = NULL;
}