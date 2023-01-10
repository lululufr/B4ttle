#ifndef MAIN_C_DISPLAY_H
#define MAIN_C_DISPLAY_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>


typedef struct Map{
    char * map_name;
    char ** map;
    int hauteur;
}Map ;




void read_map(Map * Map,char * mapname){


    char * first = malloc(sizeof (char)*50);
    first = "..\\maps\\";
    char * full = malloc(sizeof(char)*(strlen(mapname)+11));
    strcpy(full,first);
    strcat(full,mapname);
    FILE *file = fopen(full,"r");
    printf("test");
    //char** currentMap = malloc(sizeof (char *)*2);
    //currentMap[0]= malloc(sizeof (char)*2);
    //int i=0,j=0;
    //while ((buffer = fgetc(file)) != EOF){
    //    while((buffer = fgetc(file)) != '\0'){
    //        currentMap = realloc(currentMap,(2+j)*sizeof (char));
    //        currentMap[i][j]=buffer;
    //        ++j;
    //    }
    //    currentMap = realloc(currentMap,(2+i)*sizeof (char *));
    //    ++i;
    //    j=0;
    //}

    int hauteur, largeur;
    fscanf(file,"%d | %d", &hauteur, &largeur);

    printf("%d ----- %d",hauteur,largeur);
    /*char buffer;
    while((buffer =fgetc(file)!= '\0')){

    }

    char** currentMap = malloc(sizeof (char * )*hauteur);
    int i=0,j=0;
    for(i=0;i<=hauteur;++i){
        currentMap[i]=malloc(sizeof(char)*largeur);
    }

    while ((fgetc(file)) != EOF){
        while((fgetc(file)) != '\0'){
            ++j;
        }
        ++i;
        j=0;
    }
*/



    //(*Map).map_name= malloc(sizeof(char)*strlen(mapname)+1);
    //(*Map).hauteur=i;
    //(*Map).map= currentMap;
    //(*Map).map_name=mapname;
}


void print_map(Map Map){
    int i;
    for(i = 0; i < Map.hauteur; ++i) {
        mvprintw(i, 0, "%s", Map.map[i]);
    }
}



#endif

//char** currentMap = malloc(sizeof (char *)*2);
//int i=0,j=0;
//
//while ((buffer = fgetc(file)) != EOF){
//
//    while ((buffer = fgetc(file)) != '\0'){
//        linebuffer = realloc(linebuffer, (2 + j) * sizeof(char));
//        linebuffer[j] = buffer;
//    }
//    currentMap= realloc(currentmap, (i+2)*sizeof(char *));
//    currentMap[i]=linebuffer;
//}