
#include "SDLGame.h"

//Je converti le temps en second
float SDLGame::temps(){return float(SDL_GetTicks()) / CLOCKS_PER_SEC;}


SDLGame::SDLGame(){
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unable to initialize SDL: %s", SDL_GetError());
        // Quitter le programme
        exit(EXIT_FAILURE);
    }

    // Création de la fenêtre
    window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_X, WINDOW_Y, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        // je Gére l'erreur si la création de la fenêtre a échoué
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unable to create window: %s", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    // Création du renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        // je Gére l'erreur si la création du renderer a échoué
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unable to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

//Une petite map;
// Remplissage du vecteur avec les obstacles du tableau
    vecAllObstacles.push_back({WINDOW_W/2 - 80, 50 , WINDOW_W/2 - 25, SQUARE_SIZE});
    vecAllObstacles.push_back({WINDOW_W/4, WINDOW_H/2 - 20, 25, WINDOW_W/2 - 25});
    vecAllObstacles.push_back({WINDOW_W/2 + 20, WINDOW_H/2 - 20, 25, WINDOW_W/2 - 25});
    vecAllObstacles.push_back({WINDOW_W/2 - 80, WINDOW_H - 70, WINDOW_W/2 - 25, SQUARE_SIZE});

    // Initialisation de tous les sprites
    //pour l'instant que le joueur
    // TODO On choisi le chemein depuis executable bin (donc on remonte une fois et on passe dans data)
    const char * path = "../data/mur.bmp";
    sp_player.loadSpriteFile(path, renderer);
}

SDLGame::~SDLGame() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDLGame::sdlDraw() {
    // Je Remplis l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

    const Player & m_player = game.getConstPlayer();
    sp_player.draw(renderer, game.playerRect.x,game.playerRect.y, PLAYER_WIDTH, PLAYER_HEIGHT);
    for (const Rect obstacle: vecAllObstacles) {
        sp_player.draw(renderer, obstacle.x,obstacle.y,obstacle.w,obstacle.h);
    }

}

void SDLGame::runProject() {
    SDL_Event event;
    AI myAI(&game.playerRect,&game.dest);
    bool isOpen = true;
    while (isOpen){
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                isOpen = false;
            else if (event.type == SDL_MOUSEBUTTONDOWN)
                if (event.button.button == SDL_BUTTON_LEFT) {
                    // Mettre à jour la position de destination avec les coordonnées du clic
                    game.dest.x = event.button.x;
                    game.dest.y = event.button.y;
                }

        }
        sdlDraw();

        if(!myAI.estArrivee())
            myAI.mov(vecAllObstacles);

        SDL_Delay(20);

        SDL_RenderPresent(renderer);
    }
}

