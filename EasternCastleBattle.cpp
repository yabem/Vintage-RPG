#include "EasternCastleBattle.h"

EasternCastleBattle::EasternCastleBattle(ImageStore *imageStore , int layoutSize) : 
    CustomAreaMap(imageStore , NULL , NULL , NULL , NULL , layoutSize){

}

EasternCastleBattle::~EasternCastleBattle(){

}

void EasternCastleBattle::loadTheSceneries(){

    FilterImage *darkness = new FilterImage(imageStore->getBitMap("darkness") ,
        0 , 0 , 0 , 0);

    darkness->setTransparencyLevel(.5);
    darkness->setTransparencyIncrementer(.01);
    darkness->setRedTransparency(1);
    darkness->setGreenTransparency(1);
    darkness->setBlueTransparency(1);

    this->loadScenery(darkness);
}
void EasternCastleBattle::loadLayers(){

    Layer *backgroundLayer = new Layer(imageStore->getBitMap("terrain") ,
        15 , 20 , this->backgroundLayerLayout , 300);

    this->loadTheSceneries();
    this->loadLayer(backgroundLayer);
}

void EasternCastleBattle::loadBackgroundLayerMapConfiguration(){
    
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

    this->backgroundLayerLayout = new int[this->layoutSize];
    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->backgroundLayerLayout[i] = backgroundLayerLayout[i];
}