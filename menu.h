#ifndef MAIN_C_MENU_H
#define MAIN_C_MENU_H

#include<curses.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "bibliotheque.h"
//#include "display.h"

//Le menu
int menu();
void loading(){

};

void print_title(){


    char * title =
           "            ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
           "            ░░▒░░░░▒░░▒░░▒░░▒░░░▒░░░░░▒░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
           "            ░░▒░▒░▒▒░▒░▒░▒▒░▒░▒░▒▒▒░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
           "            ░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
           "            ░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
           "            ░░▒▒┌──┐┌┐▒┌┐┌┐▒┌┐┌┐▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
           "            ░░░▒│┌┐│││▒│├┘└┬┘└┤│▒▒▒▒▒░░░░░░░░░░┌───┬───┬───┬──┐░░░\n"
           "            ░░░▒│└┘└┤└─┘├┐┌┴┐┌┤│┌──┐▒░░░░░░░░░░│┌──┤┌─┐│┌─┐├┤├┘░░░\n"
           "            ░░░▒│┌─┐├──┐│││▒││││││─┤▒░░░░░░░░░░│└──┤└──┤│░└┘││░░░░\n"
           "            ░░░▒│└─┘│▒▒│││└┐│└┤└┤│─┤▒░░░░░░░░░░│┌──┴──┐││┌─┐││░░░░\n"
           "            ░░░▒└───┘▒▒└┘└─┘└─┴─┴──┘▒░░░░░░░░░░│└──┤└─┘│└┴─├┤├┐░░░\n"
           "            ░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░└───┴───┴───┴──┘░░░\n"
           "            ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n";


    printf("%s",title);
}


int load_bar()
{

    int progress = 0;

    while (progress < 100)
    {
        ++progress;

        printf("\r");
        printf("[");
        for (int i = 0; i < 100; i++){
            if (i < progress){
                printf("=");
            }
            else
            {
                printf(" ");
            }
        }
        printf("] %d%%", progress);

        // Fonction stylé qui clean le terminal
        fflush(stdout);

        usleep(60000);
    }

    printf("\n");

    return 0;
}

void launching(int i){


    switch (i){

        case 0 : // nouvelle partie
            //Map * currentMap=malloc(sizeof(Map)) ; //marche pas
            //readmap("maps/firstmap.txt", &currentMap); //marche pas
            //read_print_map("maps/firstmap.txt");
            break;

        case 1 : // Charger partie
            break;

        case 2 : //option
            break;

        case 3 : // Bibliotheque
            //endwin();
            //printf("\n \n");
            print_bibliotheque();
            break;

        case 4 : //quitter
            endwin();
            exit(EXIT_SUCCESS);
            break;

        default :
            endwin();
            printf("Une erreur est survenu lors du choix dans le menu");
            exit(EXIT_SUCCESS);
            break;
    }
}
//le menu

int menu() {

    WINDOW *w;
    char list[5][20] = {"Nouvelle Partie", "Charger Partie", "Option", "Bibliotheque", "Quitter"};
    char item[20];
    int ch, i = 0, width = 7;
    initscr(); // initialize Ncurses

//w = newwin( 10, 24, 1, 1 ); // create a new window
    w = newwin(0, 0, 0, 0); // create a new window

//box( w, 2, 2 ); // sets default borders for the window

// now print all the menu items and highlight the first one


    for (i = 0; i < 5; i++) {
        if (i == 0)
            wattron(w, A_STANDOUT); // highlights the first item.
        else
            wattroff(w, A_STANDOUT);
        sprintf(item, "%-13s", list[i]);
        mvwprintw(w, i + 1, 2, "%s", item);
    }
    wrefresh(w); // update the terminal screen
    i = 0;
    noecho(); // disable echoing of characters on the screen

    keypad(w, TRUE); // enable keyboard input for the window.

    curs_set(0); // Cache le curseur par defaut

// Prendre les entrés
    while (ch = wgetch(w)) {

// Permet de retirer la subbrillance
        sprintf(item, "%-19s", list[i]);
        mvwprintw(w, i + 1, 2, "%s", item);

// Permet de naviguer sur le menu en incrémentant i

            if (ch == KEY_UP) {
                i--;
                i = (i < 0) ? 4 : i;
            }
                if (ch == KEY_DOWN) {
                    i++;
                    i = (i > 4) ? 0 : i;
                }

        if (ch == '\n') {
            return i;
        }


// Met en subbrillance l'item selectionné
        wattron(w, A_STANDOUT);
        sprintf(item, "%-7s", list[i]);
        mvwprintw(w, i + 1, 2, "%s", item);
        wattroff(w, A_STANDOUT);
    }

    delwin(w);
    endwin();
    printf("\n Au revoir \n");

    return i;
}
#endif //MAIN_C_MENU_H
