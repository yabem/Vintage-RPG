//Configurations for the HomeTown map where the player starts.

#pragma once
#include "AreaMap.h"
#include "ImageStore.h"
#include "Scenery.h"
#include "Movement.h"

const int HOME_TOWN_LAYOUT_SIZE = 2500;

class HomeTown : public AreaMap{
    
private:

    ImageStore *imageStore;
    int sizeHomeTownLayout;
    int *backgroundLayerLayout;
    int *collisionLayerLayout;
    int *canGoBehindLayerLayout;

    void loadClouds();
    void loadRocks();
    void loadLayers();
    void loadAllMapConfigurationsForLayers();

    void loadBackgroundLayerMapConfiguration();
    void loadCollisionLayerMapConfiguration();
    void loadCanGoBehindLayerMapConfiguration();
    void deleteAllLayerConfigurations();

public:

    HomeTown(ImageStore *imageStore);
    virtual ~HomeTown();
    void loadDefaults();
};