//Area north of the hometown that is covered in snow.

#pragma once
#include "AreaMap.h"
#include "ImageStore.h"
#include "FallingImage.h"

const int LAYOUT_NORTHERN_SNOW_SIZE = 2500;

class NorthernSnow : public AreaMap{

private:

    ImageStore *imageStore;
    int sizeNorthernSnowLayout;
    int *backgroundLayerLayout;
    int *collisionLayerLayout;

    void loadClouds();
    void loadLayers();
    void loadAllMapConfigurationsForLayers();

    void loadBackgroundLayerMapConfiguration();
    void loadCollisionLayerMapConfiguration();
    void deleteAllLayerConfigurations();

public:

    NorthernSnow(ImageStore *imageStore);
    virtual ~NorthernSnow();
    void loadDefaults();
};