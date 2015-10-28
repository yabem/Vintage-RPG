//Configurations for the HomeTown map where the player starts.

#pragma once
#include "CustomAreaMap.h"
#include "Movement.h"
#include "FilterImage.h"
#include "Lightning.h"
#include "Rain.h"
#include "NPCWithDialogueThenBattle.h"
#include "Conversion.h"
#include "NPCWithDialogueAndQuest.h"
#include "NPCWithDialogueAndQuestWithItemReward.h"
#include "KillQuest.h"
#include "GatherQuest.h"

class GameManager;
class BattleManager;
class ImageStore;
class Scenery;
class DrawRepository;
class FontStore;

class EasternCastle : public CustomAreaMap{
    
private:

    virtual void loadMapEnemies();

    virtual void loadTheSceneries();
    virtual void loadLayers();
    virtual void loadTheTangibles();

    virtual void loadBackgroundLayerMapConfiguration();
    virtual void loadCollisionLayerMapConfiguration();
    virtual void loadCanGoBehindLayerMapConfiguration();

public:

    EasternCastle(ImageStore *imageStore , DrawRepository *drawRepository ,
        GameManager *gameManager , BattleManager *battleManager , 
        FontStore *fontStore , int layoutSize);
    virtual ~EasternCastle();
};