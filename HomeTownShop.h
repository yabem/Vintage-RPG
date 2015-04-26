//Configurations for the Shop.

#pragma once
#include "AreaMap.h"
#include "ImageStore.h"

const int HOME_TOWN_SHOP_LAYOUT_SIZE = 300;

class HomeTownShop : public AreaMap{

private:

    ImageStore *imageStore;
    int sizeHomeTownShopLayout;
    int *backgroundLayerLayout;
    int *shopCollisionLayerLayout;

    void loadLayers();
    void loadAllMapConfigurationsForLayers();
    void loadBackgroundLayerConfiguration();
    void loadShopCollisionLayerConfiguration();
    void deleteAllLayerConfigurations();

public:

    HomeTownShop(ImageStore *imageStore);
    virtual ~HomeTownShop();
    void loadDefaults();
};