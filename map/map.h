#include <iostream>
#include <SDL.h>

#include "color.h"
#include "../src/config_Variable.h"
#include "time.h"
#include "math.h"
#include "stdlib.h"
#ifndef HUNTERASSASSIN_MAP_H
#define HUNTERASSASSIN_MAP_H


class map {
public:
    SDL_Rect recTab[2];
    char * pathTab[2];
    char * defaultDirectory = "../data/";
    void initAllRectangle();
    void drawObstacle(SDL_Renderer * renderer, char * path, SDL_Rect destination);
    void drawMoquette(SDL_Renderer * renderer);
    void makeMap(SDL_Renderer * renderer);
};


#endif //HUNTERASSASSIN_MAP_H
