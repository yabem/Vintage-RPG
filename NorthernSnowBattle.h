//The battle map for when the players fight in the northern snow area.

#pragma once
#include "CustomAreaMap.h"

class ImageStore;

class NorthernSnowBattle : public CustomAreaMap{

private:

    void loadLayers();
    void loadBackgroundLayerMapConfiguration();

public:

    NorthernSnowBattle(ImageStore *imageStore , int layoutSize);
    virtual ~NorthernSnowBattle();
};