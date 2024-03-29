#ifndef B4TTLE_COMBAT_H
#define B4TTLE_COMBAT_H

#include "struct.h"
#include "monster.h"
#include "combat_display.h"
//fPIC pour faire des fichiers .so
//.so
//-fPIC-shared


Chain * Chain_empty(){
    Chain * empty= malloc(sizeof(Chain));
    return empty;
}

void Chain_Free(Chain * liste){
    Chain * current = liste;
    Chain * next;
    while (current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    liste = NULL;
}

int Chain_add_tail(Chain * chaine, card * carte){
    Chain * current = chaine;
    if ((*current).next == NULL){
        Chain * newChain = Chain_empty();
        (*newChain).carte = carte;
        (*newChain).next = NULL;
        (*current).next= newChain;
    } else {
        while (current->next != NULL){
            current = current->next;
        }
        current->next = (Chain *) malloc(sizeof(Chain));
        current->next->carte = carte;
        current->next->next = NULL;
    }
    return 0;
}

void Chain_pop_BOOM(Chain ** chain){
    *chain = (*chain)->next;
}

void Chain_delete(Chain **chain, int id) {
    Chain *current = *chain;
    Chain *previous = NULL;
    if(id==0){
        (*chain)->cardSdl=NULL;
        return;
    }
    int i = 0;
    while (current != NULL && i != id) {
        previous = current;
        current = current->next;
        i++;
    }
    if (current == NULL) {
        // L'élément n'a pas été trouvé
        return;
    }
    if (previous == NULL) {
        // L'élément à supprimer est en tête de liste
        *chain = current->next;
    } else {
        // L'élément à supprimer est ailleurs dans la liste
        previous->next = current->next;
    }
    free(current);
}


int Chain_insert(Chain * liste, int id, card * carte){
    Chain * current= liste;
    Chain * newchain;
    int i=0;
    while (i!=id){
        current = (*current).next;
        ++i;
    }
    newchain = (Chain *) malloc(sizeof (Chain));
    newchain->carte= carte;
    newchain->next = current->next;
    (*current).next = newchain;
    return 0;
}


int Chain_length(Chain *chain) {
    int cpt = 0;
    Chain *current = chain;
    if (current == NULL || current->carte == NULL) {
        return 0;
    }
    while (current->next != NULL) {
        cpt++;
        current = current->next;
    }
    return cpt + 1;
}



int win(Chain * player, Chain * opponent){
    if(Chain_length(player)==1&&player->carte->hp<=0){
        return 0;
    }
    if(Chain_length(opponent)==1 &&opponent->carte->hp<=0){
        return -1;
    }else{
        return 1;
    }

}


Chain * Chain_get(Chain * chain, int id){
    Chain * current= chain;
    //printf("%d", id);
    int i=0;
    if(i>=id){
        return current;
    }
    while (i!=id){
        current = (*current).next;
        ++i;
    }
    return current;
}
Chain * Chain_next(Chain * chain, int * i){
    ++(*i);
    return chain->next;
}

void attack(int attack, Chain * enemyChain, int enemy_id,TTF_Font *font){
    SDL_Color rouge = {255,35,35};
    SDL_Color blanc = {255,255,255};
    SDL_Color vert = {59,208,108};
    printf("test");

    if(Chain_length(enemyChain)) {
        Chain * enemy = malloc(sizeof (Chain));
        enemy = Chain_get(enemyChain,enemy_id);

        if ((enemy->carte->hp -= attack) <=0) {
            enemy->cardSdl=NULL;
            Chain_delete(&enemyChain, enemy_id);
        }else{
            char * str = malloc(sizeof(char)*30);
            sprintf(str, "Vie     %d", enemy->carte->hp);
            enemy->cardSdl->message_hp = TTF_RenderText_Solid(font, str, vert);
        }
    } else{
        printf("chaine vide");
        exit(EXIT_FAILURE);
    }

}



#endif