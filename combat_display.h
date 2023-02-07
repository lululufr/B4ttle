#ifndef B4TTLE_COMBAT_DISPLAY_H
#define B4TTLE_COMBAT_DISPLAY_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "monster.h"
#include "combat.h"





int print_card_sdl(card *card,SDL_Surface * screen,TTF_Font *font,int x, int y){
    SDL_Surface * SDL_cards;
    SDL_Rect pos, pos_stat;

    SDL_Surface *message;
    SDL_Color color = {200,45,75};

//on va modif ca
    char str[100];
    sprintf(str,"%s",card->name);

    message = TTF_RenderText_Solid(font, str, color);


    char way [50] = "cards_png/";
    strcat(way, card->name);
    SDL_cards = IMG_Load(way);

    pos.x = x;
    pos.y = y;

    pos_stat.x = x+5;
    pos_stat.y = y+5;

    SDL_BlitSurface(SDL_cards, NULL, screen, &pos);
    SDL_BlitSurface(message, NULL, screen, &pos_stat);

    SDL_Flip(screen);

}




/*
int fight_print_sdl()
{
    SDL_Surface *screen, *card_own_1, *card_own_2, *card_own_3, *card_own_4 ,*card_ad_1, *card_ad_2, *card_ad_3, *card_ad_4;
    SDL_Rect pos_own_1, pos_own_2, pos_own_3, pos_own_4 ,pos_ad_1,pos_ad_2,pos_ad_3,pos_ad_4;


    //SDL_Surface *stats_own_1, *stats_own_2, *stats_own_3, *stats_own_4,
    SDL_Surface * card_hover;
    SDL_Rect pos_stats_own_1, pos_stats_own_2, pos_stats_own_3, pos_stats_own_4, pos_stats_ad_1, pos_stats_ad_2, pos_stats_ad_3, pos_stats_ad_4;


    //font

    TTF_Font *font;
    SDL_Color color = {200,45,75};
    SDL_Surface *message;

    // Init
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(975, 650, 32, SDL_HWSURFACE);


    // images des cartes du haut
    card_own_1 = IMG_Load("cards_png/portrait.png");
    card_own_2 = IMG_Load("cards_png/portrait.png");
    card_own_3 = IMG_Load("cards_png/portrait.png");
    card_own_4 = IMG_Load("cards_png/portrait.png");


    // images des cartes du bas
    card_ad_1 = IMG_Load("cards_png/portrait.png");
    card_ad_2 = IMG_Load("cards_png/portrait.png");
    card_ad_3 = IMG_Load("cards_png/portrait.png");
    card_ad_4 = IMG_Load("cards_png/portrait.png");

    // Position des cartes du haut
    pos_own_1.x = 50;
    pos_own_1.y = 50;
    pos_own_2.x = 250;
    pos_own_2.y = 50;
    pos_own_3.x = 450;
    pos_own_3.y = 50;
    pos_own_4.x = 650;
    pos_own_4.y = 50;


    //carré de stats du haut
    pos_stats_own_1.w = 40;
    pos_stats_own_1.h = 70;
    pos_stats_own_1.x = pos_own_1.x + card_own_1->w;
    pos_stats_own_1.y = pos_own_1.y;
    pos_stats_own_2.w = 40;
    pos_stats_own_2.h = 70;
    pos_stats_own_2.x = pos_own_2.x + card_own_2->w;
    pos_stats_own_2.y = pos_own_2.y;
    pos_stats_own_3.w = 40;
    pos_stats_own_3.h = 70;
    pos_stats_own_3.x = pos_own_3.x + card_own_3->w;
    pos_stats_own_3.y = pos_own_3.y;
    pos_stats_own_4.w = 40;
    pos_stats_own_4.h = 70;
    pos_stats_own_4.x = pos_own_4.x + card_own_4->w;
    pos_stats_own_4.y = pos_own_4.y;

    pos_stats_ad_1.w = 40;
    pos_stats_ad_1.h = 70;
    pos_stats_ad_1.x = pos_ad_1.x + card_ad_1->w;
    pos_stats_ad_1.y = pos_ad_1.y;
    pos_stats_ad_2.w = 40;
    pos_stats_ad_2.h = 70;
    pos_stats_ad_2.x = pos_ad_2.x + card_ad_2->w;
    pos_stats_ad_2.y = pos_ad_2.y;
    pos_stats_ad_3.w = 40;
    pos_stats_ad_3.h = 70;
    pos_stats_ad_3.x = pos_ad_3.x + card_ad_3->w;
    pos_stats_ad_3.y = pos_ad_3.y;
    pos_stats_ad_4.w = 40;
    pos_stats_ad_4.h = 70;
    pos_stats_ad_4.x = pos_ad_4.x + card_ad_4->w;
    pos_stats_ad_4.y = pos_ad_4.y;





    // position des cartes du bas
    pos_ad_1.x = 50;
    pos_ad_1.y = 500;
    pos_ad_2.x = 250;
    pos_ad_2.y = 500;
    pos_ad_3.x = 450;
    pos_ad_3.y = 500;
    pos_ad_4.x = 650;
    pos_ad_4.y = 500;
    //


    TTF_Init();
    font = TTF_OpenFont("font/starjedi.ttf", 24);

    message = TTF_RenderText_Solid(font, "Hello World", color);



    // Boucle de rendu
    int quit = 0;
    SDL_Event event;
    while (!quit)
    {
        // Gestion des événements
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
            }
        }

        // Effacement de la fenêtre
        SDL_FillRect(screen, NULL, 0x000000);

        // Affichage des cartes
        SDL_BlitSurface(card_own_1, NULL, screen, &pos_own_1);
        SDL_BlitSurface(card_own_2, NULL, screen, &pos_own_2);
        SDL_BlitSurface(card_own_3, NULL, screen, &pos_own_3);
        SDL_BlitSurface(card_own_4, NULL, screen, &pos_own_4);

        SDL_BlitSurface(card_ad_1, NULL, screen, &pos_ad_1);
        SDL_BlitSurface(card_ad_2, NULL, screen, &pos_ad_2);
        SDL_BlitSurface(card_ad_3, NULL, screen, &pos_ad_3);
        SDL_BlitSurface(card_ad_4, NULL, screen, &pos_ad_4);

        //SDL_FillRect(,&pos_stats_own_1 ,0xff0000);
        //SDL_FillRect(pos_stats_own_2,& ,0x00ff00);
        //SDL_FillRect(pos_stats_own_3,& ,0x0000ff);
        //SDL_FillRect(pos_stats_own_4,& ,0xffff00);

        //SDL_BlitSurface(message, NULL, card_own_1, &pos_stats_own_1);
        //SDL_BlitSurface(message, NULL, card_own_2, &pos_stats_own_2);
        //SDL_BlitSurface(message, NULL, card_own_3, &pos_stats_own_3);
        //SDL_BlitSurface(message, NULL, card_own_4, &pos_stats_own_4);

        SDL_BlitSurface(message, NULL, screen, &pos_stats_own_1);
        SDL_BlitSurface(message, NULL, screen, &pos_stats_own_2);
        SDL_BlitSurface(message, NULL, screen, &pos_stats_own_3);
        SDL_BlitSurface(message, NULL, screen, &pos_stats_own_4);

        SDL_BlitSurface(message, NULL, screen, &pos_stats_ad_1);
        SDL_BlitSurface(message, NULL, screen, &pos_stats_ad_2);
        SDL_BlitSurface(message, NULL, screen, &pos_stats_ad_3);
        SDL_BlitSurface(message, NULL, screen, &pos_stats_ad_4);





        //SDL_BlitSurface(message, NULL, screen, NULL);


        // Mise à jour de la fenêtre
        SDL_Flip(screen);
    }








    // Nettoyage
    //SDL_FreeSurface(card_own_1);
    //SDL_FreeSurface(card_own_2);
    //SDL_FreeSurface(card_own_3);
    //SDL_FreeSurface(card_own_4);
    //SDL_FreeSurface(card_adv_1);
    //SDL_FreeSurface(card_adv_2);
    //SDL_FreeSurface(card_adv_3);
    //SDL_FreeSurface(card_adv_4);
    SDL_Quit();


    return 0;
}*/


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
        SDL_WaitEvent(&event);

        if (event.type == SDL_QUIT) {
            break;
        }

        // déplacement menu
        Chain * chosen_card;
        int pos;
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
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
            }
        }
        }
        SDL_FillRect(screen, NULL, 0xffffff);
        print_card_sdl(Read_Card("ELEFTERIOU_Alexis"), screen,font,100,510);

    }

// Met à jour l'écran !!!!!!!
SDL_Flip(ecran);
}


SDL_Quit();




return 0; // ou 1 si on gagne

}

}

#endif
