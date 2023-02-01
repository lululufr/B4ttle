#ifndef DEF_HEADER_MONSTER
#define DEF_HEADER_MONSTER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct card {
    char * name;
    int id;
    int hp;
    int atk;
    char desc[500];
    //inserer une compétence

    char * comp_desc ;
}card;




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
    }
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
    while (fgetc(file) != '\n') {
        fseek(file, -1, SEEK_CUR);
        buffer = realloc(buffer, sizeof(char) * (strlen(buffer) + 1));
        buffer[i] = fgetc(file);
        i++;
        card->id = atoi(buffer);
    }
   i=0;
    free(buffer);
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
    card->competence= malloc(sizeof (char ));
    while (fgetc(file) != '\n') {
        fseek(file, -1, SEEK_CUR);
        card->competence = realloc(card->competence, sizeof(char) * (strlen(card->competence) + 1));
        card->competence[i] = fgetc(file);
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

    return card;
}

void Print_Card(card * card){

    printf("%s --",card->name);
    printf("%d --",card->id);
    printf("%d --",card->hp);
    printf("%d --",card->atk);
    printf("%s --",card->desc);
    printf("%s --",card->competence);
    printf("%s --",card->comp_desc);

}

void Print_stat(card * card){
    printf("%s --",card->name);
    printf("%d --",card->hp);
    printf("%d --",card->atk);
}



#endif