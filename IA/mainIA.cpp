#include "SDL.h"
#include "../src/Rect.h"
#include "../src/config_Variable.h"
#include "../src/Point.h"
#include "ArtificialIntelligence.h"
#include <iostream>
int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Erreur lors de l'initialisation de SDL : " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL Bouger Carré", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
    if (!window) {
        std::cerr << "Erreur lors de la création de la fenêtre : " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Erreur lors de la création du renderer : " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    Rect squareRect = {0, (WINDOW_H - SQUARE_SIZE) / 2, SQUARE_SIZE, SQUARE_SIZE};
    // Déclaration du vecteur d'obstacles
    std::vector<Rect> vecAllObstacles;

// Remplissage du vecteur avec les obstacles du tableau
    vecAllObstacles.push_back({WINDOW_W/2 - 80, 50 , WINDOW_W/2 - 25, SQUARE_SIZE});
    vecAllObstacles.push_back({WINDOW_W/4, WINDOW_H/2 - 20, 25, WINDOW_W/2 - 25});
    vecAllObstacles.push_back({WINDOW_W/2 + 20, WINDOW_H/2 - 20, 25, WINDOW_W/2 - 25});
    vecAllObstacles.push_back({WINDOW_W/2 - 80, WINDOW_H - 70, WINDOW_W/2 - 25, SQUARE_SIZE});

    //mmm

    vecAllObstacles.push_back({WINDOW_W/2 - 80, 80 , WINDOW_W/2, SQUARE_SIZE*2});
    vecAllObstacles.push_back({WINDOW_W/2, WINDOW_H/2 - 20, 30, WINDOW_W/2 - 45});
    vecAllObstacles.push_back({WINDOW_W/2 + 40, WINDOW_H/2 - 20, 25, WINDOW_W/2 - 35});
    Rect destRect = squareRect;

    AI ai(&squareRect, &destRect);

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_MOUSEBUTTONDOWN)
                if (event.button.button == SDL_BUTTON_LEFT) {
                    // Mettre à jour la position de destination avec les coordonnées du clic
                    destRect.x = event.button.x;
                    destRect.y = event.button.y;
                }
        }

        if (!ai.estArrivee()) {
            ai.mov(vecAllObstacles);
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &squareRect);
        for(const Rect& obstacle : vecAllObstacles) {
            SDL_SetRenderDrawColor(renderer, 217, 189, 100, 255);
            SDL_RenderFillRect(renderer, &obstacle);
        }
        SDL_RenderPresent(renderer);

        SDL_Delay(10);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}