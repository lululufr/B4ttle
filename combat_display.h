#ifndef B4TTLE_COMBAT_DISPLAY_H
#define B4TTLE_COMBAT_DISPLAY_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "monster.h"
#include "combat.h"



void print_card_sdl(card *card,SDL_Surface * screen,TTF_Font *font,int x, int y){


    //SDL_Surface * SDL_card;
    SDL_Rect pos, pos_nom,pos_hp,pos_atk;

    SDL_Surface * message_nom,*message_hp,*message_atk;

    SDL_Color rouge = {200,45,75};
    SDL_Color blanc = {255,255,255};
    SDL_Color vert = {45,45,125};

//message
    char * str = malloc(sizeof(char)*strlen(card->name)+15);

        sprintf(str,"%s",card->name);
        strcat(str,"\0");
        message_nom = TTF_RenderText_Solid(font, str, blanc);


        sprintf(str,"Vie : %d",card->hp);
        strcat(str,"\0");
        message_hp = TTF_RenderText_Solid(font, str, vert);

        sprintf(str,"Attaque : %d",card->atk);
        strcat(str,"\0");
        message_atk = TTF_RenderText_Solid(font, str, rouge);

//ici



    char way[50] = "cards_png/";
    strcat(way, card->name);
    strcat(way, "\0");
    //strcat(way, card->name);
    card->SDL_card = IMG_Load(way);


//ici

    pos.x = x;
    pos.y = y;

    pos_nom.x = x -10;
    pos_nom.y = y-20;

    pos_hp.x = x + 10;
    pos_hp.y = y + 20;

    pos_atk.x = x +10;
    pos_atk.y = y + 30;

    SDL_BlitSurface(card->SDL_card, NULL, screen, &pos);
    SDL_BlitSurface(message_nom, NULL, screen, &pos_nom);
    SDL_BlitSurface(message_hp, NULL, screen, &pos_hp);
    SDL_BlitSurface(message_atk, NULL, screen, &pos_atk);



    SDL_FreeSurface(message_nom);
    SDL_FreeSurface(message_hp);
    SDL_FreeSurface(message_atk);
    SDL_FreeSurface(card->SDL_card);

    SDL_Flip(screen);

}



int fight_print_sdl(){
    //why on a pas besoin de init le sdl ?
    TTF_Init();


    SDL_Surface *screen;
    screen = SDL_SetVideoMode(975, 650, 32, SDL_HWSURFACE);

    TTF_Font *font;
    font = TTF_OpenFont("font/starjedi.ttf", 12);


    // Boucle de rendu
    int quit = 0;
    SDL_Event event;


    while (1)
    {
        SDL_FillRect(screen, NULL, 0x000000);

        if (event.type == SDL_QUIT) {
            break;
        }


        SDL_WaitEvent(&event);

// déplacement menu
        //Chain * chosen_card;
        int pos;

        if (event.type == SDL_KEYDOWN ) {

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
            print_card_sdl(Read_Card("ELEFTERIOU_Alexis"), screen, font, 100, 510);
        }


    }





SDL_Quit();




return 0; // ou 1 si on gagne

}



#endif
