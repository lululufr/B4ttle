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

    //WINDOW * w;

    //print_title();
    //load_bar();
 
    //launching(menu(w)); //la fonction qui lance nos menusmenu(); //SDLprinting(); est dans nouvelle partie !!!

    fight_print_sdl(player , opponent);
    //fight();
    //TTF_Font *font;
    //font = TTF_OpenFont("font/starjedi.ttf", 12);


}

