//Configurations for the HomeTown map where the player starts.

#pragma once
#include "CustomAreaMap.h"
#include "NPCWithDialogue.h"
#include "NPCWithDialogueAndGift.h"
#include "NPCWithDialogueAndQuest.h"
#include "ItemLocationWithGift.h"
#include "PixelConversion.h"
#include "KillQuest.h"

class GameManager;
class BattleManager;
class ImageStore;
class Scenery;
class DrawRepository;
class FontStore;

class HomeTown : public CustomAreaMap{
    
private:

    virtual void loadTheSceneries();
    virtual void loadLayers();
    virtual void loadTheTangibles();

    virtual void loadBackgroundLayerMapConfiguration();
    virtual void loadCollisionLayerMapConfiguration();
    virtual void loadCanGoBehindLayerMapConfiguration();

public:

    HomeTown(ImageStore *imageStore , DrawRepository *drawRepository ,
        GameManager *gameManager , BattleManager *battleManager , 
        FontStore *fontStore , int layoutSize);
    virtual ~HomeTown();
};