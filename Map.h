#pragma once

#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include <vector>
#include "Layer.h"
#include "Enums.h"
#include "Scenery.h"

class Map{

private:

    vector<Layer*> layers;       //Layer 0 is background, layer 1 is collision, layer 2 is foreground.
    vector<Scenery*> sceneries;  //Clouds and such.

public:

    Map();                      //Constructor.

    int getNumLayers() const;       //Return the number of Layers.
    int getNumSceneries() const;    //Return the number of Sceneries.
  
    Layer& getLayer(int index);         //Return a reference to the indexed Layer.
    Scenery& getScenery(int index);   //Return a reference to the indexed Scenery.
    Layer* getBackground();             //Return a pointer to the 0th layer.

    bool loadLayer(Layer *layer);           //Add a Layer to Layers.
    bool loadScenery(Scenery *scenery);     //Add a Scenery to sceneries.
 
    void setLayersDX(int x);                //Set the DX values for every layer.
    void setLayersDY(int y);                //Set the DY values for every layer.
};

