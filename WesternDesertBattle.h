//The battle map for when the players fight in the town.

#pragma once
#include "AreaMap.h"
#include "ImageStore.h"

const int WESTERN_DESERT_BATTLE_LAYOUT_SIZE = 300;

class WesternDesertBattle : public AreaMap{

private:

    ImageStore *imageStore;
    int sizeOfBattleCutsceneLayout;
    int *backgroundLayerLayout;

    void loadLayers();
    void loadAllMapConfigurationsForLayers();
    void loadBackgroundLayerConfiguration();
    void deleteAllLayerConfigurations();

public:

    WesternDesertBattle(ImageStore *imageStore);
    virtual ~WesternDesertBattle();
    void loadDefaults();
};