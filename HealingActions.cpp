#include "HealingActions.h"

bool HealingActions::isHealingAction(std::string action){

    if(action == "Potion"){
        
        return true;
    }

    else if(action == "Bandage"){

        return true;
    }

    else if(action == "Recover"){

        return true;
    }

    else if(action == "Heal"){

        return true;
    }

    else if(action == "Cure"){

        return true;
    }

    else return false;
}