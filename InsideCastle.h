//Configurations for the HomeTown map where the player starts.

#pragma once
#include "CustomAreaMap.h"
#include "ImageStore.h"
#include "Movement.h"
#include "FilterImage.h"
#include "PulsingImage.h"
#include "NPCWithDialogueThenBattle.h"
#include "Conversion.h"
#include "NPCWithDialogueAndQuest.h"
#include "NPCWithDialogueAndQuestWithItemReward.h"
#include "NPCWithQuestAndRemoval.h"
#include "NPCWithDialogueThenCutscene.h"
#include "GatherQuest.h"

class GameManager;
class BattleManager;
class ImageStore;
class Scenery;
class DrawRepository;
class FontStore;

class InsideCastle : public CustomAreaMap{
    
private:

    virtual void loadMapEnemies();

    virtual void loadLayers();
    virtual void loadTheTangibles();

    virtual void loadBackgroundLayerMapConfiguration();
    virtual void loadCollisionLayerMapConfiguration();
    virtual void loadCanGoBehindLayerMapConfiguration();

public:

    InsideCastle(ImageStore *imageStore , DrawRepository *drawRepository ,
        GameManager *gameManager , BattleManager *battleManager , 
        FontStore *fontStore , int layoutSize);
    virtual ~InsideCastle();
};