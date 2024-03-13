#ifndef HUNTERASSASSIN_SDLGAME_H
#define HUNTERASSASSIN_SDLGAME_H

#include "SDLSprite.h"
#include "../core/Game.h"
#include "SDL.h"
#include "../core/config.h"

/**
 * @brief La classe gérant le jeu avec un affichage SDL.
 */
class SDLGame {
private:
    Game game; /**< Instance de la classe Game. */
    SDL_Window * window; /**< Fenêtre SDL pour l'affichage. */
    SDL_Renderer * renderer; /**< Rendu SDL pour l'affichage. */
    std::vector<Rect> vecAllObstacles; /**< Vecteur contenant tous les obstacles du jeu. */
    SDLSprite sp_player; /**< Sprite SDL pour le joueur. */

public:

    /**
     * @brief Constructeur par défaut de la classe SDLGame.
     */
    SDLGame ();

    /**
     * @brief Destructeur de la classe SDLGame.
     */
    ~SDLGame ();

    /**
     * @brief Méthode principale pour exécuter le jeu.
     */
    void runProject();

    /**
     * @brief Méthode pour dessiner le jeu avec SDL.
     */
    void sdlDraw();

    /**
     * @brief Méthode pour obtenir le temps.
     * @return Le temps écoulé depuis le début du jeu.
     */
    float temps();
};

#endif //HUNTERASSASSIN_SDLGAME_H
