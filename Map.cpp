#include "Map.h"

//Constructor.
Map::Map(){

}

//Return the number of Layers.
int Map::getNumLayers() const{

    return layers.size();
}

//Return the number of Sceneries.
int Map::getNumSceneries() const{

    return sceneries.size();
}
//Return a reference to the indexed layer.
Layer& Map::getLayer(int index){

    return *layers[index];
}

//Return a reference to the indexed Scenery.
Scenery& Map::getScenery(int index){

    return *sceneries[index];
}

//Return a pointer to the 0th layer.
Layer *Map::getBackground(){

    return layers[BACKGROUND];
}

//Add a Layer to Layers.
bool Map::loadLayer(Layer *layer){

    layers.push_back(layer);
    return true;
}

//Add a Scenery to sceneries.
bool Map::loadScenery(Scenery *scenery){

    sceneries.push_back(scenery);
    return true;
}

//Set the DX values for every layer.
void Map::setLayersDX(int x){

    for(unsigned int i = 0 ; i < layers.size() ; i++)
        layers[i]->setDX(x);
}

//Set the DY values for every layer.
void Map::setLayersDY(int y){

    for(unsigned int i = 0 ; i < layers.size() ; i++)
        layers[i]->setDY(y);
}
