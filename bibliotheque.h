#ifndef MAIN_C_BIBLIOTHEQUE_H
#define MAIN_C_BIBLIOTHEQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#define LINE_SIZE 1024

void print_bibliotheque() {

    DIR *dir = opendir("cards");

    // Ouverture du dossier

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char carte_actuelle[50] = "cards/";
        strcat(carte_actuelle,entry->d_name);

        FILE *carte = fopen(carte_actuelle, "r");
        if (carte == NULL) {
            perror("Erreur pour ouvrir la carte");
        }

        char *line = malloc(LINE_SIZE);

        printf("->");

        //wprintw(w, "->");

        while (fgets(line, LINE_SIZE, carte) != NULL) {

            //wprintw(w, "%s", line);
            printf("%s",line);

        }

        free(line);
        fclose(carte);

        //printf("\n");
        //wrefresh(w);
    }
    closedir(dir);

}




#endif //MAIN_C_BIBLIOTHEQUE_H
