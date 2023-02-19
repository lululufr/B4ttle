#ifndef DEF_HEADER_MONSTER
#define DEF_HEADER_MONSTER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "combat.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>




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
    while (fgetc(file) != '\n') {
        fseek(file, -1, SEEK_CUR);
        card->name = realloc(card->name, sizeof(char) * (strlen(card->name) + 1));
        card->name[i] = fgetc(file);
        i++;
    }
    i=0;
    char * buffer= malloc(sizeof (char ));
    buffer = malloc(sizeof (char ));
    while (fgetc(file) != '\n') {
        fseek(file, -1, SEEK_CUR);
        buffer = realloc(buffer, sizeof(char) * (strlen(buffer) + 1));
        buffer[i] = fgetc(file);
        i++;
        card->hp = atoi(buffer);
    }
    i=0;
    free(buffer);
    buffer = malloc(sizeof (char ));
    while (fgetc(file) != '\n') {
        fseek(file, -1, SEEK_CUR);
        buffer = realloc(buffer, sizeof(char) * (strlen(buffer) + 1));
        buffer[i] = fgetc(file);
        i++;
        card->atk = atoi(buffer);
    }
    i=0;
    free(buffer);
    card->desc= malloc(sizeof (char ));
    while (fgetc(file) != '\n') {
        fseek(file, -1, SEEK_CUR);
        card->desc = realloc(card->desc, sizeof(char) * (strlen(card->desc) + 1));
        card->desc[i] = fgetc(file);
        i++;
    }
    i=0;
    card->comp_desc= malloc(sizeof (char ));
    while (fgetc(file) != '\n') {
        fseek(file, -1, SEEK_CUR);
        card->comp_desc = realloc(card->comp_desc, sizeof(char) * (strlen(card->comp_desc) + 1));
        card->comp_desc[i] = fgetc(file);
        i++;
    }
    fclose(file);
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

void Read_player(char * filename, Chain * player) {
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





card * Random_Card(){
    int i;
    i = rand()%31;
    switch(i){
        case 0:
            Read_Card("ALIYOU_Reda");//
            break;
        case 1:
            Read_Card("ALOISI_Come");//
            break;
        case 2:
            Read_Card("AMBRY_Lukas");//
            break;
        case 3:
            Read_Card("AZARKANE_Issam");//
            break;
        case 4:
            Read_Card("BATHILY_Oussoumane");//
            break;
        case 5:
            Read_Card("BENZENINE_Yassine");//
            break;
        case 6:
            Read_Card("BOSSEBOEUF_Quentin");//
            break;
        case 7:
            Read_Card("BOUAYOUN_Ayman");//
            break;
        case 8:
            Read_Card("CARK_Dryss");//
            break;
        case 9:
            Read_Card("CHOUK_Steven");// problème d'image
            break;
        case 10:
            Read_Card("DAUTREMEPUICH_Hugo");//
            break;
        case 11:
            Read_Card("DIABIRA_Mamadou");//
            break;
        case 12:
            Read_Card("DUFRESNE_Jordan");//
            break;
        case 13:
            Read_Card("ELEFTERIOU_Alexis");//
            break;
        case 14:
            Read_Card("FERROUJ_Anass");//
            break;
        case 15:
            Read_Card("FRESSE_Balkis");//
            break;
        case 16:
            Read_Card("GAMBO-MAGAGI_Soumaya");//
            break;
        case 17:
            Read_Card("KAKOU_Marceau");//
            break;
        case 18:
            Read_Card("KEOMANY_Steven");//
            break;
        case 19:
            Read_Card("KIGER_Maxence");//
            break;
        case 20:
            Read_Card("KOBANOVIC_Anthony");//
            break;
        case 21:
            Read_Card("LANCELOT_Romain");//
            break;
        case 22:
            Read_Card("MEALARES_Julien");//
            break;
        case 23:
            Read_Card("MECHOUCHE_Vincent");//
            break;
        case 24:
            Read_Card("MILLER_Lucas");//
            break;
        case 25:
            Read_Card("MONTOUTE_Anthony-james");
            break;
        case 26:
            Read_Card("OELSCHLAGER_Karl");//
            break;
        case 27:
            Read_Card("PITORIN_Tom");//
            break;
        case 28:
            Read_Card("PIVATY_Gabriel-Ange");//
            break;
        case 29:
            Read_Card("SAGE_Julien");//
            break;
        case 30:
            Read_Card("YAHIA-ABDCHAFEE_Adam");//
            break;
    }
}




#endif