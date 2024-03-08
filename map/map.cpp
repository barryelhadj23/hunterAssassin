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
    for(int i=0; i<5;i++){
        drawObstacle(renderer,pathTab[i],recTab[i]);
    }
    /*drawObstacle(renderer,pathTab[0],recTab[0]);
    drawObstacle(renderer,pathTab[1],recTab[1]);
    drawObstacle(renderer,pathTab[2],recTab[2]);
    /*for(int i=0; i<3;i++){
        drawObstacle(renderer,pathTab[i],recTab[i]);
    }*/
}
//un probleme de concatenation à resoudre
void map::initAllRectangle() {
    //porte
    recTab[0].x = 166;
    recTab[0].y = 680;
    recTab[0].w = 55;
    recTab[0].h = 25;
    //mur gauche
    recTab[1].x = 0;
    recTab[1].y = 670;
    recTab[1].w = 165;
    recTab[1].h = 40;
    //mur droit
    recTab[2].x = 222;
    recTab[2].y = 670;
    recTab[2].w = 180;
    recTab[2].h = 40;

    pathTab[0] = "../data/porte.bmp";
    pathTab[1] = "../data/mur.bmp";
    pathTab[2] = "../data/mur.bmp";
    //pathTab[3] = "../data/block1.bmp";

    //texture bas
    recTab[3].x = 0;
    recTab[3].y = 330;
    recTab[3].w = 400;
    recTab[3].h = 175;

    recTab[4].x = 0;
    recTab[4].y = 490;
    recTab[4].w = 400;
    recTab[4].h = 180;

    /*pathTab[3]= "../data/textureBlanc.bmp";
    pathTab[4]= "../data/textureBlanc.bmp";*/
    for(int i=3; i<=4; i++){
        pathTab[i]= "../data/textureBlanc.bmp";
    }

    /*for(int i=1; i<2; i++){
        recTab[i].x = recTab[i-1].x + 50;
        recTab[i].y = recTab[i-1].y;
        recTab[i].w = 30;
        recTab[i].h = 40;
        //pathTab[i] = defaultDirectory+"block"+(i+1)+".bmp";
    }*/
}