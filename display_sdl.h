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


//char grille[25] = {23,0,23,0,23,0,23,0,23,0,23,0,23,0,23,0,23,0,23,0,23,0,23,0,23};
//char * grille = readFile("maps/firstmap.txt");
    Map * map = malloc(sizeof (Map)*20);

    MapFile(map,"maps/firstmap.txt");

    SDL_FillRect(ecran, NULL, 0x4226ad); //on peut changer la couleur ici

//func changement symbole
    int y;
    for(y = 0; y < 8; ++y) {
        if(map->map[y] == '#'){
            map->map[y] = 0; //# = vide
        }else if(map->map[y] == '%'){
            map->map[y] = 12;
        }else if(map->map[y] == '#'){
            map->map[y] = 0;
        }else if(map->map[y] == '#'){
            map->map[y] = 0;
        }
    }
    //func changement symbole

    SDL_Rect tilePos;
    SDL_Rect screenPos;
    int i, j;
    for(j = 0; j < 8; ++j) {
        for(i = 0; i < 8; ++i) {
            if(map->map[j*map->width+i] == 0) continue;
            tilePos.x = 25 * ((map->map[j*map->width+i] -1) % 6);
            tilePos.y = 25 * ((map->map[j*map->width+i] -1) / 6);
            tilePos.w = 25;
            tilePos.h = 25;
            screenPos.x = i * 25;
            screenPos.y = j * 25;
            SDL_BlitSurface(surface, &tilePos, ecran, &screenPos);

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

                SDL_Flip(ecran);
                break;
            default : 
                break;
        }
}

SDL_Quit();
    printf("%s", map->map);
exit(EXIT_SUCCESS);

}






#endif