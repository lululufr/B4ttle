#ifndef B4TTLE_COMBAT_DISPLAY_H
#define B4TTLE_COMBAT_DISPLAY_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "monster.h"
#include "combat.h"

#define SCREEN_WIDTH  1280
#define SCREEN_HEIGHT 832

typedef struct card_sdl{

    SDL_Surface * SDL_card;
    SDL_Surface * message_nom,*message_hp,*message_atk;

} card_sdl ;



card_sdl * init_card_sdl(card_sdl * cardsdl, card * card, TTF_Font *font){

    SDL_Color rouge = {200,45,75};
    SDL_Color blanc = {255,255,255};
    SDL_Color vert = {45,45,125};

    //char str[50];
    char * way = malloc(sizeof(char)*strlen(card->name)+20);
    char * str = malloc(sizeof(char)*strlen(card->name)+20);

    sprintf(way, "cards_png/%s", card->name);
    cardsdl->SDL_card = IMG_Load(way);

    sprintf(str, "%s", card->name);
    cardsdl->message_nom = TTF_RenderText_Solid(font, str, blanc);

    sprintf(str, "Vie : %d", card->hp);
    cardsdl->message_hp = TTF_RenderText_Solid(font, str, vert);

    sprintf(str, "Attaque : %d", card->atk);
    cardsdl->message_atk = TTF_RenderText_Solid(font, str, rouge);

    free(way);
    free(str);

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


    SDL_BlitSurface(card_sdl->message_nom, NULL, screen, &pos_nom);
    SDL_BlitSurface(card_sdl->message_hp, NULL, screen, &pos_hp);
    SDL_BlitSurface(card_sdl->message_atk, NULL, screen, &pos_atk);
    SDL_BlitSurface(card_sdl->SDL_card, NULL, screen, &pos);



    //SDL_FreeSurface(card_sdl->SDL_card);
    //SDL_FreeSurface(card_sdl->message_hp);
    //SDL_FreeSurface(card_sdl->message_atk);
    //SDL_FreeSurface(card_sdl->message_nom);


}


//la





char ** optionMenu() {
    const int numStrings = 3;
    const int maxStringLength = 20;

    char **stringArray = malloc(numStrings * sizeof(char *)+10);
    for (int i = 0; i < numStrings; i++) {
        stringArray[i] = malloc(maxStringLength * sizeof(char)+10);
    }

    strncpy(stringArray[0], "Attaque", maxStringLength);
    strncpy(stringArray[1], "Pouvoir", maxStringLength);
    strncpy(stringArray[2], "Passer", maxStringLength);

    return stringArray;

}


int menuSelection(SDL_Surface* screen, TTF_Font* font, char** options, int numOptions) {
    int MENU_WIDTH = 150;
    int MENU_HEIGHT = 150;
    int MENU_X = 800;
    int MENU_Y = 470; //(SCREEN_HEIGHT - MENU_HEIGHT) / 2;
    int MENU_SPACING = 20;


    SDL_Surface *menu = SDL_CreateRGBSurface(SDL_HWSURFACE, MENU_WIDTH, MENU_HEIGHT, 32, 0, 0, 0, 0);

    SDL_FillRect(menu, NULL, SDL_MapRGB(menu->format, 255, 255, 255));

    SDL_Color text_color = {0, 0, 0};
    SDL_Rect option_pos = {MENU_SPACING, MENU_SPACING, 0, 0};
    SDL_Surface *option_surfaces[numOptions];

    for (int i = 0; i < numOptions; i++) {
        option_surfaces[i] = TTF_RenderText_Solid(font, options[i], text_color);
        SDL_BlitSurface(option_surfaces[i], NULL, menu, &option_pos);
        option_pos.y += option_surfaces[i]->h + MENU_SPACING;
    }

    // Création d'une surface pour la sélection
    SDL_Surface *selection = SDL_CreateRGBSurface(SDL_HWSURFACE, 16, option_surfaces[0]->h,
                                                  32, 0, 0, 0, 0);
    SDL_FillRect(selection, NULL, SDL_MapRGB(selection->format, 255, 0, 0));

// Boucle principale
    bool quit = false;
    int selectedOption = 0;
    while (!quit) {
        // Gestion des événements
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    return 9;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_UP:
                            selectedOption = (selectedOption - 1 + numOptions) % numOptions;
                            break;
                        case SDLK_DOWN:
                            selectedOption = (selectedOption + 1) % numOptions;
                            break;
                        case SDLK_RETURN:
                            return selectedOption;

                    }
                    break;
            }
        }
        // Affichage de la sélection

        // Affichage du menu


        SDL_Rect menu_pos = {MENU_X, MENU_Y, 0, 0};
        SDL_BlitSurface(menu, NULL, screen, &menu_pos);
        SDL_Rect selection_pos = {MENU_X + 2,
                                  MENU_Y + MENU_SPACING + selectedOption * (option_surfaces[0]->h + MENU_SPACING), 0,
                                  0};

        SDL_BlitSurface(selection, NULL, screen, &selection_pos);




        // Mise à jour de l'écran
        SDL_Flip(screen);
    }

