
#ifndef HUNTERASSASSIN_ARTIFICIALINTELLIGENCE_H
#define HUNTERASSASSIN_ARTIFICIALINTELLIGENCE_H
#include "SDL.h"
#include <iostream>
#include "../src/config_Variable.h"

const int SQUARE_SIZE = 20;
class AI {
public:
    AI(SDL_Rect* squareRect, SDL_Rect* destRect);
    bool estArrivee();
    void mov(SDL_Rect obstacleRect);
    bool collision(const SDL_Rect& rect2);
    void contourObstacle(SDL_Rect obstacleRect);
    void moveAgain(int distanceX, int distanceY);
private:
    SDL_Rect* squareRect;
    SDL_Rect* destRect;
};



#endif //HUNTERASSASSIN_ARTIFICIALINTELLIGENCE_H
