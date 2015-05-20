//Used for converting pixels to columns and columns to pixels.

#pragma once
#include "GameConfig.h"

namespace PixelConversion{

    int convertPixelsToTiles(int pixels);
    int convertTilesToPixels(int tiles);
};