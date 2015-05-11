//Configurations for the HomeTown map where the player starts.

#pragma once
#include "AreaMap.h"
#include "ImageStore.h"
#include "Scenery.h"
#include "Movement.h"
#include "PulsingImage.h"

const int WESTERN_DESERT_LAYOUT_SIZE = 2500;

class WesternDesert : public AreaMap{
    
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

    WesternDesert(ImageStore *imageStore);
    virtual ~WesternDesert();
    void loadDefaults();
};