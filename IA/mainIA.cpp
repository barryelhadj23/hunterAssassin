#include "SDL.h"
#include "../src/config_Variable.h"
#include "../src/Point.h"
#include "ArtificialIntelligence.h"
#include <iostream>
int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Erreur lors de l'initialisation de SDL : " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL Bouger Carré", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
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

    SDL_Rect squareRect = {0, (WINDOW_H - SQUARE_SIZE) / 2, SQUARE_SIZE, SQUARE_SIZE};
    SDL_Rect destRect = {WINDOW_W/2 , (WINDOW_H - SQUARE_SIZE), SQUARE_SIZE, SQUARE_SIZE};

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
            ai.mov();
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &squareRect);

        SDL_RenderPresent(renderer);

        SDL_Delay(10);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}