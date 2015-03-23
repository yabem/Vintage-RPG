#include "XPToLevel.h"

//Constructor.
XPToLevel::XPToLevel(){
    
}

//Destructor.
XPToLevel::~XPToLevel(){

    XPAmounts.clear();
}

//Sets the values.
//Pre:  None.
//Post: Sets the values for the entire table up to 99. The index corresponds
//      to the level. The XP needed to reach level 3 is stored at XPAmounts[3].
void XPToLevel::initializeValues(){

    //Skip level 0 and 1.
    XPAmounts.push_back(0);
    XPAmounts.push_back(0);

    //Start entering values for level 2-99.
    for(int i = 2 ; i < 99 ; i++){

        XPAmounts.push_back(i * 15);
    }
}

//Returns the XP needed to level.
//Pre:  The position is within the bounds of the list.
//Post: Returns the XP needed to level at that position.
int XPToLevel::getValue(int position){

    if(position > XPAmounts.size() || position < 0)
        return 0;

    else return XPAmounts[position];
}