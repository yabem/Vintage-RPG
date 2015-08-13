//Area north of the hometown that is covered in snow.

#pragma once
#include "CustomAreaMap.h"
#include "NPCWithDialogueThenBattle.h"
#include "NPCWithDialogueAndQuest.h"
#include "Conversion.h"
#include "FallingImage.h"
#include "GatherQuest.h"

class GameManager;
class BattleManager;
class ImageStore;
class Scenery;
class DrawRepository;
class FontStore;

class NorthernSnow : public CustomAreaMap{

private:

    virtual void loadMapEnemies();

    virtual void loadTheSceneries();
    virtual void loadLayers();
    virtual void loadTheTangibles();

    virtual void loadBackgroundLayerMapConfiguration();
    virtual void loadCollisionLayerMapConfiguration();

public:

    NorthernSnow(ImageStore *imageStore , DrawRepository *drawRepository ,
        GameManager *gameManager , BattleManager *battleManager , 
        FontStore *fontStore , int layoutSize);
    virtual ~NorthernSnow();
};