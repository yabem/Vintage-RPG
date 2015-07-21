//Holds a table of information that is displayed in rows.

#pragma once
#include "Menu.h"
#include "DrawTextWithBorder.h"

class InfoTable : public Menu{

protected:

public:

    InfoTable(std::string text , ALLEGRO_FONT *font);
    ~InfoTable();
    virtual void draw(); 
};