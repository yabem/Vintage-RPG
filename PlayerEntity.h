//Holds all the information that defines a player such as the
//Inventory, available characters, etc.

#include "Backpack.h"
#include "CharacterList.h"
#include "ImageStore.h"
#include "CharStats.h"

class PlayerEntity{

private:

    Backpack *backpack;
    ImageStore *imageStore;
    CharacterList *thePlayers;

public:

    PlayerEntity(ImageStore *imageStore);
    ~PlayerEntity();
    void loadBackpack();
    void loadDefaultPlayers();
    Backpack* getPlayerInventory();
    CharacterList* getThePlayers();
    Character* getFirstPlayer();
};