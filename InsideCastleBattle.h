//The battle map for when the players fight in the town.

#pragma once
#include "CustomAreaMap.h"

class ImageStore;

class InsideCastleBattle : public CustomAreaMap{

private:

    void loadLayers();
    void loadBackgroundLayerMapConfiguration();

public:

    InsideCastleBattle(ImageStore *imageStore , int layoutSize);
    virtual ~InsideCastleBattle();
};