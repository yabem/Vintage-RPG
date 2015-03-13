//Stores the AI for a Character.

#pragma once
//#include "DrawRepository.h"


class I_AI{

public:
    virtual ~I_AI();
    virtual void executeBattleLogic() = 0;
};
