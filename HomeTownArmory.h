//Configurations for the Shop.

#pragma once
#include "CustomAreaMap.h"
#include "NPCWithDialogueAndQuest.h"
#include "GatherQuest.h"
#include "ItemLocationWithGift.h"

class GameManager;
class BattleManager;
class ImageStore;
class Scenery;
class DrawRepository;
class FontStore;

class HomeTownArmory : public CustomAreaMap{

private:

    void loadLayers();
    void loadAllMapConfigurationsForLayers();
    void loadBackgroundLayerConfiguration();
    void loadShopCollisionLayerConfiguration();
    void loadTheTangibles();

public:

    HomeTownArmory(ImageStore *imageStore , DrawRepository *drawRepository ,
        GameManager *gameManager , BattleManager *battleManager , 
        FontStore *fontStore , int layoutSize);
    virtual ~HomeTownArmory();
};