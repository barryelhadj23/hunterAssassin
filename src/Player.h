//
// Created by mamad on 05/03/2024.
//

#ifndef HUNTERASSASSIN_PLAYER_H
#define HUNTERASSASSIN_PLAYER_H

#include <iostream>
#include "Rect.h"
#include <cassert>

class Player {
public:
    const char *spriteIMG;
    Rect source;
    Rect dest;
    bool moving_left, moving_right, moving_up, moving_down;
    int health; ///Nombre de vie du joueur
    Player();
    ~Player();
    void static testRegression();

};

#endif //HUNTERASSASSIN_PLAYER_H
