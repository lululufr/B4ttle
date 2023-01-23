#ifndef MAIN_C_DISPLAY_H
#define MAIN_C_DISPLAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "maps/map.h"


char * readmap(char * filename /*,Map ** map*/) {

    FILE *map_file = fopen(filename, "r");
    if (map_file == NULL) {
        printf("Erreur lors de l'ouverture du fichier contenant la map");
        //return 1;
    }

    char *new_map = malloc(sizeof(char) * 2);
    int j = 0;

    while (fgetc(map_file) != EOF) {

        fseek(map_file, -1, SEEK_CUR);
        new_map = realloc(new_map, sizeof(char) * (strlen(new_map) +1));
        new_map[j] = fgetc(map_file);
        j++;
    }

    return new_map;
}


void printmap(){

    printw("%s",readmap("maps/city1"));

    getch();
   
    refresh();

    endwin();

}



#endif