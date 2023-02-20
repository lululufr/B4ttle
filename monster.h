#ifndef DEF_HEADER_MONSTER
#define DEF_HEADER_MONSTER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "combat.h"
#include "struct.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "competence.h"
//#include <dlfcn.h> //j'ai essayé plein de trucs mais j'ai pas réussi à les faire marcher.
//#include <windows.h> //j'ai essayé de faire des choses avec le .so mais pareil, j'ai pas réussi


card * Read_Card( char * cardname){

    char * path = malloc(sizeof (char)*50);
    path = cardname;
    char * first = malloc(sizeof (char)*50);
    first = "cards/";
    char * full = malloc(sizeof(char)*(strlen(path)+11*sizeof (char)));
    strcpy(full,first);
    strcat(full,path);

    FILE *file = fopen(full, "r");
    if(file){
        //good
    } else{
        printf("erreur d'ouverture du fichier des cartes");
        exit(EXIT_FAILURE);
    }

    //free(path);
    //free(first);
    free(full);

    card * card= malloc(sizeof (card)*8);
    card->name= malloc(sizeof (char ));
    int i =0;
    while (fgetc(file) != '\n') {//lecture du nom
        fseek(file, -1, SEEK_CUR);
        card->name = realloc(card->name, sizeof(char) * (strlen(card->name) + 1));
        card->name[i] = fgetc(file);
        i++;
    }
    i=0;
    char * buffer= malloc(sizeof (char ));
    buffer = malloc(sizeof (char ));
    while (fgetc(file) != '\n') {//lecture des pv
        fseek(file, -1, SEEK_CUR);
        buffer = realloc(buffer, sizeof(char) * (strlen(buffer) + 1));
        buffer[i] = fgetc(file);
        i++;
        card->hp = atoi(buffer);
    }
    i=0;
    free(buffer);
    buffer = malloc(sizeof (char ));
    while (fgetc(file) != '\n') {//lecture de l'attaque
        fseek(file, -1, SEEK_CUR);
        buffer = realloc(buffer, sizeof(char) * (strlen(buffer) + 1));
        buffer[i] = fgetc(file);
        i++;
        card->atk = atoi(buffer);
    }
    i=0;
    free(buffer);
    card->desc= malloc(sizeof (char ));
    while (fgetc(file) != '\n') {//lecture de la description du personnage
        fseek(file, -1, SEEK_CUR);
        card->desc = realloc(card->desc, sizeof(char) * (strlen(card->desc) + 1));
        card->desc[i] = fgetc(file);
        i++;
    }
    i=0;
    card->comp_desc= malloc(sizeof (char ));
    while (fgetc(file) != '\n') {//lecture de la description de la compétence
        fseek(file, -1, SEEK_CUR);
        card->comp_desc = realloc(card->comp_desc, sizeof(char) * (strlen(card->comp_desc) + 1));
        card->comp_desc[i] = fgetc(file);
        i++;
    }
    fclose(file);
//non fonctionnel, permettrait de trouver la fonction associée à la carte qui est lue actuellement

    //Fonction * fonctions= malloc(sizeof (Fonction));
    //Create_func_struct(fonctions);
    //for(i=0;i<fonctions->number;++i){
    //    if(!strcmp(card->name,fonctions[i].name[i])){
    //        card->competence=fonctions->competence[i];
    //    }
    //}
    //free(fonctions);


//#pragma comment(lib,card.name); comment ça marche ???? (pour lire des librairies)

    return card;
}

void Print_Card(card * card){

    printf("%s --",card->name);
    printf("%d --",card->id);
    printf("%d --",card->hp);
    printf("%d --",card->atk);
    printf("%s --",card->desc);
    //printf("%s --",card->competence);
    printf("%s --",card->comp_desc);

}

void Print_stat(card * card){
    printf("%s --",card->name);
    printf("%d --",card->hp);
    printf("%d --",card->atk);
}

