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

//Je charge mes image source (pour en faire une animation video
void Game::loadClips() {

    for (int i = 0; i < 7; ++i) {
        player.player_left_clips[i].x = i * PLAYER_WIDTH;
        player.player_left_clips[i].y = PLAYER_HEIGHT;
        player.player_right_clips[i].x = i * PLAYER_WIDTH;
        player.player_right_clips[i].y = PLAYER_HEIGHT * 2;
        player.player_up_clips[i].x = i * PLAYER_WIDTH;
        player.player_up_clips[i].y = PLAYER_HEIGHT * 3;
        player.player_down_clips[i].x = i * PLAYER_WIDTH;
        player.player_down_clips[i].y = 0;
    }
}

void Game::runProject() {
    InitGame();
    loadClips();
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
    /*SDL_Event event;
    const Uint8* state = SDL_GetKeyboardState(NULL);

    player.moving_left = state[SDL_SCANCODE_LEFT] > 0;
    player.moving_right = state[SDL_SCANCODE_RIGHT] > 0;
    player.moving_up = state[SDL_SCANCODE_UP] > 0;
    player.moving_down = state[SDL_SCANCODE_DOWN] > 0;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            SDL_DestroyWindow(window);
            SDL_Quit();
            exit(0);
        }
    }*/
}

void Game::moveNow() {
    /*
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
    }*/

    int animation_speed = SDL_GetTicks() / 175;
    int idx = animation_speed % 4;
    float vitesse=2.4;

    if (player.moving_left) {
        player.source.x =  player.player_left_clips[idx].x;
        player.source.y =  player.player_left_clips[idx].y;
        player.dest.x -= vitesse;
    }
    if (player.moving_right) {
        player.source.x =  player.player_right_clips[idx].x;
        player.source.y =  player.player_right_clips[idx].y;
        player.dest.x += vitesse;
    }
    if (player.moving_up) {
        player.source.x = player.player_up_clips[idx].x;
        player.source.y = player.player_up_clips[idx].y;
        player.dest.y -= vitesse;
    }
    if (player.moving_down) {
        player.source.x = player.player_down_clips[idx].x;
        player.source.y = player.player_down_clips[idx].y;
        player.dest.y += vitesse;
    }
}

Game::~Game() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texPlayer);
    SDL_Quit();
}
