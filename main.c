#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "bibliotheque.h"
//#include "display.h"
//#define HAUTEUR2 13
//#define LARGEUR2 22

int main() {
    printf("slut");

    Map * newmap = malloc(sizeof (Map));
    printf("whre");
    readmap("maps/firstmap.txt",&newmap);
    //printmap(*newmap);


    for(;;) {
        launching(menu()); //la fonction qui lance nos menusmenu();
    }
    ////read_map( newMap,"firstmap.txt");
    ////print_map(*newMap);

}