void Read_player(char * filename, Chain * player) {// permet la lecture du deck du joueur, non fonctionnel
    char * first = malloc(sizeof (char)*50);
    first = "./deck/";
    char * full = malloc(((strlen(filename)+10)*sizeof (char)));
    strcpy(full,first);
    strcat(full,filename);
    printf("%s", full); //1

    FILE * file = fopen(full,"r");
    if(file) {
        int i = 0;
        char * name = malloc(sizeof(char));
        while (fgetc(file) != '\n') {
            fseek(file, -1, SEEK_CUR);
            name = realloc(name, sizeof(char) * (i + 1));
            name[i] = fgetc(file);
            i++;
        }
        name[i] = '\0';
        printf("%s", name);
        Chain_add_tail(player, Read_Card(name));
        free(name);
        fclose(file);
    } else {
        printf("erreur d'ouverture du fichier du deck");
        exit(EXIT_FAILURE);
    }
}





card * Random_Card(){//renvoit une carte aléatoire pour l'opponent
    int i;
    i = rand()%30;
    switch(i){
        case 0:
            printf("%d",i);
            Read_Card("ALIYOU_Reda");
            break;
        case 1:
            printf("%d",i);
            Read_Card("ALOISI_Come");
            break;
        case 2:
            printf("%d",i);
            Read_Card("AMBRY_Lukas");
            break;
        case 3:
            printf("%d",i);
            Read_Card("AZARKANE_Issam");
            break;
        case 4:
            printf("%d",i);
            Read_Card("BATHILY_Oussoumane");
            break;
        case 5:
            printf("%d",i);
            Read_Card("BENZENINE_Yassine");
            break;
        case 6:
            printf("%d",i);
            Read_Card("BOSSEBOEUF_Quentin");
            break;
        case 7:
            printf("%d",i);
            Read_Card("BOUAYOUN_Ayman");
            break;
        case 8:
            printf("%d",i);
            Read_Card("CARK_Dryss");
            break;
        case 9:
            printf("%d",i);
            Read_Card("CHOUK_Steven");
            break;
        case 10:
            printf("%d",i);
            Read_Card("DAUTREMEPUICH_Hugo");
            break;
        case 11:
            printf("%d",i);
            Read_Card("DIABIRA_Mamadou");
            break;
        case 12:
            printf("%d",i);
            Read_Card("DUFRESNE_Jordan");
            break;
        case 13:
            printf("%d",i);
            Read_Card("ELEFTERIOU_Alexis");
            break;
        case 14:
            printf("%d",i);
            Read_Card("FERROUJ_Anass");
            break;
        case 15:
            printf("%d",i);
            Read_Card("FRESSE_Balkis");
            break;
        case 16:
            printf("%d",i);
            Read_Card("GAMBO-MAGAGI_Soumaya");
            break;
        case 17:
            printf("%d",i);
            Read_Card("KAKOU_Marceau");
            break;
        case 18:
            printf("%d",i);
            Read_Card("KEOMANY_Steven");
            break;
        case 19:
            printf("%d",i);
            Read_Card("KIGER_Maxence");
            break;
        case 20:
            printf("%d",i);
            Read_Card("KOBANOVIC_Anthony");//
            break;
        case 21:
            printf("%d",i);
            Read_Card("LANCELOT_Romain");
            break;
        case 22:
            printf("%d",i);
            Read_Card("MEALARES_Julien");
            break;
        case 23:
            printf("%d",i);
            Read_Card("MECHOUCHE_Vincent");
            break;
        case 24:
            printf("%d",i);
            Read_Card("MILLER_Lucas");
            break;
        case 25:
            printf("%d",i);
            Read_Card("MONTOUTE_Anthony-james");
            break;
        case 26:
            printf("%d",i);
            Read_Card("OELSCHLAGER_Karl");
            break;
        case 27:
            printf("%d",i);
            Read_Card("PITORIN_Tom");
            break;
        case 28:
            printf("%d",i);
            Read_Card("PIVATY_Gabriel-Ange");
            break;
        case 29:
            printf("%d",i);
            Read_Card("SAGE_Julien");
            break;
        case 30:
            printf("%d",i);
            Read_Card("YAHIA-ABDCHAFEE_Adam");
            break;
        default:
            printf("%d",i);
            Read_Card("ELEFTERIOU_Alexis");
            break;
    }
}




#endif