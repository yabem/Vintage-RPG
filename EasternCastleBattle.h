//The battle map for when the players fight in the town.

#pragma once
#include "AreaMap.h"
#include "ImageStore.h"

const int BATTLE_SCREEN_LAYOUT_SIZE = 300;

class EasternCastleBattle : public AreaMap{

private:

    ImageStore *imageStore;
    int sizeOfBattleCutsceneLayout;
    int *backgroundLayerLayout;

    void loadLayers();
    void loadAllMapConfigurationsForLayers();
    void loadBackgroundLayerConfiguration();
    void deleteAllLayerConfigurations();

public:

    EasternCastleBattle(ImageStore *imageStore);
    virtual ~EasternCastleBattle();
    void loadDefaults();
};