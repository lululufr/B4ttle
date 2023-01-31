#ifndef B4TTLE_COMBAT_H
#define B4TTLE_COMBAT_H

#include "monster.h"
#include "combat_display.h"


//typedef struct card {
//    int id;
//    char name[50];
//    int hp;
//    int atk;
//    char desc[500];
//    //inserer une compétence
//
//    char * comp_desc ;
//}card;



//typedef struct Chain {
//    card carte;
//    struct Chain * next;
//} Chain;
//
//Chain Chain_empty(){
//    Chain empty;
//    return empty;
//}
//
//void Chain_Free(Chain * liste){
//    Chain * current = liste;
//    Chain * next;
//    while (current != NULL){
//        next = current->next;
//        free(current);
//        current = next;
//    }
//    liste = NULL;
//}
//
//int Chain_add_tail(Chain * chaine, card * carte){
//    Chain * current = chaine;
//    if (current == NULL){
//        current = (Chain *) malloc(sizeof(Chain));
//        (*current).carte = card ;
//        (*current).next = NULL;
//    } else {
//        while (current->next != NULL){
//            current = current->next;
//        }
//        current->next = (Chain *) malloc(sizeof(Chain));
//        current->next->value = value;
//        current->next->next = NULL;
//    }
//    return 0;
//}
//int Chain_delete(Chain * liste, int id, int * value){
//    Chain * current = liste;
//    Chain * previous = NULL;
//    int i = 0;
//    while (i < id && current != NULL){
//        previous = current;
//        current = current->next;
//        ++i;
//    }
//    if (current == NULL){
//        return -1;
//    }
//    if (value != NULL){
//        *value = current->value;
//    }
//    if (previous == NULL){
//        *liste = *current->next;
//    } else {
//        previous->next = current->next;
//    }
//    free(current);
//    return 0;
//}
//
//int Chain_insert(Chain * liste, int id, card carte){
//    Chain * current= liste;
//    Chain * newchain;
//    int i=0;
//    while (i!=id){
//        current = (*current)->next;
//        ++i;
//    }
//    newchain = (Chain *) malloc(sizeof (Chain));
//    (*newchain).carte=carte;
//    (*newchain).next = (*current)->next;
//    (*current)->next = newchain;
//    return 0;
//}
//
//



void attack(card * carte, int attack){
    if (carte->hp-=attack<=0){
        //
    }
}


void chose(chain chain){

}


int fight(){

    fight_print_sdl();


}









#endif //B4TTLE_COMBAT_H