#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "bibliotheque.h"
#include "display.h"
//#define HAUTEUR2 13
//#define LARGEUR2 22

//#define w WINDOW * ;

//


int main() {

    WINDOW * w;

    //print_title();
    ////load_bar();
    for(;;) {
        launching(menu(w),w); //la fonction qui lance nos menusmenu();
    }



    //off
    //read_map( newMap,"firstmap.txt");
    //print_map(*newMap);
    //play();

}