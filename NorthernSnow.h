//Area north of the hometown that is covered in snow.

#pragma once
//#include "AreaMap.h"
#include "CustomAreaMap.h"
#include "ImageStore.h"
#include "Scenery.h"
#include "Movement.h"
#include "DrawRepository.h"
#include "NPCWithDialogueThenBattle.h"
#include "GameManager.h"
#include "BattleManager.h"
#include "PixelConversion.h"
#include "FallingImage.h"

//const int LAYOUT_NORTHERN_SNOW_SIZE = 2500;

class NorthernSnow : public CustomAreaMap{

private:

    /*
    ImageStore *imageStore;
    DrawRepository *drawRepository;
    int sizeNorthernSnowLayout;
    int *backgroundLayerLayout;
    int *collisionLayerLayout;
    */
    void loadTheSceneries();
    void loadLayers();
    void loadTheTangibles();

    //void loadAllMapConfigurationsForLayers();

    void loadBackgroundLayerMapConfiguration();
    void loadCollisionLayerMapConfiguration();

    void deleteAllLayerConfigurations();
    /*
    GameManager *gameManager;
    BattleManager *battleManager;
    FontStore *fontStore;
    */

public:

    NorthernSnow(ImageStore *imageStore , DrawRepository *drawRepository ,
        GameManager *gameManager , BattleManager *battleManager , 
        FontStore *fontStore , int layoutSize);
    virtual ~NorthernSnow();
    //void loadDefaults();
};