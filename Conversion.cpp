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

std::string Conversion::convertFloatToString(float number){

    ostringstream buffer;

    buffer << std::fixed << std::setprecision(1) << number;

    return buffer.str();
}

float Conversion::getBattleTimeIncrement(){

    return (1.0 / FPS);
}