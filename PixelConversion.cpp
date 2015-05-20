#include "PixelConversion.h"

int PixelConversion::convertPixelsToTiles(int pixels){

    return pixels / TILE_SIZE;
}

int PixelConversion::convertTilesToPixels(int tiles){

    return tiles * TILE_SIZE;
}