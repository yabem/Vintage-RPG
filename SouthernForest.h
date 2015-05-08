//Configurations for the HomeTown map where the player starts.

#pragma once
#include "AreaMap.h"
#include "ImageStore.h"
#include "Scenery.h"
#include "Movement.h"
#include "Fog.h"
#include "HeatWave.h"

const int SOUTHERN_FOREST_LAYOUT_SIZE = 2500;

class SouthernForest : public AreaMap{
    
private:

    ImageStore *imageStore;
    int layoutSize;
    int *backgroundLayerLayout;
    int *collisionLayerLayout;
    int *canGoBehindLayerLayout;

    void loadTheSceneries();
    void loadLayers();
    void loadAllMapConfigurationsForLayers();

    void loadBackgroundLayerMapConfiguration();
    void loadCollisionLayerMapConfiguration();
    void loadCanGoBehindLayerMapConfiguration();
    void deleteAllLayerConfigurations();

public:

    SouthernForest(ImageStore *imageStore);
    virtual ~SouthernForest();
    void loadDefaults();
};