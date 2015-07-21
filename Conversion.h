//Used for converting pixels to columns and columns to pixels.

#pragma once
#include "GameConfig.h"

namespace Conversion{

    int convertPixelsToTiles(int pixels);
    int convertTilesToPixels(int tiles);
    std::string convertIntToString(int number);
    float getBattleTimeIncrement();
};