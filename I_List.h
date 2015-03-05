//An interface that holds a list of objects.

#pragma once
class Menu;

class I_List{

private:

public:

    virtual ~I_List();
    virtual bool deleteSelection(int position) = 0;
    virtual void deleteList() = 0;
    virtual Menu* getSelection(int selection);
    //virtual void loadMenu(Menu *menu);
    //virtual void pauseBattle();
    //virtual void unPauseBattle();
};