
#ifndef HUNTERASSASSIN_ARTIFICIALINTELLIGENCE_H
#define HUNTERASSASSIN_ARTIFICIALINTELLIGENCE_H
#include "SDL.h"
#include <iostream>

const int SQUARE_SIZE = 20;
class AI {
public:
    AI(SDL_Rect* squareRect, SDL_Rect* destRect);
    bool estArrivee();
    void mov();

private:
    SDL_Rect* squareRect;
    SDL_Rect* destRect;
};



#endif //HUNTERASSASSIN_ARTIFICIALINTELLIGENCE_H
