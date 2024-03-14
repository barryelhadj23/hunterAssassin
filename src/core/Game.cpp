//
// Created by mamad on 13/03/2024.
//

#include "Game.h"

Game::Game(): _player() {

}

Game::~Game() {}

bool Game::toucheClavier(const char touche)
{
    switch (touche)
    {
        case 'z':
            _player.goUp(_gameMap);
            break;
        case 'q':
            _player.goLeft(_gameMap);
            break;
        case 's':
            _player.goDown(_gameMap);
            break;
        case 'd':
            _player.goRight(_gameMap);
            break;
    }

    if (_gameMap.getObject(_player.getPosition().x, _player.getPosition().y) == '|')
    {
        _gameMap.openTheDoor(_player.getPosition().x, _player.getPosition().y);
        return true;
    }
    return false;
}