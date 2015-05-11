//Configurations for the HomeTown map where the player starts.

#pragma once
#include "AreaMap.h"
#include "ImageStore.h"
#include "Scenery.h"
#include "Movement.h"
#include "FilterImage.h"
#include "Lightning.h"
#include "Rain.h"

const int EASTERN_CASTLE_LAYOUT_SIZE = 2500;

class EasternCastle : public AreaMap{
    
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

    EasternCastle(ImageStore *imageStore);
    virtual ~EasternCastle();
    void loadDefaults();
};