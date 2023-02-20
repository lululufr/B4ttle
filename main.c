#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "bibliotheque.h"
#include "display_sdl.h" //faudra changer ca
#include "combat.h"
#include "competence.h"
//#include <SDL/SDL.h>
//#include <SDL/SDL_image.h>


int main() {
    srand(time(NULL));
    WINDOW * w;

    print_title();
    //load_bar();
    launching(menu(w)); //la fonction qui lance nos menusmenu(); //SDLprinting(); est dans nouvelle partie !!
}

