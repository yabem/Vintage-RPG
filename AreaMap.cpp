//The purpose of AreaMap is to hold all the collections that make up an area
//such as layers, tangibles, sceneries, and exits. The area map had all the
//necessary information for drawing a complete area. Default destructor, copy 
//constructor, and assignment operator are used.

#include "AreaMap.h"

//Constructor.
AreaMap::AreaMap(){

}

//Destructor.
AreaMap::~AreaMap(){

    deleteLayers();
    deleteTangibles();
    deleteSceneries();     
}

//Return the number of Layers.
int AreaMap::getNumLayers() const{

    return layers.size();
}

//Return the number of Tangibles.
int AreaMap::getNumTangibles() const{

    return tangibles.size();
}

//Return the number of Sceneries.
int AreaMap::getNumSceneries() const{

    return sceneries.size();
}

//Return the number of exits.
int AreaMap::getNumExits() const{

    return exits.size();
}

//Return the exit row of the indexed exit.
int AreaMap::getExitR(int index) const{

    if(index < 0 || index > exits.size())
        return -1;

    else return exits[index].row;
}

//Return the exit col of the indexed exit.
int AreaMap::getExitC(int index) const{

    if(index < 0 || index > exits.size())
        return -1;

    else return exits[index].col;
}

//Return the destination row of the indexed exit.
int AreaMap::getExitDestR(int index) const{

    return exits[index].destRow;
}

//Return the destination col of the indexed exit.
int AreaMap::getExitDestC(int index) const{

    return exits[index].destCol;
}

//Removes the tangible that matches the name.
bool AreaMap::removeTangible(std::string identifierName){

    std::vector<Tangible*>::iterator tangibleIter = tangibles.begin();

    while(tangibleIter != tangibles.end()){

        if((*tangibleIter)->getIdentifierName() == identifierName){

            tangibles.erase(tangibleIter);
            return true;
        }

        tangibleIter++;
    }

    return false;
}

//Return a pointer to the indexed exits destination map.
AreaMap* AreaMap::getToMap(int index) const{

    return exits[index].toMap; 
}

//Return a reference to the indexed layer.
Layer& AreaMap::getLayer(int index) const{

    return *layers[index];
}

//Return a reference to the indexed tangible.
Tangible& AreaMap::getTangible(int index) const{

    return *tangibles[index];
}

//Return a reference to the indexed Scenery.
Scenery& AreaMap::getScenery(int index) const{

    return *sceneries[index];
}

//Return a pointer to the 0th layer.
Layer *AreaMap::getBackground(){

    return layers[BACKGROUND];
}

void AreaMap::setBattleMap(AreaMap *battleMap){

    this->battleMap = battleMap;
}

AreaMap* AreaMap::getBattleMap(){

    return this->battleMap;
}

//Add a Layer to Layers.
bool AreaMap::loadLayer(Layer *layer){

    layers.push_back(layer);
    return true;
}

//Add a Tangible to tangibles.
bool AreaMap::loadTangible(Tangible *tangible){

    tangibles.push_back(tangible);
    return true;
}

//Add a Scenery to sceneries.
bool AreaMap::loadScenery(Scenery *scenery){

    sceneries.push_back(scenery);
    return true;
}

//Add an Exit to exits.
bool AreaMap::loadExit(int exitCol , int exitRow , AreaMap *toMap , int destCol , int destRow){

    if(exitRow < 0 || exitCol < 0)
        return false;

    else{
        
        Exit insExit;
        insExit.row = exitRow;
        insExit.col = exitCol;
        insExit.destCol = destCol;
        insExit.destRow = destRow;
        insExit.toMap = toMap;

        exits.push_back(insExit);
        return true;
    }
}

//Resets the draw x location to the start x plus the offset.
void AreaMap::resetTangiblesDXToSX(int xOffset){

    for(unsigned int i = 0 ; i < tangibles.size() ; i++)
        tangibles[i]->setDX(xOffset + tangibles[i]->getSX());
}

//Resets the draw y location to the start y plus the offset.
void AreaMap::resetTangiblesDYToSY(int yOffset){

    for(unsigned int i = 0 ; i < tangibles.size() ; i++)
        tangibles[i]->setDY(yOffset + tangibles[i]->getSY());
}

//Set the DX values for every layer.
void AreaMap::setLayersDX(int x){

    for(unsigned int i = 0 ; i < layers.size() ; i++)
        layers[i]->setDX(x);
}

//Set the DY values for every layer.
void AreaMap::setLayersDY(int y){

    for(unsigned int i = 0 ; i < layers.size() ; i++)
        layers[i]->setDY(y);
}

//Increment each Scenery in the sceneries vector.
void AreaMap::animateSceneries(){

    vector<Scenery*>::iterator iter;

    for(iter = sceneries.begin() ; iter != sceneries.end() ; iter++)
        (*iter)->animate();
}

//Deallocates all Layers.
void AreaMap::deleteLayers(){

    vector<Layer*>::iterator layerIter = layers.begin();

    while(layerIter != layers.end()){

        delete (*layerIter);
        (*layerIter) = NULL;
        layerIter++;
    }
    layers.clear();
}

//Deallocates all Tangibles.
void AreaMap::deleteTangibles(){

    vector<Tangible*>::iterator tangibleIter = tangibles.begin();

    while(tangibleIter != tangibles.end()){

        delete (*tangibleIter);
        (*tangibleIter) = NULL;
        tangibleIter++;
    }
    tangibles.clear();

}

//Deallocates all Sceneries.
void AreaMap::deleteSceneries(){

    vector<Scenery*>::iterator sceneryIter = sceneries.begin();

    while(sceneryIter != sceneries.end()){

        delete (*sceneryIter);
        (*sceneryIter) = NULL;
        sceneryIter++;
    }

    sceneries.clear();
}