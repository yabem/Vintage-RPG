#include "NorthernSnowBattle.h"

NorthernSnowBattle::NorthernSnowBattle(ImageStore *imageStore , int layoutSize) : 
    CustomAreaMap(imageStore , NULL , NULL , NULL , NULL , layoutSize){

}

NorthernSnowBattle::~NorthernSnowBattle(){
    
}

void NorthernSnowBattle::loadLayers(){

    Layer *backgroundLayer = new Layer(imageStore->getBitMap("terrain") ,
        15 , 20 , this->backgroundLayerLayout , 300);

    this->loadLayer(backgroundLayer);
}

void NorthernSnowBattle::loadBackgroundLayerMapConfiguration(){
    
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

    this->backgroundLayerLayout = new int[this->layoutSize];
    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->backgroundLayerLayout[i] = backgroundLayerLayout[i];
}