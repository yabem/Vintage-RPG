#pragma once
#include "BattleManager.h"
#include "ImageStore.h"
#include "GameManager.h"
#include "Intro.h"
#include "Instruct.h"
#include "FontStore.h"

namespace GameInitialization{

    void loadAllEnemyModels(BattleManager *battleManager , ImageStore *imageStore);
    void loadIntro(GameManager *gameManager , DrawRepository *drawRepository ,
        FontStore *fontStore , ImageStore *imageStore);
};