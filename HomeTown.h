//Configurations for the HomeTown map where the player starts.

#pragma once
#include "AreaMap.h"
#include "ImageStore.h"
#include "Scenery.h"
#include "Movement.h"
#include "DrawRepository.h"
#include "NPCWithDialogue.h"
#include "GameManager.h"
#include "PixelConversion.h"
#include "FontStore.h"

const int HOME_TOWN_LAYOUT_SIZE = 2500;

class HomeTown : public AreaMap{
    
private:

    ImageStore *imageStore;
    DrawRepository *drawRepository;
    int sizeHomeTownLayout;
    int *backgroundLayerLayout;
    int *collisionLayerLayout;
    int *canGoBehindLayerLayout;

    void loadSceneries();
    void loadTangibles();
    void loadLayers();
    void loadAllMapConfigurationsForLayers();

    void loadBackgroundLayerMapConfiguration();
    void loadCollisionLayerMapConfiguration();
    void loadCanGoBehindLayerMapConfiguration();
    void deleteAllLayerConfigurations();

    GameManager *gameManager;
    FontStore *fontStore;

public:

    HomeTown(ImageStore *imageStore , DrawRepository *drawRepository ,
        GameManager *gameManager , FontStore *fontStore);
    virtual ~HomeTown();
    void loadDefaults();
};