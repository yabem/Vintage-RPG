//The controls namespace is used for taking in key presses
//from the user.

#include "controls.h"

//Return the key represented as an int.
int getKeyboardInput(ALLEGRO_EVENT *ev , bool *keys){

    int theKey = -1;
    
    bool keyAlreadyPressed = false;

    
    for(int i = 0 ; i < 4 ; i++){
        if(keys[i] == true){
            keyAlreadyPressed = true;
            theKey = i;
        }
    }
    
    if(ev->type == ALLEGRO_EVENT_KEY_DOWN)
    {
        switch(ev->keyboard.keycode){

	        case ALLEGRO_KEY_SPACE:
		        keys[SPACE] = true;
                theKey = SPACE;
		        break;

	        case ALLEGRO_KEY_Q:
		        keys[Q] = true;
                theKey = Q;
		        break;

	        case ALLEGRO_KEY_RIGHT:
                resetKeys(keys);
		        keys[RIGHT] = true;
                theKey = RIGHT;
		        break;

	        case ALLEGRO_KEY_LEFT:
                resetKeys(keys);
		        keys[LEFT] = true;
                theKey = LEFT;
		        break;

	        case ALLEGRO_KEY_UP:
                resetKeys(keys);
		        keys[UP] = true;
                theKey = UP;
		        break;

	        case ALLEGRO_KEY_DOWN:
                resetKeys(keys);
		        keys[DOWN] = true;
                theKey = DOWN;
		        break;

	        case ALLEGRO_KEY_U:
                resetKeys(keys);
		        keys[U] = true;
                theKey = U;
		        break;

	        case ALLEGRO_KEY_C:
                resetKeys(keys);
		        keys[C] = true;
                theKey = C;
		        break;

	        case ALLEGRO_KEY_L:
                resetKeys(keys);
		        keys[L] = true;
                theKey = L;
		        break;
        }
    }

    else if(ev->type == ALLEGRO_EVENT_KEY_UP){

        switch(ev->keyboard.keycode){

	        case ALLEGRO_KEY_SPACE:
		        keys[SPACE] = false;
		        break;
	        
	        case ALLEGRO_KEY_Q:
		        keys[Q] = false;
		        break;

            case ALLEGRO_KEY_RIGHT:
                if(RIGHT == theKey){
    		        keys[RIGHT] = false;
                    theKey = -1;
                }
                break;
	    
            case ALLEGRO_KEY_LEFT:
                if(LEFT == theKey){
    		        keys[LEFT] = false;
                    theKey = -1;
                }
                break;
	
            case ALLEGRO_KEY_UP:
                if(UP == theKey){
    		        keys[UP] = false;
                    theKey = -1;
                }
                break;
	        
            case ALLEGRO_KEY_DOWN:
                if(DOWN == theKey){
    		        keys[DOWN] = false;
                    theKey = -1;
                }
                break;

            case ALLEGRO_KEY_U:
                if(U == theKey){
    		        keys[U] = false;
                    theKey = -1;
                }
                break;

            case ALLEGRO_KEY_C:
                if(C == theKey){
    		        keys[C] = false;
                    theKey = -1;
                }
                break;

            case ALLEGRO_KEY_L:
                if(L == theKey){
    		        keys[L] = false;
                    theKey = -1;
                }
                break;
        }
    }

    return theKey;
}

//Reset keys to false.
void resetKeys(bool *keys){

    for(int i = 0 ; i < DIRECTIONS ; i++)
        keys[i] = false;
}