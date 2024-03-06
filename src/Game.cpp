#include "Game.h"

void Game::InitGame() {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_X, WINDOW_Y, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(  window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

    SDL_Surface* player_img = SDL_LoadBMP(player.spriteIMG);

    texPlayer = SDL_CreateTextureFromSurface(renderer, player_img);
    source={player.source.x, player.source.y, player.source.w, player.source.h};
    dest={player.dest.x, player.dest.y, player.dest.w, player.dest.h};
    SDL_FreeSurface(player_img);
}

void Game::runProject() {
    InitGame();
    while (true) {
        EventAction();
        moveNow();
        Renderer();
    }
}

void Game::Renderer() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,texPlayer,&source,&dest);
    SDL_RenderPresent(renderer);
}

void Game::EventAction() {
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                SDL_DestroyWindow( window);
                SDL_Quit();
                exit(0);
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                         player.moving_left = true;
                        break;
                    case SDLK_RIGHT:
                        player.moving_right = true;
                        break;
                    case SDLK_UP:
                        player.moving_up = true;
                        break;
                    case SDLK_DOWN:
                        player.moving_down = true;
                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        player.moving_left = false;
                        break;
                    case SDLK_RIGHT:
                        player.moving_right = false;
                        break;
                    case SDLK_UP:
                        player.moving_up = false;
                        break;
                    case SDLK_DOWN:
                        player.moving_down = false;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
}

void Game::moveNow() {
    if (player.moving_left) {
         source.x = 0;
         source.y = PLAYER_HEIGHT;
         dest.x -= 10;
    }

    if (player.moving_right) {
         source.x = 0;
         source.y = PLAYER_HEIGHT * 2;
         dest.x += 10;
    }

    if (player.moving_up) {
         source.x = 0;
         source.y = PLAYER_HEIGHT * 3;
         dest.y -= 10;
    }

    if (player.moving_down) {
         source.x = 0;
         source.y = 0;
         dest.y += 10;
    }
}

Game::~Game() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
