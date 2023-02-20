#ifndef B4TTLE_COMPETENCE_H
#define B4TTLE_COMPETENCE_H

#endif //B4TTLE_COMPETENCE_H
#include "struct.h"
#include "combat.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
/*
void ELEFTERIOU_Alexis(Chain * chain){
    TTF_Font *font;
    font = TTF_OpenFont("font/Roboto-Black.ttf", 16);
    int i, len= Chain_length(chain),minhp=chain->carte->hp;
    for(i=0;i<len;++i){
        if(minhp> Chain_get(chain,i)->carte->hp){
            minhp=Chain_get(chain,i)->carte->hp;
        }
    }
    attack(10,chain,minhp,font);
}

void  MILLER_Lucas(Chain * chain){
    Chain * ahah = Chain_empty();
    Chain_pop_BOOM(&ahah);
}

void FRESSE_Balkis(Chain * chain){
    TTF_Font *font;
    font = TTF_OpenFont("font/Roboto-Black.ttf", 16);
    int i, len= Chain_length(chain);
    for(i=0;i<len;++i){
        attack(3,chain,i,font);
    }
}


void Create_func_struct(Fonction * func){
    void (*competences[3])(Chain *)={//je stock les pointeurs dans un tableau pour les donner a ma structure
            ELEFTERIOU_Alexis,
            MILLER_Lucas,
            FRESSE_Balkis
    };
    char * names[3]={//pareil avec les noms
            "ELEFTERIOU Alexis",
            "MILLER Lucas",
            "FRESSE Balkis"
    };
    int i;
    func->name = malloc(sizeof(char*) * 3);
    for(i=0;i<3;++i){
        func->competence[i]=competences[i];
        func->name[i] = malloc(strlen(names[i]) + 1);
        strcpy(func->name[i], names[i]);
    }
    func->number=3;
}*/