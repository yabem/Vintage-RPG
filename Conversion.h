//Used for converting pixels to columns and columns to pixels.

#pragma once
#include "GameConfig.h"
#include <sstream>
#include <iomanip>

namespace Conversion{

    int convertPixelsToTiles(int pixels);
    int convertTilesToPixels(int tiles);
    std::string convertIntToString(int number);
    std::string convertFloatToString(float number);
    float getBattleTimeIncrement();
};