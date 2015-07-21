#include "Conversion.h"

int Conversion::convertPixelsToTiles(int pixels){

    return pixels / TILE_SIZE;
}

int Conversion::convertTilesToPixels(int tiles){

    return tiles * TILE_SIZE;
}
std::string Conversion::convertIntToString(int number){

    char tempChar[10];
    _itoa_s(number , tempChar , 10); 
    return tempChar;
}

float Conversion::getBattleTimeIncrement(){

    return (1.0 / FPS);
}