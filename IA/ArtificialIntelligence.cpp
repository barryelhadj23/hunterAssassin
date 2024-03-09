
#include "ArtificialIntelligence.h"
#include "ArtificialIntelligence.h"

AI::AI(SDL_Rect* squareRect, SDL_Rect* destRect) : squareRect(squareRect), destRect(destRect) {}

bool AI::estArrivee() {
    return (squareRect->x == destRect->x && squareRect->y == destRect->y);
}

//Simple IA
void AI::mov() {
    // Si le carré a atteint la position y de la destination,
    // alors je déplace sur l'axe x
        if (squareRect->y < destRect->y) {
            squareRect->y++;
        } else if (squareRect->y > destRect->y) {
            squareRect->y--;
        }

        if(squareRect->y == destRect->y) {
            // Déplacement sur l'axe x
            if (squareRect->x < destRect->x) {
                squareRect->x++;
            } else if (squareRect->x > destRect->x) {
                squareRect->x--;
        }
    }
}

