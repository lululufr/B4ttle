#ifndef MAIN_C_DISPLAY_H
#define MAIN_C_DISPLAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "maps/map.h"


char * readmap(char * filename /*,Map ** map*/) { ////faire en sorte que le filename soit clean sans PATH pour pouvoir le mettre dans map.nom
    char * first = malloc(sizeof (char)*12);
    first = "..\\maps\\";

    FILE *map_file = fopen(filename, "r");
    if (map_file == NULL) {
        printf("Erreur lors de l'ouverture du fichier contenant la map");
        //return 1;
    }

    char buffer[3];
    fscanf(map_file,"%s/n",buffer);
    int width = atoi(buffer);
    char *new_map = malloc(sizeof(char) * 2);
    int j = 0;
    fseek(map_file, 4, SEEK_SET);
    while (fgetc(map_file) != EOF) {

        fseek(map_file, -1, SEEK_CUR);
        new_map = realloc(new_map, sizeof(char) * (strlen(new_map) +1));
        new_map[j] = fgetc(map_file);
        j++;
    }

    //(*map)->map = new_map;
    //(*map)->width= width;
    //printf("%s",new_map);
    //printw("%s",new_map);

    return new_map;
}


void printmap(Map map,WINDOW * w){

    //int i,j;
    //while(map.map[j]!='\0'){
    //    for (i = 0; i <= map.width-1 ; ++i) {
    //        printw("%c",map.map[j]);
    //        ++j;
    //    }
    //    printw("\n");
    //    i=0;
    //}

    //char * test;
    //test = readmap("maps/city1");

    printw("%s",readmap("maps/city1"));

    getch();
    refresh();

    //Map * city1 = City1();
    //printw("%s",city1->map);



}

void play(WINDOW * w) {

    Map *newmap = malloc(sizeof(Map)*2);
    //readmap("maps/firstmap.txt"/*,&newmap*/);
    printmap(*newmap,w);
}

#endif