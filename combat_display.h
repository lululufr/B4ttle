#ifndef B4TTLE_COMBAT_DISPLAY_H
#define B4TTLE_COMBAT_DISPLAY_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "monster.h"
#include "combat.h"





void print_card_sdl(card *card,SDL_Surface * screen,TTF_Font *font,int x, int y){
    SDL_Surface * SDL_cards;
    SDL_Rect pos, pos_stat;

    SDL_Surface *message;
    SDL_Color color = {200,45,75};

//on va modif ca
    char * str = malloc(sizeof(char)*strlen(card->name));

    sprintf(str,"%s",card->name);

    message = TTF_RenderText_Solid(font, str, color);


    //char way[100] = "cards_png/";
    //strcat(way, str);
    SDL_cards = IMG_Load("cards_png/ELEFTERIOU_Alexis");

    pos.x = x;
    pos.y = y;

    pos_stat.x = x+5;
    pos_stat.y = y+5;

    SDL_BlitSurface(SDL_cards, NULL, screen, &pos);
    SDL_BlitSurface(message, NULL, screen, &pos_stat);

    SDL_Flip(screen);

    free(str);

}



int fight_print_sdl(){
    //why on a pas besoin de init le sdl ?

    TTF_Init();

    SDL_Surface *screen;
    screen = SDL_SetVideoMode(975, 650, 32, SDL_HWSURFACE);

    TTF_Font *font;
    font = TTF_OpenFont("font/starjedi.ttf", 24);


    // Boucle de rendu
    int quit = 0;
    SDL_Event event;


    while (1)
    {


        if (event.type == SDL_QUIT) {
            break;
        }

        // déplacement menu
        //Chain * chosen_card;


        SDL_FillRect(screen, NULL, 0x000000);
        print_card_sdl(Read_Card("ELEFTERIOU_Alexis"), screen, font, 100, 510);

        // Met à jour l'écran !!!!!!!
        SDL_Flip(screen);

        SDL_WaitEvent(&event);

        int pos;
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {/*
                case SDLK_LEFT:
                    if (pos == 0) {
                        //pos = Chain_length(player);
                    } else {
                        --pos;
                        //chosen_card = Chain_get(player_chain, pos);
                    }
                    break;
                case SDLK_RIGHT:
                    if (pos == Chain_length(player)) {
                        //pos = 0;
                    } else {
                        //++pos;
                        //chosen_card = Chain_get(player_chain, pos);
                    }
                    break;*/
            }
        }
    }





SDL_Quit();




return 0; // ou 1 si on gagne

}



#endif
