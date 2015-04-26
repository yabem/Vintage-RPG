//Area north of the hometown that is covered in snow.

#include "AreaMap.h"
#include "ImageStore.h"

const int LAYOUT_NORTHERN_SNOW_SIZE = 2500;

class NorthernSnow : public AreaMap{

private:

    ImageStore *imageStore;
    int sizeNorthernSnowLayout;
    int *backgroundLayerLayout;
    int *collisionLayerLayout;
    int *canGoBehindLayerLayout;

    void loadClouds();
    void loadLayers();
    void loadAllMapConfigurationsForLayers();

    void loadGrassLayerMapConfiguration();
    void loadTownCollisionLayerMapConfiguration();
    void loadTownCanGoBehindLayerMapConfiguration();
    void deleteAllLayerConfigurations();

public:

    NorthernSnow(ImageStore *imageStore);
    virtual ~NorthernSnow();
    void loadDefaults();
};