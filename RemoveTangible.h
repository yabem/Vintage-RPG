//Removes a tangible from the current map.

#include "Cutscene.h"
#include "GameManager.h"

class RemoveTangible : public Cutscene{

private:

    GameManager *gameManager;
    std::string identifierNameToRemove;

public:

    RemoveTangible(GameManager *gameManager , 
        std::string identifierNameToRemove);
    ~RemoveTangible();
    virtual bool play(const int pressedKey); 
};