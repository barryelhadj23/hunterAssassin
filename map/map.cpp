#include "map.h"

void map::drawMoquette(SDL_Renderer * renderer) {
    SDL_Surface* moquette_img = SDL_LoadBMP("../data/mapMoq.bmp");

    SDL_Texture * tex = SDL_CreateTextureFromSurface( renderer, moquette_img);
    SDL_Rect source = {0, 0, WINDOW_W,WINDOW_H};
    //SDL_Rect dest = {100, 100, PLAYER_WIDTH * 2, PLAYER_HEIGHT * 2};
    SDL_FreeSurface(moquette_img);
    SDL_RenderCopy( renderer,  tex, & source, NULL);
}

// on prend une image et on la place dans un rectangle destination qui est deja placee sur le rendu
void map::drawObstacle(SDL_Renderer * renderer, char * path, SDL_Rect destination) {
        SDL_Surface* obstacle = SDL_LoadBMP(path);
        SDL_Texture * tex = SDL_CreateTextureFromSurface( renderer,obstacle);
        SDL_FreeSurface(obstacle);
        SDL_RenderCopy( renderer,  tex,  NULL, & destination);
}

void map::makeMap(SDL_Renderer * renderer) {
    drawMoquette(renderer);
    for(int i=0; i<2;i++){
        drawObstacle(renderer,pathTab[i],recTab[i]);
    }

}
//un probleme de concatenation à resoudre
void map::initAllRectangle() {
    recTab[0].x =10;
    recTab[0].y =500;
    recTab[0].w = 100;
    recTab[0].h = 60;
    pathTab[0] = defaultDirectory+"block1.bmp";
    for(int i=1; i<2; i++){
        recTab[i].x = recTab[i-1].x + 50;
        recTab[i].y = recTab[i-1].y;
        recTab[i].w = 30;
        recTab[i].h = 40;
        pathTab[i] = defaultDirectory+"block"+(i+1)+".bmp";
    }
}