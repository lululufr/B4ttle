#ifndef B4TTLE_MOVEMENT_H
#define B4TTLE_MOVEMENT_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <stdlib.h>
#include <stdio.h>
#include "map.h"

int isValid(int move, Map * map){
    if(map->map[move]==63){/*peut importe ce qu'il y a ici, c'est juste un exemple je connais pas tous les caractères valides*/
        return 0;          /*on peut mettre des OR dans le if*/
    }else{
        return 1;
    }
}
void evenement(int pos,Map * map){
    if(map->map[pos] == 21) {
        printf("hey");
    }



}

#endif //B4TTLE_MOVEMENT_H
