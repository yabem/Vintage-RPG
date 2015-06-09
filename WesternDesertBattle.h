//The battle map for when the players fight in the western desert.

#pragma once
#include "CustomAreaMap.h"

class ImageStore;

class WesternDesertBattle : public CustomAreaMap{

private:

    void loadLayers();
    void loadBackgroundLayerMapConfiguration();

public:

    WesternDesertBattle(ImageStore *imageStore , int layoutSize);
    virtual ~WesternDesertBattle();
};