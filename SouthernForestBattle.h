//The battle map for when the players fight in the town.

#pragma once
#include "CustomAreaMap.h"

class ImageStore;

class SouthernForestBattle : public CustomAreaMap{

private:

    void loadLayers();
    void loadBackgroundLayerMapConfiguration();

public:

    SouthernForestBattle(ImageStore *imageStore , int layoutSize);
    virtual ~SouthernForestBattle();
};