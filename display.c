#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void read_map(char * mapname){
    char * first = malloc(sizeof (char)*50);
    first = "..\\maps\\";
    char * full = malloc(sizeof(char)*(strlen(mapname)+11));
    strcpy(full,first);
    strcat(full,mapname);
    fopen(full,"r");

    char** currentMap = malloc(sizeof (char *)*2);
    int i=0,j=0;
    while (){

    }



}