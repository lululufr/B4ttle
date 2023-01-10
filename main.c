#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "bibliotheque.h"
#include "display.h"
#define HAUTEUR2 13
#define LARGEUR2 22

int main() {

    print_title();
    load_bar();
    launching(menu()); //la fonction qui lance nos menusmenu();


    ////read_map( newMap,"firstmap.txt");
    ////print_map(*newMap);

}