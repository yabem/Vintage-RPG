//Allows for customization of an AreaMap.

#pragma once
#include "AreaMap.h"
#include "ImageStore.h"
#include "DrawRepository.h"
#include "GameManager.h"
#include "BattleManager.h"
#include "FontStore.h"

class CustomAreaMap : public AreaMap{

protected:

    ImageStore *imageStore;
    DrawRepository *drawRepository;
    GameManager *gameManager;
    BattleManager *battleManager;
    FontStore *fontStore;

    int layoutSize;
    int *backgroundLayerLayout;
    int *collisionLayerLayout;
    int *canGoBehindLayerLayout;

    virtual void loadTheSceneries();
    virtual void loadLayers();
    virtual void loadTheTangibles();

    virtual void loadAllMapConfigurationsForLayers();

    virtual void loadBackgroundLayerMapConfiguration();
    virtual void loadCollisionLayerMapConfiguration();
    virtual void loadCanGoBehindLayerMapConfiguration();
    
    void deleteAllLayerConfigurations();

public:

    CustomAreaMap(ImageStore *imageStore , DrawRepository *drawRepository ,
        GameManager *gameManager , BattleManager *battleManager , 
        FontStore *fontStore , int layoutSize);
    virtual ~CustomAreaMap();
    void loadDefaults();
};