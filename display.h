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
    int width;
}Map;

//int read_print_map(char * nameofthefile) {
//    int i = 0;
//    int j = 0;
//
//    char buffer[COLS];
//    FILE *map_file = fopen(nameofthefile, "r");
//    if (map_file == NULL) {
//        printf("Erreur lors de l'ouverture du fichier contenant la carte");
//        return 1;
//    }
//
//
//    char **map = (char **)malloc(ROWS * sizeof(char *));
//    for(; i < ROWS; i++) {
//        map[i] = (char *)malloc(COLS * sizeof(char));
//    }
//
//    for(i = 0; i < ROWS; i++) {
//        if (fgets(buffer, COLS, map_file) != NULL){
//            for(j = 0; j < COLS; j++) {
//                map[i][j] = buffer[j];
//            }
//        }
//    }
//
//
//    initscr();
//    noecho();
//
//    // affichage de la CARTEEEEEEE WESHHHH
//    for(i = 0; i < ROWS; i++) {
//        refresh();
//        printf("%s", map[i]);
//    }
//
//
//    getch();
//
//    // Clean up de fin :D
//    endwin();
//    fclose(map_file);
//    for(i = 0; i < ROWS; i++) {
//        free(map[i]);
//    }
//    free(map);
//    return 0;
//}




int readmap(char * filename, Map ** map){
    FILE *map_file = fopen(filename, "r");
    if (map_file == NULL) {
        printf("Erreur lors de l'ouverture du fichier contenant la map");
        return 1;
    }
//    while (fgetc(map_file)!=EOF){
//        fseek(map_file,-1, SEEK_CUR);
//        printf("%c", fgetc(map_file));
//    }


    char *new_map = malloc(sizeof(char) * 2);
    int i = 0, j = 0, width = 0;
    while (fgetc(map_file) != EOF) {

        fseek(map_file, -1, SEEK_CUR);
        new_map = realloc(new_map, sizeof(char) * (strlen(new_map) + 1));
        new_map[i * width + j] = fgetc(map_file);
        //printf("%c",new_map[i * width + j] );
        if (i == 0)
            width = j;
        //j = 0;
        j++;
        i++;
    }

    printf("\n\n\n%d", width);
    (*map)->map = new_map;
    (*map)->width = width;
}




void printmap(Map map){

 //   int i=0,j=0;
 //   while (map.map[i*map.width+j]!='\0'){
 //       for (j = 0; j <= map.width; ++j) {
 //           printf("%c", map.map[i*map.width+j]);
 //       }
 //       printf("\n");
 //       ++i;
 //   }

 printf("%s",map.map);

}

#endif