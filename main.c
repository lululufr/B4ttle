#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "bibliotheque.h"
#include "display.h"
//#define HAUTEUR2 13
//#define LARGEUR2 22

int main() {
    Map * newmap = malloc(sizeof (Map));
    readmap("maps/firstmap.txt",&newmap);
    printmap(*newmap);



    //print_title();
    //load_bar();
    //for(;;) {
    //    launching(menu()); //la fonction qui lance nos menusmenu();
    //}
    ////read_map( newMap,"firstmap.txt");
    ////print_map(*newMap);

}