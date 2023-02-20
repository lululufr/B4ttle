#ifndef B4TTLE_CARD_H
#define B4TTLE_CARD_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

typedef struct Chain {
    struct card * carte;
    struct card_sdl * cardSdl;
    struct Chain * next;
} Chain;

typedef struct fonction{
    int number;
    char ** name;
    void (*competence[])(Chain * chain);
}Fonction;

typedef struct card {
    char * name;
    int id;
    int hp;
    int atk;
    char * desc;
    void (*competence)(Chain * chain);
    char * comp_desc;
}card;

typedef struct card_sdl{

    SDL_Surface * SDL_card;
    SDL_Surface * message_nom,*message_hp,*message_atk;

} card_sdl ;

typedef struct Map{
    char * name;
    char * map;
    int width;
}Map;
#endif