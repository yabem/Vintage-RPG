//Holds all the information that defines a player such as the
//Inventory, available characters, etc.

#include "Backpack.h"

class PlayerEntity{

private:

    Backpack *backpack;

public:

    PlayerEntity();
    ~PlayerEntity();
    void loadBackpack();
    Backpack* getPlayerInventory();
};