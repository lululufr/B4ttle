#ifndef DEF_HEADER_MONSTER
#define DEF_HEADER_MONSTER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct card {
    int id;
    char name[50];
    int hp;
    int atk;
    char desc[500];
    //inserer une compétence

    char * comp_desc ;
}card;



card declare( char * cardname){
    char * path = malloc(sizeof (char)*50);
    path = cardname;
    char * first = malloc(sizeof (char)*50);
    first = "..\\cards\\";
    char * full = malloc(sizeof(char)*(strlen(path)+11));
    strcpy(full,first);
    strcat(full,path);
    printf("%s", full);

    FILE *file = fopen(full, "r");
        if(file){
            //good
        } else{
            printf("erreur d'ouverture du fichier des cartes");
        }
    card card;
    fscanf(file,"%s | %d | %d | %s",card.name,&card.hp,&card.atk,card.desc);
//    fgets(card.desc,1,file);

    return card;
}
void printcard(card card){

    printf("\n%s\n%d\n%d\n%s",card.name,card.hp,card.atk,card.desc);


}




#endif