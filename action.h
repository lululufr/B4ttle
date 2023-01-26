#ifndef MAIN_C_ACTION_H
#define MAIN_C_ACTION_H

#include <curses.h>


int is_valid(int x, int y, int hauteur, int largeur, char grid[hauteur][largeur]) {
    if(grid[y][x]=='#'||y>hauteur||x>largeur||x<0||y<0){
        return 0;
    }
    return 1;
}
//v�rifie si le labyrnthe est fini en fonction de la position de l'user
int is_finish(int x, int y, int hauteur, int largeur, char grid[hauteur][largeur]) {
    if (grid[y][x]=='.'){
        return 1;
    }
    return 0;
}




/*void movement(int hauteur, int largeur ,char labyrinth[hauteur][largeur]) {

    int x = 1, y = 0;
    int move_x, move_y;
    int i;
    initscr();
    noecho();
    cbreak();
    do {
        clear();
        for(i = 0; i < hauteur; ++i) {
            mvprintw(i, 0, "%s", labyrinth[i]);
        }
        mvprintw(y, x, "@");
        mvprintw(y, x, "");
        refresh();
        move_x = x; move_y = y;
        switch(getch()) {
            case 'z': move_y = y - 1; break;
            case 's': move_y = y + 1; break;
            case 'q': move_x = x - 1; break;
            case 'd': move_x = x + 1; break;
            case 'l': refresh();
                clrtoeol();
                refresh();
                endwin();
                break;
        }
        if(is_valid(move_x, move_y, hauteur, largeur, labyrinth)) {
            x = move_x; y = move_y;
        }
    } while(! is_finish(x, y, hauteur, largeur, labyrinth));
    refresh();
    clrtoeol();
    refresh();
    endwin();
    // freegrid(labyrinth, hauteur);
}
*/

void move_character(char **map, int *x, int *y) {
    int ch = getch();
    switch(ch) {
        case KEY_UP:
            if (*x > 0) {
                map[*x][*y] = ' ';
                (*x)--;
                map[*x][*y] = '@';
            }
            break;
        case KEY_DOWN:
            if (*x < ROWS - 1) { // il faut trouver un moyen de transmettre les constantes et tout
                map[*x][*y] = ' ';
                (*x)++;
                map[*x][*y] = '@';
            }
            break;
        case KEY_LEFT:
            if (*y > 0) {
                map[*x][*y] = ' ';
                (*y)--;
                map[*x][*y] = '@';
            }
            break;
        case KEY_RIGHT:
            if (*y < COLS - 1) {
                map[*x][*y] = ' ';
                (*y)++;
                map[*x][*y] = '@';
            }
            break;
    }
}

#endif
