#pragma once
#include "GameManager.h"
#include "PlayerEntity.h"
#include "DrawRepository.h"
#include "ShowActiveQuestLog.h"
#include "ShowCompletedQuestLog.h"
#include "ShowInventory.h"
#include "ShowPartyStatus.h"

namespace ProcessPlayerInput{

    void processPlayerInput(GameManager *gameManager , 
        PlayerEntity *playerEntity , DrawRepository *drawRepository);
};