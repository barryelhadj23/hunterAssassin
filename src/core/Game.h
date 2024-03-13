#ifndef HUNTERASSASSIN_GAME_H
#define HUNTERASSASSIN_GAME_H

#include "Player.h"
#include "Rect.h"
#include "IA.h"

/**
 * @brief Classe représentant le jeu.
 *
 * Cette classe gère les opérations liées au jeu, telles que l'initialisation du joueur,
 * de la map et des gardes.
 */
class Game {
private:
    Player _player; /**< Instance du joueur. */
public:

    Rect dest; /**< Destination de L'IA. */
    Rect playerRect = dest= {getConstPlayer().getPosition().x,
                             getConstPlayer().getPosition().y,
                             PLAYER_WIDTH,
                             PLAYER_HEIGHT};


    /**
     * @brief Constructeur par défaut de la classe Game.
     */
    Game();

    /**
     * @brief Destructeur de la classe Game.
     */
    ~Game();

    /**
     * @brief Obtient une référence constante vers l'objet Player.
     *
     * @return Une référence constante vers l'objet Player associé au jeu.
     */
     //TODO vous pouvez tout simplement ignorer le inline (c'est fais pour moi)
     /**
      *
      * @brief inline permet de generer getPlayer que lors de son appel ,
      * le compilateur l'ignore donc par defaut (c'est une suggestion)
      */
    inline const Player &getConstPlayer() { return _player; }
};

#endif //HUNTERASSASSIN_GAME_H
