//The transition screen for when the players fight in the town.

#pragma once
#include "AreaMap.h"
#include "ImageStore.h"

const int BATTLE_TRANSITION_SCREEN_LAYOUT_SIZE = 300;

class BattleTransitionScreen : public AreaMap{

private:

    ImageStore *imageStore;
    int sizeOfBattleTransitionScreenLayout;
    int *backgroundLayerLayout;

    void loadLayers();
    void loadAllMapConfigurationsForLayers();
    void loadBackgroundLayerConfiguration();
    void deleteAllLayerConfigurations();

public:

    BattleTransitionScreen(ImageStore *imageStore);
    virtual ~BattleTransitionScreen();
    void loadDefaults();
};