#ifndef MAIN_C_BIBLIOTHEQUE_H
#define MAIN_C_BIBLIOTHEQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#define LINE_SIZE 1024

void print_bibliotheque() {

    DIR *dir = opendir("cards");

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char carte_actuelle[50] = "cards/";
        strcat(carte_actuelle,entry->d_name);

        FILE *carte = fopen(carte_actuelle, "r");
        if (carte == NULL) {
            perror("Erreur pour ouvrir la carte");
        }

        char *line = malloc(LINE_SIZE);

        initscr();
        scrollok(stdscr, TRUE); // Active le défilement de la fenêtre

        printw("->");


        while (fgets(line, LINE_SIZE, carte) != NULL) {

            printw("%s \n",line);
            refresh();

            int ch = wgetch(stdscr); // Récupérer les entrées
            if (ch == KEY_UP) {
                scroll(stdscr); // Défiler vers le haut
            } else if (ch == KEY_DOWN) {
                wscrl(stdscr, 1); // Défiler vers le bas
            }
        }


        free(line);
        fclose(carte);
    }


    closedir(dir);

    getch();
    endwin();

}




#endif //MAIN_C_BIBLIOTHEQUE_H
