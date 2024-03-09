#ifndef HUNTERASSASSIN_PLAYER_H
#define HUNTERASSASSIN_PLAYER_H

#include <iostream>
#include "Rect.h"
#include <cassert>
#include "Point.h"

/**
 * @class Player
 * @brief Classe représentant le joueur dans le jeu.
 */
class Player {
public:
    const char *spriteIMG; ///< Chemin vers l'image du sprite du joueur.
    Rect source; ///< Rectangle source pour la découpe du sprite.
    Rect dest; ///< Rectangle de destination pour l'affichage du joueur.
    bool moving_left, moving_right, moving_up, moving_down; ///< Indicateurs de direction du joueur.
    int health; ///< Nombre de vies du joueur.

    Position player_left_clips[7]; ///< Tableau des positions pour l'animation du joueur vers la gauche.
    Position player_right_clips[7]; ///< Tableau des positions pour l'animation du joueur vers la droite.
    Position player_up_clips[7]; ///< Tableau des positions pour l'animation du joueur vers le haut.
    Position player_down_clips[7]; ///< Tableau des positions pour l'animation du joueur vers le bas.

    /**
     * @brief Constructeur par défaut de la classe Player.
     */
    Player();

    /**
     * @brief Destructeur de la classe Player.
     */
    ~Player();

    /**
     * @brief Méthode de test pour la régression.
     */
    void static testRegression();
};

#endif //HUNTERASSASSIN_PLAYER_H
