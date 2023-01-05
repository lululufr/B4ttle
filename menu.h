#ifndef MAIN_C_MENU_H
#define MAIN_C_MENU_H

//Le menu

void launching(int i){


    switch (i){

        case 0 : // nouvelle partie
            break;

        case 1 : // Charger partie
            break;

        case 2 : //option
            break;

        case 3 : // Bibliotheque
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


#endif //MAIN_C_MENU_H
