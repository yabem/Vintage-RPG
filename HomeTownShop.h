//Configurations for the Shop.

#pragma once
#include "CustomAreaMap.h"

class GameManager;
class BattleManager;
class ImageStore;
class Scenery;
class DrawRepository;
class FontStore;

class HomeTownShop : public CustomAreaMap{

private:

    void loadLayers();
    void loadAllMapConfigurationsForLayers();
    void loadBackgroundLayerConfiguration();
    void loadShopCollisionLayerConfiguration();

public:

    HomeTownShop(ImageStore *imageStore , DrawRepository *drawRepository ,
        GameManager *gameManager , BattleManager *battleManager , 
        FontStore *fontStore , int layoutSize);
    virtual ~HomeTownShop();
};