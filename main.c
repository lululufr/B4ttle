#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "bibliotheque.h"
#include "display_sdl.h" //faudra changer ca
#include "combat.h"

//#include <SDL/SDL.h>
//#include <SDL/SDL_image.h>


int main() {
    srand(time(NULL));

    //Chain * player = Chain_empty(); //init du premier maillons
    //Chain * opponent = Chain_empty(); //init de la chaine adv
//
    //player->carte = Read_Card("ELEFTERIOU_Alexis");
    //Chain_add_tail(player, Read_Card("AMBRY_Lukas"));
    //Chain_add_tail(player, Read_Card("SAGE_Julien"));
    //Chain_add_tail(player, Read_Card("KAKOU_Marceau"));
//
//
    //opponent->carte = Random_Card();
    //Chain_add_tail(opponent, Random_Card());
    //Chain_add_tail(opponent, Random_Card());
    //Chain_add_tail(opponent, Random_Card());
    WINDOW * w;
//
    print_title();
    //load_bar();
 //
    launching(menu(w)); //la fonction qui lance nos menusmenu(); //SDLprinting(); est dans nouvelle partie !!!

    //fight_print_sdl(player , opponent);
    //fight();
    //TTF_Font *font;
    //font = TTF_OpenFont("font/starjedi.ttf", 12);


}

