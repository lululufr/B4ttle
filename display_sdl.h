#ifndef MAIN_C_DISPLAY_SDL_H
#define MAIN_C_DISPLAY_SDL_H

//gcc -o B4ttle main.c -lSDL -lSDL_image -lcurses
//pour compiler


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "movement.h"


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#define SCREEN_WIDTH  1280
#define SCREEN_HEIGHT 832



void SDLprinting(int position,char * mapName){ //la fonction d'affichage global


    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error in SDL_Init : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_Surface * ecran = NULL;
    if((ecran = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {

        fprintf(stderr, "euurreur : : %s\n",SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("B4TTLE - esgi", NULL);

    /* Votre travail ici */

    SDL_Surface * surface = NULL;
    if((surface = IMG_Load("media/mapping.png")) == NULL) {
        fprintf(stderr, "errur SDL_LoadBMP(\"media/TK.png\") : %s\n", SDL_GetError());
        SDL_FreeSurface(ecran);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }


    Map * map = malloc(sizeof (Map)*20);

    MapFile(map,mapName);

    SDL_FillRect(ecran, NULL, 0X9ed448); //on peut changer la couleur ici

   SDL_Rect tilePos;
   SDL_Rect screenPos;
    SDL_Rect persoPos;
   int i, j;




    //func changement symbole

#include "transformation.c"

    SDL_Event event;


    int pos = position;
    char mov = 0;

    char temp = map->map[pos];
    int newpos;
    char buffer;

    while (1) {


        SDL_WaitEvent(&event);

        // Si c'est la croix rouge
        if (event.type == SDL_QUIT) {
            break;
        }

        // mouvement
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    if (isValid(pos-map->width, map)){
                        newpos= map->map[pos-map->width]; //valeur case après
                        map->map[pos] = buffer; //case avant = case avant avant le déplacement
                        buffer = newpos; // "nouvelle case avant" = case après
                        map->map[pos-map->width]=62;
                        pos-=map->width;
                    }
                    break;
                case SDLK_DOWN:
                    if (isValid(pos+map->width, map)){
                        newpos= map->map[pos+map->width]; //valeur case après
                        map->map[pos] = buffer; //case avant = case avant avant le déplacement
                        buffer = newpos; // "nouvelle case avant" = case après
                        map->map[pos+map->width]=59;
                        pos+=map->width;
                    }
                    break;
                case SDLK_LEFT:
                    if (isValid(pos-1, map)) {
                        newpos = map->map[pos - 1]; //valeur case après
                        map->map[pos] = buffer; //case avant = case avant avant le déplacement
                        buffer = newpos; // "nouvelle case avant" = case après
                        map->map[pos - 1] = 60;
                        --pos;
                    }
                    break;
                case SDLK_RIGHT:
                    if (isValid(pos+1, map)) {
                        newpos = map->map[pos + 1]; //valeur case après
                        map->map[pos] = buffer; //case avant = case avant avant le déplacement
                        buffer = newpos; // "nouvelle case avant" = case après
                        map->map[pos + 1] = 61 ;
                        ++pos;
                    }
                    break;
            }
        }







        //SDL_FillRect(ecran, NULL, 0);

        // Dessine la map
        for(j = 0; j < 40; ++j) {
            for(i = 0; i < 40; ++i) {
                if(map->map[j*map->width+i] == 0) continue;
                tilePos.x = 32 * ((map->map[j*map->width+i] -1) % 40);
                tilePos.y = 32 * ((map->map[j*map->width+i] -1) / 40);
                tilePos.w = 32;
                tilePos.h = 32;
                screenPos.x = i * 32;
                screenPos.y = j * 32;
                SDL_BlitSurface(surface, &tilePos, ecran, &screenPos);

            }
        }

        // Met à jour l'écran !!!!!!!
        SDL_Flip(ecran);



        if(buffer == 60 ){
            SDL_FillRect(ecran, NULL, 0X9ed448); //on peut changer la couleur ici
            SDL_Flip(ecran);
            SDLprinting(56,"maps/route1");
        }

        buffer = evenement(buffer,ecran);



    }


    SDL_Quit();

    exit(EXIT_SUCCESS);

}






#endif