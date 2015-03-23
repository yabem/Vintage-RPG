//Stores the experience amount values needed for a Character to level up.

#include <vector>
#include "I_CharacterValuesList.h"

class XPToLevel : public I_CharacterValuesList{

private:
    
    std::vector<int> XPAmounts;

public:

    XPToLevel();
    ~XPToLevel();

    //Sets the values.
    void initializeValues();

    //Returns the value at the position.
    virtual int getValue(int position);
};