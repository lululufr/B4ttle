#ifndef DEF_HEADER_MONSTER
#define DEF_HEADER_MONSTER
#include <stdio.h>
#include <stdlib.h>

typedef struct card
{
    int id;
    char * nom;
    int vie;
    int atk;
    char * desc;
    void comp(){};
    
    char * comp_desc ;
} card ;



card * declare(int id, char * cardname){

    card->id = 1;
    


    return * card;
}





#endif