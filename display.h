#ifndef MAIN_C_DISPLAY_H
#define MAIN_C_DISPLAY_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>



#define ROWS 26
#define COLS 22


typedef struct Map{
    char * map;
    char * nom;
}Map;



int readmap(char * filename, Map ** map) { ////faire en sorte que le filename soit clean sans PATH pour pouvoir le mettre dans map.nom
    char * first = malloc(sizeof (char)*12);
    first = "..\\maps\\";

    FILE *map_file = fopen(filename, "r");
    if (map_file == NULL) {
        printf("Erreur lors de l'ouverture du fichier contenant la map");
        return 1;
    }

    char *new_map = malloc(sizeof(char) * 2);
    int i = 0, j = 0, width = 0;
    while (fgetc(map_file) != EOF) {

        fseek(map_file, -1, SEEK_CUR);
        new_map = realloc(new_map, sizeof(char) * (strlen(new_map) + 1));
        new_map[i * width + j] = fgetc(map_file);
        if (i == 0)
            width = j;
        j++;
        i++;
    }

    (*map)->map = new_map;
    //(*map)->nom = "Map de TEST";
}




void printmap(Map map){

    //printw("%s",map.map);


    //getch();
    //endwin();
    //printf("%s",map.map);
    printf("%s",map.map);


}

void play() {


    Map *newmap = malloc(sizeof(Map));
    readmap("maps/firstmap.txt", &newmap);
    printmap(*newmap);
}

#endif