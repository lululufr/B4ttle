#include<curses.h>
#include <stdlib.h>
#include "menu.h"


int main() {


    WINDOW *w;
    char list[5][20] = { "Nouvelle Partie", "Charger Partie", "Option", "Bibliotheque", "Quitter" };
    char item[20];
    int ch, i = 0, width = 7;
    initscr(); // initialize Ncurses

    //w = newwin( 10, 24, 1, 1 ); // create a new window
    w = newwin( 0, 0, 0, 0 ); // create a new window

    //box( w, 2, 2 ); // sets default borders for the window

// now print all the menu items and highlight the first one


    for( i=0; i<5; i++ ) {
        if( i == 0 )
            wattron( w, A_STANDOUT ); // highlights the first item.
        else
            wattroff( w, A_STANDOUT );
        sprintf(item, "%-13s",  list[i]);
        mvwprintw( w, i+1, 2, "%s", item );
    }
    wrefresh( w ); // update the terminal screen
    i = 0;
    noecho(); // disable echoing of characters on the screen

    keypad( w, TRUE ); // enable keyboard input for the window.

    curs_set( 0 ); // Cache le curseur par defaut

// Prendre les entrés
    while( ch = wgetch(w)){

// Permet de retirer la subbrillance
        sprintf(item, "%-19s",  list[i]);
        mvwprintw( w, i+1, 2, "%s", item );

// Permet de naviguer sur le menu en incrémentant i
        switch( ch ) {
            case KEY_UP:
                i--;
                i = ( i<0 ) ? 4 : i;
                break;
            case KEY_DOWN:
                i++;
                i = ( i>4 ) ? 0 : i;
                break;
        }
        if (ch == '\n'){
            launching(i);
        }


// Met en subbrillance l'item selectionné
        wattron( w, A_STANDOUT );
        sprintf(item, "%-7s",  list[i]);
        mvwprintw( w, i+1, 2, "%s", item);
        wattroff( w, A_STANDOUT );
    }

    delwin( w );
    endwin();
}