#ifndef B4TTLE_COMBAT_DISPLAY_H
#define B4TTLE_COMBAT_DISPLAY_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

int fight_print_sdl()
{
    SDL_Surface *screen, *card_own_1, *card_own_2, *card_own_3, *card_own_4 ,*card_ad_1, *card_ad_2, *card_ad_3, *card_ad_4;
    SDL_Rect pos_own_1, pos_own_2, pos_own_3, pos_own_4 ,pos_ad_1,pos_ad_2,pos_ad_3,pos_ad_4;
    SDL_Rect stats_own_1, stats_own_2, stats_own_3, stats_own_4;

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
    stats_own_1.w = 40;
    stats_own_1.h = 70;
    stats_own_1.x = pos_own_1.x + card_own_1->w;
    stats_own_1.y = pos_own_1.y;
    stats_own_2.w = 40;
    stats_own_2.h = 70;
    stats_own_2.x = pos_own_2.x + card_own_2->w;
    stats_own_2.y = pos_own_2.y;
    stats_own_3.w = 40;
    stats_own_3.h = 70;
    stats_own_3.x = pos_own_3.x + card_own_3->w;
    stats_own_3.y = pos_own_3.y;
    stats_own_4.w = 40;
    stats_own_4.h = 70;
    stats_own_4.x = pos_own_4.x + card_own_4->w;
    stats_own_4.y = pos_own_4.y;





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

        SDL_FillRect(screen, &stats_own_1, 0xff0000);
        SDL_FillRect(screen, &stats_own_2, 0x00ff00);
        SDL_FillRect(screen, &stats_own_3, 0x0000ff);
        SDL_FillRect(screen, &stats_own_4, 0xffff00);

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
}


#endif
