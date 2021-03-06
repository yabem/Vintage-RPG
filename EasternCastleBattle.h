//The battle map for when the players fight in the town.

#pragma once
#include "CustomAreaMap.h"
#include "FilterImage.h"
class ImageStore;

class EasternCastleBattle : public CustomAreaMap{

private:

    void loadLayers();
    void loadTheSceneries();
    void loadBackgroundLayerMapConfiguration();

public:

    EasternCastleBattle(ImageStore *imageStore , int layoutSize);
    virtual ~EasternCastleBattle();
};