//The battle map for when the players fight in the town.

#pragma once
#include "AreaMap.h"
#include "ImageStore.h"

const int BATTLE_SCREEN_LAYOUT_SIZE = 300;

class HomeTownBattleScreen : public AreaMap{

private:

    ImageStore *imageStore;
    int sizeOfBattleCutsceneLayout;
    int *backgroundLayerLayout;

    void loadLayers();
    void loadAllMapConfigurationsForLayers();
    void loadBackgroundLayerConfiguration();
    void deleteAllLayerConfigurations();

public:

    HomeTownBattleScreen(ImageStore *imageStore);
    virtual ~HomeTownBattleScreen();
    void loadDefaults();
};