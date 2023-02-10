#ifndef B4TTLE_COMBAT_DISPLAY_H
#define B4TTLE_COMBAT_DISPLAY_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "monster.h"
#include "combat.h"

typedef struct card_sdl{

    SDL_Surface * SDL_card;
    SDL_Surface * message_nom,*message_hp,*message_atk;

} card_sdl ;



card_sdl * init_card_sdl(card_sdl * cardsdl, card * card, TTF_Font *font){

    SDL_Color rouge = {200,45,75};
    SDL_Color blanc = {255,255,255};
    SDL_Color vert = {45,45,125};

    char str[100];
    char way[100];

    sprintf(way, "cards_png/%s", card->name);
    cardsdl->SDL_card = IMG_Load(way);

    sprintf(str, "%s", card->name);
    cardsdl->message_nom = TTF_RenderText_Solid(font, str, blanc);

    sprintf(str, "Vie : %d", card->hp);
    cardsdl->message_hp = TTF_RenderText_Solid(font, str, vert);

    sprintf(str, "Attaque : %d", card->atk);
    cardsdl->message_atk = TTF_RenderText_Solid(font, str, rouge);

 return cardsdl;

}

void print_card_sdl(card_sdl * card_sdl, SDL_Surface * screen,int x, int y){

    //SDL_Surface * SDL_card;

    SDL_Rect pos, pos_nom,pos_hp,pos_atk;

    //message

    pos.x = x;
    pos.y = y;

    pos_nom.x = x - 10;
    pos_nom.y = y - 20;

    pos_hp.x = x + 30;
    pos_hp.y = y + 20;

    pos_atk.x = x + 30;
    pos_atk.y = y + 30;

    SDL_BlitSurface(card_sdl->SDL_card, NULL, screen, &pos);
    SDL_BlitSurface(card_sdl->message_nom, NULL, screen, &pos_nom);
    SDL_BlitSurface(card_sdl->message_hp, NULL, screen, &pos_hp);
    SDL_BlitSurface(card_sdl->message_atk, NULL, screen, &pos_atk);


    //SDL_FreeSurface(card->SDL_card);
    //SDL_FreeSurface(message_hp);
    //SDL_FreeSurface(message_atk);
    //SDL_FreeSurface(message_nom);
}



int fight_print_sdl(){
    int i;
    //why on a pas besoin de init le sdl ?
    TTF_Init();


    SDL_Surface *screen;
    screen = SDL_SetVideoMode(975, 650, 32, SDL_HWSURFACE);

    TTF_Font *font;
    font = TTF_OpenFont("font/starjedi.ttf", 12);

    //preparation
    card_sdl card1;

    init_card_sdl(&card1,Read_Card("ELEFTERIOU_Alexis"),font);
    //preparation


    // Boucle de rendu
    int quit = 0;
    SDL_Event event;


    while (1)
    {
        SDL_WaitEvent(&event);


        if (event.type == SDL_QUIT) {
            break;
        }
//affichage
        for(i=1;i<5;++i){ //haut
            print_card_sdl(&card1, screen, i*150, 110); // faudra print ca mdr
        }
        for(i=1;i<5;++i){ //bas
            print_card_sdl(&card1, screen, i*150 ,510); // faudra print ca mdr
        }
        SDL_Flip(screen);
//affichage

// déplacement menu
        //Chain * chosen_card;
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
                    break;
                case SDLK_KP_ENTER:*/

            }


        }
SDL_FillRect(screen, NULL, 0x000000);

    }





SDL_Quit();




return 0; // ou 1 si on gagne

}



#endif
