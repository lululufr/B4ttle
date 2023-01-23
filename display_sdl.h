#ifndef MAIN_C_DISPLAY_SDL_H
#define MAIN_C_DISPLAY_SDL_H

//gcc -o B4ttle main.c -lSDL -lSDL_image -lcurses
//pour compiler


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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



char grille[6][8] = {
{ 1, 0, 2, 0, 3, 0, 4, 0},
{ 0, 5, 0, 6, 0, 7, 0, 8},
{ 9, 0, 10, 0, 11, 0, 12, 0},
{ 0, 13, 0, 14, 0, 15, 0, 16},
{ 17, 0, 18, 0, 19, 0, 20, 0},
{ 0, 21, 0, 22, 0, 23, 0, 24}
};
SDL_Rect tilePos;
SDL_Rect screenPos;
int i, j;
for(j = 0; j < 6; ++j) {
for(i = 0; i < 8; ++i) {
if(grille[j][i] == 0) continue;
tilePos.x = 25 * ((grille[j][i] - 1) % 6);
tilePos.y = 25 * ((grille[j][i] - 1) / 6);
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
case SDL_QUIT : active = 0; break;
case SDL_KEYUP : active = 0; break;
default : break;
}
}
SDL_Quit();
exit(EXIT_SUCCESS);

}

#endif