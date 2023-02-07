#ifndef B4TTLE_COMBAT_H
#define B4TTLE_COMBAT_H

#include "monster.h"
#include "combat_display.h"






typedef struct Chain {
    struct card * carte;
    struct Chain * next;
} Chain;

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

int Chain_delete(Chain * liste, int id){
    Chain * current = liste;
    Chain * previous = NULL;
    int i = 0;
    while (i < id && current != NULL){
        previous = current;
        current = current->next;
        ++i;
    }
    if (current == NULL){
        return -1;
    }
    if (previous == NULL){
        *liste = *current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    return 0;
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

int Chain_length(Chain * chain){
    int cpt=0;
    Chain * current= chain;
    if(current->carte== NULL){return 0;}
    while (current->next!=NULL){
        cpt++;
        current = (*current).next;
    }
    return cpt;
}

void Chain_print(const Chain * chain){
    while (chain->next != NULL){
        Print_Card(chain->carte);
        printf("\n");
        chain = chain->next;
    }
    Print_Card(chain->carte);
}

void attack(card * carte, int attack, Chain * enemyChain){
    if(Chain_length(enemyChain)) {
        if (carte->hp -= attack <= 0) {
            //
        }
    } else{

    }
}

void Chain_action(Chain * chain){
    while (chain->next != NULL){
        //SDL EVENT plus tard
    }
}

Chain * Chain_get(Chain * chain, int id){
    Chain * current= chain;
    int i=0;
    while (i!=id){
        current = (*current).next;
        ++i;
    }
    return current;
}


int fight(){
    Chain * player = Chain_empty(); //init du premier maillons
    Chain * opponent = Chain_empty(); //init de la chaine adv

    player->carte = Read_Card("ELEFTERIOU_Alexis");
    Chain_add_tail(player, Read_Card("AMBRY_Lukas"));
    Chain_add_tail(player, Read_Card("SAGE_Julien"));
    Chain_add_tail(player, Read_Card("KAKOU_Marceau"));


    opponent->carte = Read_Card("MECHOUCHE_Vincent");
    Chain_add_tail(opponent, Read_Card("OELSCHLAGER_Karl"));
    Chain_add_tail(opponent, Read_Card("PIVATY_Gabriel-Ange"));
    Chain_add_tail(opponent, Read_Card("PIVATY_Gabriel-Ange"));

    int len;
    int i;
    int tour=0; //pour compter le nombre de tour
    while (Chain_length(player) && Chain_length(opponent) && tour<=20){


        len =Chain_length(player);
        for (i=0 ; i<=len;++i){
            Chain * player1 = Chain_get(player, i);
            Print_stat(player1->carte);
        }
        printf("\n****************************************\n");
       len =Chain_length(opponent);
        for (i=0 ; i<=len;++i){
            Chain * player2 = Chain_get(opponent, i);
            Print_stat(player2->carte);
        }





        scanf("g\n");
        ++tour;
    }

}









#endif