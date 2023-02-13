#ifndef B4TTLE_MOVEMENT_H
#define B4TTLE_MOVEMENT_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include "combat_display.h"

int isValid(int move, Map * map){
    if(map->map[move]==6 || map->map[move]==3){/*peut importe ce qu'il y a ici, c'est juste un exemple je connais pas tous les caractères valides*/
        return 0;          /*on peut mettre des OR dans le if*/
    }else{
        return 1;
    }
}
void evenement(int buffer){

    if(buffer == 65) {
        //fight_print_sdl();
    }


}

#endif //B4TTLE_MOVEMENT_H
