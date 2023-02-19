#ifndef B4TTLE_COMBAT_DISPLAY_H
#define B4TTLE_COMBAT_DISPLAY_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "monster.h"
#include "combat.h"
#include <time.h>
#define SCREEN_WIDTH  1280
#define SCREEN_HEIGHT 832




card_sdl * init_card_sdl(card_sdl * cardsdl, card * card, TTF_Font *font){

    SDL_Color rouge = {255,35,35};
    SDL_Color blanc = {255,255,255};
    SDL_Color vert = {59,208,108};

    //char str[50];
    char * way = malloc(sizeof(char)*strlen(card->name)+20);
    char * str = malloc(sizeof(char)*strlen(card->name)+20);

    sprintf(way, "cards_png/%s", card->name);
    cardsdl->SDL_card = IMG_Load(way);

    sprintf(str, "%s", card->name);
    cardsdl->message_nom = TTF_RenderText_Solid(font, str, blanc);

    sprintf(str, "Vie     %d", card->hp);
    cardsdl->message_hp = TTF_RenderText_Solid(font, str, vert);

    sprintf(str, "Attaque     %d", card->atk);
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

    pos_nom.x = x;
    pos_nom.y = y - 20;

    pos_hp.x = x + 10;
    pos_hp.y = y + 160;

    pos_atk.x = x + 10;
    pos_atk.y = y + 145;


    SDL_BlitSurface(card_sdl->message_nom, NULL, screen, &pos_nom);
    SDL_BlitSurface(card_sdl->message_hp, NULL, screen, &pos_hp);
    SDL_BlitSurface(card_sdl->message_atk, NULL, screen, &pos_atk);
    SDL_BlitSurface(card_sdl->SDL_card, NULL, screen, &pos);



    //SDL_FreeSurface(card_sdl->SDL_card);
    //SDL_FreeSurface(card_sdl->message_hp);
    //SDL_FreeSurface(card_sdl->message_atk);
    //SDL_FreeSurface(card_sdl->message_nom);


}





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
    int MENU_WIDTH = 140;
    int MENU_HEIGHT = 140;
    int MENU_X = 1000;
    int MENU_Y = 600; //(SCREEN_HEIGHT - MENU_HEIGHT) / 2;
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
                    SDL_Quit();
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

int choixadv(SDL_Surface* screen, Chain* chain, TTF_Font *font) {

    SDL_Surface* pointeur_adv = SDL_CreateRGBSurface(SDL_HWSURFACE, 150, 10, 32, 0, 0, 0, 0);
    SDL_FillRect(pointeur_adv, NULL, SDL_MapRGB(pointeur_adv->format, 254, 0, 0));

    int selectedOption = 1;
    int numOptions = Chain_length(chain);

    SDL_Event event;
    while (1) {
        // Effacer l'écran
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
        // Afficher le menu

        int i;
        for (i = 1; i <= numOptions; i++) {
            Chain * element = Chain_get(chain, i-1);
            SDL_Color color = {255, 255, 255};
            if (i == selectedOption) {
                // Afficher le pointeur sur l'option sélectionnée
                SDL_Rect selection_pos = {130+250*(i-1), 450, 5, 5};
                SDL_BlitSurface(pointeur_adv, NULL, screen, &selection_pos);
                //color = {255, 0, 0};
            }
            char * buffer = malloc(sizeof (char)* strlen(element->carte->name)+2);
            strcpy(buffer,element->carte->name);
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, buffer, color);
            SDL_Rect text_pos = {130+250*(i-1), 430, textSurface->w, textSurface->h};
            SDL_BlitSurface(textSurface, NULL, screen, &text_pos);
            SDL_FreeSurface(textSurface);
            free(buffer);
        }
        // Afficher le résultat à l'écran
        SDL_Flip(screen);


        // Lire les événements SDL
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    SDL_Quit();
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_LEFT:
                            selectedOption = (selectedOption - 1 + numOptions+1) % (numOptions+1);
                            break;
                        case SDLK_RIGHT:
                            selectedOption = (selectedOption + 1) % (numOptions+1);
                            break;
                        case SDLK_RETURN:
                            if(selectedOption== Chain_length(chain)+1){
                                choixadv(screen, chain,font);
                            }
                            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
                            return selectedOption-1;
                        default:
                            break;
                    }
                    break;
            }
        }
    }
}





