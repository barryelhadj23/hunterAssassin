#ifndef HUNTERASSASSIN_GAME_H
#define HUNTERASSASSIN_GAME_H

#include "Player.h"
#include "Rect.h"
#include "IA.h"
#include "Map.h"

/**
 * @brief Classe représentant le jeu.
 *
 * Cette classe gère les opérations liées au jeu, telles que l'initialisation du joueur,
 * de la map et des gardes.
 */
class Game {
private:
    Player _player; /**< Instance du joueur. */
    Map _gameMap; /**< Instance de la map du jeu. */
public:
    Rect dest; /**< Destination de L'IA. */
    Rect playerRect = dest = { getConstPlayer().getPosition().x,
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
     * @brief Gère l'entrée du clavier.
     *
     * Cette fonction détermine l'action à entreprendre en fonction de la touche pressée.
     * Elle permet au joueur de se déplacer sur la carte et interagit avec les éléments du jeu.
     *
     * @param touche La touche pressée par le joueur.
     * @return true si le joueur a effectué une action, sinon false.
     */
    bool toucheClavier(const char touche);

    /**
     * @brief Obtient une référence constante vers l'objet Player.
     *
     * @return Une référence constante vers l'objet Player associé au jeu.
     */
    inline const Player &getConstPlayer() { return _player; }

    /**
     * @brief Obtient une référence constante vers l'objet Map.
     *
     * @return Une référence constante vers l'objet Map associé au jeu.
     */
    inline const Map &getConstMap() { return _gameMap; }
};

#endif //HUNTERASSASSIN_GAME_H
