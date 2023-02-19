#ifndef B4TTLE_CARD_H
#define B4TTLE_CARD_H

typedef struct card {
    char * name;
    int id;
    int hp;
    int atk;
    char * desc;
    void * competence;
    char * comp_desc;
}card;


typedef struct fonction{
    char * name;
    //(*void)(void*, void*) function;
}Fonction;

#endif