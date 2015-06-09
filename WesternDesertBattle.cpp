#include "WesternDesertBattle.h"

WesternDesertBattle::WesternDesertBattle(ImageStore *imageStore , int layoutSize) : 
    CustomAreaMap(imageStore , NULL , NULL , NULL , NULL , layoutSize){

}

WesternDesertBattle::~WesternDesertBattle(){

}

void WesternDesertBattle::loadLayers(){

    Layer *backgroundLayer = new Layer(imageStore->getBitMap("terrain") ,
        15 , 20 , this->backgroundLayerLayout , 300);

    this->loadLayer(backgroundLayer);
}

void WesternDesertBattle::loadBackgroundLayerMapConfiguration(){
    
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

    this->backgroundLayerLayout = new int[this->layoutSize];
    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->backgroundLayerLayout[i] = backgroundLayerLayout[i];
}