void print_tour(SDL_Surface *screen, card * text,TTF_Font *font) {

    SDL_Color text_color = {255, 255, 255};
    SDL_Color tour_color = {255, 35, 35};
    SDL_Rect text_position,desc_position,comp_position;
    SDL_Surface *text_surface,*desc_surface,*comp_surface;

    SDL_Rect tour_position,descdesc_position,compcomp_position;
    SDL_Surface *tour_surface, *descdesc_surface,*compcomp_surface;


    tour_surface = TTF_RenderText_Solid(font, "Tour de : ", tour_color);
    tour_position.x = 30;
    tour_position.y = 85;
    SDL_BlitSurface(tour_surface, NULL, screen, &tour_position);

    text_surface = TTF_RenderText_Solid(font, text, text_color); // Rendre la surface de texte avec la police, le texte et la couleur
    text_position.x = 30;
    text_position.y = 100;
    SDL_BlitSurface(text_surface, NULL, screen, &text_position); // Dessiner la surface de texte à l'écran

   desc_surface = TTF_RenderText_Solid(font, "Description :", tour_color);
   desc_position.x = 30;
   desc_position.y = 20;
   SDL_BlitSurface(desc_surface, NULL, screen, &desc_position);

   descdesc_surface = TTF_RenderText_Solid(font, text->desc, text_color);
   descdesc_position.x = 30;
   descdesc_position.y = 35;
   SDL_BlitSurface(descdesc_surface, NULL, screen, &descdesc_position);

    comp_surface = TTF_RenderText_Solid(font, "Competence :", tour_color);
    comp_position.x = 30;
    comp_position.y = 55;
    SDL_BlitSurface(comp_surface, NULL, screen, &comp_position);

    compcomp_surface = TTF_RenderText_Solid(font, text->comp_desc, text_color);
    compcomp_position.x = 30;
    compcomp_position.y = 70;
    SDL_BlitSurface(compcomp_surface, NULL, screen, &compcomp_position);


    SDL_FreeSurface(text_surface); // Libérer la mémoire utilisée par la surface de texte
    SDL_FreeSurface(tour_surface);
    SDL_FreeSurface(desc_surface); // Libérer la mémoire utilisée par la surface de texte
    SDL_FreeSurface(descdesc_surface);
    SDL_FreeSurface(comp_surface);
    SDL_FreeSurface(compcomp_surface);

}

void tour_adversaire(SDL_Surface* screen,TTF_Font* font) {
    // Afficher un écran noir
    SDL_Color bl = {255,255,255};
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

    // Écrire "Au tour de l'adversaire" au centre de l'écran

    SDL_Surface *text_surface = TTF_RenderText_Solid(font, "Au tour de l'adversaire", bl);

    SDL_Rect text_rect;
    text_rect.x =  100;
    text_rect.y =  100;

    SDL_BlitSurface(text_surface, NULL, screen, &text_rect);
    SDL_FreeSurface(text_surface);
    //SDL_Surface *text_surface = TTF_RenderText_Solid(font, "Au tour de l'adversaire", noir);


    // Afficher la barre de chargement
    SDL_Rect progress_bar_rect;
    progress_bar_rect.x = (screen->w - 200) / 2;
    progress_bar_rect.y = text_rect.y + text_surface->h + 20;
    progress_bar_rect.w = 200;
    progress_bar_rect.h = 20;
    SDL_Rect progress_rect = progress_bar_rect;
    progress_rect.w = 0;
    Uint32 start_time = SDL_GetTicks();
    Uint32 elapsed_time = 0;

    while (elapsed_time < 5000) {
    // Afficher la barre de chargement
    SDL_FillRect(screen, &progress_bar_rect, SDL_MapRGB(screen->format, 255, 255, 255));

    SDL_FillRect(screen, &progress_rect, SDL_MapRGB(screen->format, 255, 0, 0));

    SDL_UpdateRect(screen, progress_bar_rect.x, progress_bar_rect.y, progress_bar_rect.w, progress_bar_rect.h);

    // Attendre un peu pour simuler le chargement
    SDL_Delay(50);

    // Mettre à jour la barre
    elapsed_time = SDL_GetTicks() - start_time;
    float progress = (float) elapsed_time / 5000;
    progress_rect.w = progress_bar_rect.w * progress;
    }
}

