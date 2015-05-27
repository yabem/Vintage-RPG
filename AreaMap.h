//The purpose of AreaMap is to hold all the collections that make up an area
//such as layers, tangibles, sceneries, and exits. The area map had all the
//necessary information for drawing a complete area. Default destructor, copy 
//constructor, and assignment operator are used.

#pragma once
#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include <vector>
#include "Layer.h"
#include "GameConfig.h"
#include "Tangible.h"
#include "Scenery.h"
#include "Character.h"

class AreaMap{

protected:

    //Stores an exit location, the destination map, and the destination location.
    struct Exit{

        int row , col;
        AreaMap *toMap;
        int destRow , destCol;
    };

    vector<Layer*> layers;       //Layer 0 is background, layer 1 is collision, layer 2 is foreground.
    vector<Tangible*> tangibles; //Collision objects.
    vector<Scenery*> sceneries;  //Clouds and such.
    vector<Exit> exits;          //Exits to other maps.

    AreaMap *battleMap;          //Map for the battles in this area.

public:

    AreaMap();                      //Constructor.
    virtual ~AreaMap();             //Destructor.

    int getNumLayers() const;       //Return the number of Layers.
    int getNumTangibles() const;    //Return the number of Tangibles.
    int getNumSceneries() const;    //Return the number of Sceneries.
    int getNumExits() const;        //Return the number of exits.
    int getExitR(int index) const;  //Return the exit row of the indexed exit.
    int getExitC(int index) const;  //Return the exit col of the indexed exit.
    int getExitDestR(int index) const; //Return the destination row of the indexed exit.
    int getExitDestC(int index) const; //Return the destination col of the indexed exit.
    bool removeTangible(std::string identifierName); //Removes the tangible that matches the name.

    AreaMap* getToMap(int index) const; //Return a pointer to the indexed exits destination map.   
    Layer& getLayer(int index) const;         //Return a reference to the indexed Layer.
    Tangible& getTangible(int index) const;//Return a reference to the indexed Tangible.
    Scenery& getScenery(int index) const;   //Return a reference to the indexed Scenery.
    Layer* getBackground();             //Return a pointer to the 0th layer.

    void setBattleMap(AreaMap *battleMap);  //Sets the battlemap.
    AreaMap* getBattleMap();
    bool loadLayer(Layer *layer);           //Add a Layer to Layers.
    bool loadTangible(Tangible *tangible);  //Add a Tangible to tangibles.
    bool loadScenery(Scenery *scenery);     //Add a Scenery to sceneries.
    bool loadExit( int exitCol, int exitRow , AreaMap *toMap , int destCol , int destRow);  //Add an Exit to exits.
 
    void resetTangiblesDXToSX(int xOffset); //Resets the draw x location to the start x plus the offset.
    void resetTangiblesDYToSY(int yOffset); //Resets the draw y location to the start y plus the offset.
    void setLayersDX(int x);                //Set the DX values for every layer.
    void setLayersDY(int y);                //Set the DY values for every layer.

    void animateSceneries();                //Animate each Scenery in the sceneries vector.

    void deleteLayers();        //Deallocates all Layers.
    void deleteTangibles();     //Deallocates all Tangibles.
    void deleteSceneries();     //Deallocates all Sceneries.
};