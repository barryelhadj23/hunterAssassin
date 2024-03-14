//
// Created by mamad on 14/03/2024.
//

#include "Map.h"
const char mapAssassin[15][20] = {
        "################",
        "#____|____|____#",
        "######||########",
        "######____#__##",
        "#__##_#_______#",
        "#____######___#",
        "#____|____#___#",
        "#____#____#___#",
        "#____#____|___#",
        "#____#######__#",
        "##_________#_|#",
        "#__#____####__#",
        "#____#____##__#",
        "#_________|___#",
        "#######||######"
};

Map::Map() {
    _dimX = 20;// nb colonne
    _dimY = 15; //nb ligne
    for(int i=0; i<_dimX; ++i)
        for(int j=0;j<_dimY;++j) {
            switch (mapAssassin[_dimY-1-j][i]) {
                case '#':
                    myMap[i][j] = WALL;
                    break;
                case '|':
                    myMap[i][j] = DOOR;
                    break;
                case '_':
                    myMap[i][j] = UNDERSCORE;
                    break;

            }

        }
}

void Map::openTheDoor(const int _x, const int _y) {
    assert(_x >= 0);
    assert(_y >= 0);
    assert(_x < _dimX);
    assert(_y < _dimY);
    myMap[_x][_y] = UNDERSCORE;
}

bool Map::freePixel(const int _x, const int _y) const {
    if((_x>=0 && _x<_dimX) && (_y>=0 && _y<_dimY) && (myMap[_x][_y] != '#'))
        return true;
    return false;
}