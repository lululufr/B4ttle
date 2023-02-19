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

int isValid(int move, Map * map){
    if(map->map[move]==6 || map->map[move]==3){/*peut importe ce qu'il y a ici, c'est juste un exemple je connais pas tous les caractères valides*/
        return 0;          /*on peut mettre des OR dans le if*/
    }else{
        return 1;
    }
}
void evenement(int buffer){

    if(buffer == 65) {
        Chain * opponent = Chain_empty();
        Chain * player = Chain_empty();
        player->carte = Read_Card("ELEFTERIOU_Alexis");
        Chain_add_tail(player, Read_Card("AMBRY_Lukas"));
        Chain_add_tail(player, Read_Card("SAGE_Julien"));
        Chain_add_tail(player, Read_Card("KAKOU_Marceau"));
        /*player->carte = Read_Card("1");
        Read_player("2",player);
        Read_player("3",player);
        Read_player("4",player);*/

        opponent->carte = Random_Card();
        Chain_add_tail(opponent, Random_Card());
        Chain_add_tail(opponent, Random_Card());
        Chain_add_tail(opponent, Random_Card());
        fight_print_sdl(player,opponent);
    }


}

#endif //B4TTLE_MOVEMENT_H
