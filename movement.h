#ifndef B4TTLE_MOVEMENT_H
#define B4TTLE_MOVEMENT_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include "combat_display.h"
#include "combat.h"
#include "monster.h"
#include "display_sdl.h"

int isValid(int move, Map * map){
    if(map->map[move]==6 ||
    map->map[move]==7 ||
    map->map[move]==8 ||
    map->map[move]==9 ||
    map->map[move]==10 ||
    map->map[move]==3||
    map->map[move]==2 ||
    map->map[move]==58||
    map->map[move]==55||
    map->map[move]==56||
    map->map[move]==57||
    map->map[move]==58){/*peut importe ce qu'il y a ici, c'est juste un exemple je connais pas tous les caractères valides*/
        return 0;          /*on peut mettre des OR dans le if*/
    }else{
        return 1;
    }
}
int evenement(char buffer, SDL_Surface * ecran){

    if(buffer == 65) {
        Chain * opponent = Chain_empty();//création des cartes du joueur et de l'ennemi
        Chain * player = Chain_empty();
        player->carte = Read_Card("ELEFTERIOU_Alexis");
        Chain_add_tail(player, Read_Card("AMBRY_Lukas"));
        Chain_add_tail(player, Read_Card("MEALARES_Julien"));
        Chain_add_tail(player, Read_Card("KOBANOVIC_Anthony"));
        opponent->carte = Random_Card();
        Chain_add_tail(opponent, Random_Card());
        Chain_add_tail(opponent, Random_Card());
        Chain_add_tail(opponent, Random_Card());

        fight_print_sdl(player,opponent);//combat


        SDL_FillRect(ecran, NULL, 0X9ed448);
        return buffer-1;
    }


}

#endif //B4TTLE_MOVEMENT_H
