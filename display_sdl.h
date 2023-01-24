#ifndef MAIN_C_DISPLAY_SDL_H
#define MAIN_C_DISPLAY_SDL_H

//gcc -o B4ttle main.c -lSDL -lSDL_image -lcurses
//pour compiler


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"



#include <SDL/SDL.h>
#include <SDL/SDL_image.h>



void SDLprinting(){


    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error in SDL_Init : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_Surface * ecran = NULL;
    if((ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE |
        SDL_DOUBLEBUF)) == NULL) {fprintf(stderr, "Error in SDL_SetVideoMode : %s\n",SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("B4TTLE - esgi", NULL);




    /* Votre travail ici */

    SDL_Surface * surface = NULL;
    if((surface = IMG_Load("media/test_map_1.png")) == NULL) {
        fprintf(stderr, "Error in SDL_LoadBMP(\"media/TK.png\") : %s\n", SDL_GetError());
        SDL_FreeSurface(ecran);
        SDL_Quit();
        exit(EXIT_FAILURE);
}


char tableau[25] = {23,0,23,0,23,0,23,0,23,0,23,0,23,0,23,0,23,0,23,0,23,0,23,0,23};
int width=5;
//char * grille = readFile("maps/firstmap.txt");
    Map * map= malloc(sizeof (Map)*20);

    MapFile(map,"maps/firstmap.txt");


    SDL_Rect valtile;
    SDL_Rect screenPos;
    int i, j;
    for(j = 0; j < 5; ++j) {
        for(i = 0; i < 5; ++i) {
            if(tableau[i*width+j] == 0) continue;
            valtile.x = 35 * ((tableau[i*width+j]- 1) % 6);
            valtile.y = 35 * ((tableau[i*width+j] - 1) / 6);
            valtile.w = 35;
            valtile.h = 35;
            screenPos.x = i * 35;
            screenPos.y = j * 35;
            SDL_BlitSurface(surface, &valtile, ecran, &screenPos);
        }
    }
    SDL_Flip(ecran);

/* Votre travail ici */




int active = 1;
SDL_Event event;
while(active) {
    SDL_WaitEvent(&event);
        switch(event.type) {
            case SDL_QUIT : active = 0; 
                break;
            case SDL_KEYDOWN : 
                grille[10][20] = 10; 
                SDL_Flip(ecran);
                break;
            default : 
                break;
        }
}
SDL_Quit();
exit(EXIT_SUCCESS);

}






#endif