// Libération de la mém
    SDL_FreeSurface(menu);
    SDL_FreeSurface(selection);
    for (int i = 0; i < numOptions; i++) {
        SDL_FreeSurface(option_surfaces[i]);
    }

    return selectedOption;
}

int choixadv(SDL_Surface* screen ,Chain * chain) {


    SDL_Surface *pointeur_adv ;


    SDL_Surface *selection = SDL_CreateRGBSurface(SDL_HWSURFACE, 16, 30,
                                                  32, 0, 0, 0, 0);

    SDL_FillRect(selection, NULL, SDL_MapRGB(pointeur_adv->format, 255, 0, 0));

    int selectedOption = 0;
    int numOptions = Chain_length(chain);

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                return 9;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_RIGHT:
                        selectedOption = (selectedOption - 1 + numOptions) % numOptions;
                        break;
                    case SDLK_LEFT:
                        selectedOption = (selectedOption + 1) % numOptions;
                        break;
                    case SDLK_RETURN:
                        return selectedOption;

                }
                break;


                SDL_Rect selection_pos = {10,20, 30,30};

                SDL_BlitSurface(pointeur_adv, NULL, screen, &selection_pos);

                SDL_Flip(screen);
        }

    }
}


int fight_print_sdl(Chain * player, Chain * opponent){
    int choix;
    int i;
    //why on a pas besoin de init le sdl ?
    TTF_Init();


    SDL_Surface *screen;
    screen = SDL_SetVideoMode(975, 650, 32, SDL_HWSURFACE);

    TTF_Font *font;
    font = TTF_OpenFont("font/starjedi.ttf", 12);

    //preparation
    card_sdl * card1 = malloc(sizeof(card_sdl)+100);
    card_sdl * card2 = malloc(sizeof(card_sdl)+100);
    card_sdl * card3 = malloc(sizeof(card_sdl)+100);
    card_sdl * card4 = malloc(sizeof(card_sdl)+100);

    card_sdl * card_adv1 = malloc(sizeof(card_sdl)+100);
    card_sdl * card_adv2 = malloc(sizeof(card_sdl)+100);
    card_sdl * card_adv3 = malloc(sizeof(card_sdl)+100);
    card_sdl * card_adv4 = malloc(sizeof(card_sdl)+100);

    init_card_sdl(card1,Read_Card("ELEFTERIOU_Alexis"),font);
    init_card_sdl(card2,Read_Card("MILLER_Lucas"),font);
    init_card_sdl(card3,Read_Card("SAGE_Julien"),font);
    init_card_sdl(card4,Read_Card("KAKOU_Marceau"),font);

    init_card_sdl(card_adv1,Read_Card("ELEFTERIOU_Alexis"),font);
    init_card_sdl(card_adv2,Read_Card("ELEFTERIOU_Alexis"),font);
    init_card_sdl(card_adv3,Read_Card("ELEFTERIOU_Alexis"),font);
    init_card_sdl(card_adv4,Read_Card("ELEFTERIOU_Alexis"),font);
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

    print_card_sdl(card1, screen, 150, 510);
    print_card_sdl(card2, screen, 300, 510);
    print_card_sdl(card3, screen, 450, 510);
    print_card_sdl(card4, screen, 600, 510);


    print_card_sdl(card_adv1, screen, 150 ,110);
    print_card_sdl(card_adv2, screen, 300 ,110);
    print_card_sdl(card_adv3, screen, 450 ,110);
    print_card_sdl(card_adv4, screen, 600 ,110);

//affichage menu
        //menuSelection(screen, font, optionMenu(), 3);
//
choix = menuSelection(screen, font, optionMenu(), 3);

      if (choix == 9) {
          break; // pourquitter
      }else if (choix == 0){
          choixadv(screen, opponent);
      }else if (choix == 1){
          printf("hello 2 ");
      }else if (choix == 2){
      printf("hello 3 ");
  }
//SDL_FillRect(screen, NULL, 0x000000);
    SDL_Flip(screen);
    }




    free(card1);
SDL_Quit();




return 0; // ou 1 si on gagne

}



#endif