int fight_print_sdl(Chain * player, Chain * opponent) {
    int choix;
    int choix_adv;
    int i;
    Chain * current;
    Chain * print_card;
    //why on a pas besoin de init le sdl ?
    TTF_Init();

    SDL_Surface *screen;
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    TTF_Font *font;
    font = TTF_OpenFont("font/Roboto-Black.ttf", 16);

    //IMAGE EN BACK
    SDL_Surface *imageback = IMG_Load("media/background.jpg");

    SDL_Surface *backgroud = SDL_DisplayFormat(imageback);
    SDL_FreeSurface(imageback);
    SDL_Rect destRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};


    //preparation des cartes
    card_sdl * array_player[4];
    card_sdl * array_adv[4];


    i=0;

    for (i = 0; i < 4; ++i) {
        array_player[i] = malloc(5 * sizeof(card_sdl)+100);
        current= Chain_get(player,i);
        current->cardSdl = init_card_sdl(array_player[i], current->carte, font);

        array_adv[i] = malloc(5 * sizeof(card_sdl)+100);
        current= Chain_get(opponent,i);
        current->cardSdl =init_card_sdl(array_adv[i], current->carte, font);
    }
    i=0;


    //preparation


    // Boucle de rendu
    int quit = 0;
    SDL_Event event;
    int tour_carte = 0, random,random_2,cpt=0;


    while (1) {
        while ((tour_carte != Chain_length(player))) {
            current = Chain_get(player, tour_carte);
            //SDL_WaitEvent(&event);

            if (event.type == SDL_QUIT) {
                break;
            }

//affichage
            SDL_BlitSurface(backgroud, NULL, screen, &destRect);//background
            cpt =0;
            print_card = player;

            if(print_card!=NULL) {
                print_card_sdl(print_card->cardSdl, screen, 50, 410);
            }
            if (print_card->next!=NULL) {
                print_card = Chain_next(print_card, &cpt);
                print_card_sdl(print_card->cardSdl, screen, 100 + 225 * cpt, 600);
            }
            if (print_card->next!=NULL) {
                print_card = Chain_next(print_card, &cpt);
                print_card_sdl(print_card->cardSdl, screen, 100 + 225 * cpt, 600);
            }
            if (print_card->next!=NULL) {
                print_card= Chain_next(print_card,&cpt);
                print_card_sdl(print_card->cardSdl, screen, 100 + 225 * cpt, 600);
            }

            cpt = 0;



            print_card=opponent;
            if(print_card!=NULL) {
                print_card_sdl(print_card->cardSdl, screen, 200, 110);
            }
            if (print_card->next!=NULL) {
                print_card = Chain_next(print_card, &cpt);
                print_card_sdl(print_card->cardSdl, screen, 300 + 225 * cpt, 200);
            }
            if (print_card->next!=NULL) {
                print_card = Chain_next(print_card, &cpt);
                print_card_sdl(print_card->cardSdl, screen, 300 + 225 * cpt, 200);
            }
            if (print_card->next!=NULL) {
                print_card= Chain_next(print_card,&cpt);
                print_card_sdl(print_card->cardSdl, screen, 300+225*cpt, 200);
            }




            print_tour(screen, current->carte, font);
//affichage menu
            //menuSelection(screen, font, optionMenu(), 3);
//
            choix = menuSelection(screen, font, optionMenu(), 3);

            if (choix == 9) {
                break; // pourquitter
            } else if (choix == 0) {
                choix_adv = choixadv(screen, opponent, font);
                if (choix_adv == 9) {
                    break;
                } else {
                    attack(current->carte->atk, opponent, choix_adv,font);
                }
            } else if (choix == 1) {
                printf("hello 2 ");
            } else if (choix == 2) {
                //++tour_carte;
            }
//SDL_FillRect(screen, NULL, 0x000000);
            //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

            SDL_Flip(screen);
            ++tour_carte;
        }

        tour_carte = 0;
        //à l'adversaire
        while(tour_carte != Chain_length(opponent)){
            printf("%d",tour_carte);
            current = Chain_get(opponent,tour_carte);
            ++tour_carte;
            random = rand()%1;
            random_2 =rand()% Chain_length(player);
            switch(random){
                case 0:
                    attack(current->carte->atk,player,random_2,font);
                    break;
                case 1:
                    //tbd current->carte->comp();
                    break;
            }
        }
        tour_adversaire(screen,font);
        tour_carte = 0;


        if(win(player, opponent)<=0){ break;}
    }


SDL_Quit();




return 0; // ou 1 si on gagne

}



#endif
