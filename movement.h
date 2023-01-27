#ifndef B4TTLE_MOVEMENT_H
#define B4TTLE_MOVEMENT_H

void move() {

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
// Déplacer l'élément vers le haut
                        break;
                    case SDLK_DOWN:
// Déplacer l'élément vers le bas
                        break;
                    case SDLK_LEFT:
// Déplacer l'élément vers la gauche
                        break;
                    case SDLK_RIGHT:
// Déplacer l'élément vers la droite
                        break;
                }
                break;
        }
    }
}




#endif //B4TTLE_MOVEMENT_H
