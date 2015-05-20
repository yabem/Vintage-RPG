//The battle map for when the players fight in the town.

#pragma once
#include "AreaMap.h"
#include "ImageStore.h"

const int NORTHERN_SNOW_BATTLE_LAYOUT_SIZE = 300;

class NorthernSnowBattle : public AreaMap{

private:

    ImageStore *imageStore;
    int sizeOfBattleCutsceneLayout;
    int *backgroundLayerLayout;

    void loadLayers();
    void loadAllMapConfigurationsForLayers();
    void loadBackgroundLayerConfiguration();
    void deleteAllLayerConfigurations();

public:

    NorthernSnowBattle(ImageStore *imageStore);
    virtual ~NorthernSnowBattle();
    void loadDefaults();
};