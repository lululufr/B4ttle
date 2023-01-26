#ifndef MAIN_C_DISPLAY_H
#define MAIN_C_DISPLAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

typedef struct Map{
    char * name;
    char * map;
    int width;
}Map;



void MapFile(Map * map, char * filename){

        FILE *map_file = fopen(filename, "r");
        if (map_file == NULL) {
            printf("Erreur lors de l'ouverture du fichier contenant la map");
        }

        int cpt=0;
        while(fgetc(map_file)!='\n'){
            ++cpt;
        }
        fseek(map_file,0,SEEK_SET);

        char *new_map = malloc(sizeof(char) * 2);
        int j = 0;

        while (fgetc(map_file) != EOF) {

            fseek(map_file, -1, SEEK_CUR);
            //if(fgetc(map_file)!='\n'){
                new_map = realloc(new_map, sizeof(char) * (strlen(new_map) + 1));
                new_map[j] = fgetc(map_file);
            //}
            j++;
        }
        (*map).name = filename;
        (*map).map = new_map ;
        (*map).width = cpt+1;
}




//void printmap(){
//
//    printw("%s",readmap("maps/city1"));
//
//    getch();
//
//    refresh();
//
//    endwin();
//
//}



#endif