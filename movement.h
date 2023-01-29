#ifndef B4TTLE_MOVEMENT_H
#define B4TTLE_MOVEMENT_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
int isValid(int move, Map * map){
    if(map->map[move]!=' '){/*peut importe ce qu'il y a ici, c'est juste un exemple je connais pas tous les caractères valides*/
        return 0;          /*on peut mettre des OR dans le if*/
    }else{
        return 1;
    }
}

void movement(int * pos, Map * map) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
// Déplacer l'élément vers le haut
                        if(isValid(*pos-map->width, map))
                            *pos-=map->width;
                        break;
                    case SDLK_DOWN:
// Déplacer l'élément vers le bas
                        if(isValid(*pos+map->width, map))
                            *pos+=map->width;
                        break;
                    case SDLK_LEFT:
// Déplacer l'élément vers la gauche
                        if(isValid(*pos-1, map))
                            *pos-=1;                        
                        break;
                    case SDLK_RIGHT:
// Déplacer l'élément vers la droite
                        if(isValid(*pos+1, map))
                            *pos+=1;
                        break;
                }
                break;
        }
    }

}




#endif //B4TTLE_MOVEMENT_H
