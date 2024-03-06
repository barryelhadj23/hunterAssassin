
#ifndef HUNTERASSASSIN_GAME_H
#define HUNTERASSASSIN_GAME_H

#include "Player.h"
#include "SDL.h"
#include "config_Variable.h"
class Game {
public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texPlayer;
    SDL_Rect source, dest;
    SDL_Event event;
    Player player;

    void InitGame();
    void Renderer();
    void runProject();
    void EventAction();
    void moveNow();
    ~Game();
};


#endif //HUNTERASSASSIN_GAME_H
