
#ifndef HUNTERASSASSIN_PLAYER_H
#define HUNTERASSASSIN_PLAYER_H

#include <iostream>
#include "Rect.h"
#include <cassert>
#include "Point.h"
class Player {
public:
    const char *spriteIMG;
    Rect source;
    Rect dest;
    bool moving_left, moving_right, moving_up, moving_down;
    int health; ///Nombre de vie du joueur
    //Nombre de sprite a utilise 7 car on revien a la position de depart (1,2,3,4,5,6,1)
    Position player_left_clips[7];
    Position player_right_clips[7];
    Position player_up_clips[7];
    Position player_down_clips[7];
    Player();
    ~Player();
    void static testRegression();

};

#endif //HUNTERASSASSIN_PLAYER_H