//The battle map for when the players fight in the town.

#pragma once
#include "AreaMap.h"
#include "ImageStore.h"

const int SOUTHERN_FOREST_BATTLE_SCREEN_LAYOUT_SIZE = 300;

class SouthernForestBattle : public AreaMap{

private:

    ImageStore *imageStore;
    int sizeOfBattleCutsceneLayout;
    int *backgroundLayerLayout;

    void loadLayers();
    void loadAllMapConfigurationsForLayers();
    void loadBackgroundLayerConfiguration();
    void deleteAllLayerConfigurations();

public:

    SouthernForestBattle(ImageStore *imageStore);
    virtual ~SouthernForestBattle();
    void loadDefaults();
};