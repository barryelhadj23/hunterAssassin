#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"

#include "../core/Game.h"

void txtAff(WinTXT &win, Game &g)
{
	const Map &map = g.getConstMap();
	const Player & player = g.getConstPlayer();
	//const Gardes &gardes = jeu.getConstAllGarde();

	win.clear();

	// Affichage des murs et des portes
	for (int x = 0; x < map.getDimX(); ++x)
		for (int y = 0; y < map.getDimY(); ++y)
			win.print(x, y, map.getObjectChar(x, y));

	// Affichage de l'assassin
	win.print(player.getPosition().x, player.getPosition().y, 'A');

	win.draw();
}

void txtRun(Game &g)
{
	//Je creer une fenetre en mode texte
	WinTXT win(g.getConstMap().getDimX(), g.getConstMap().getDimY());

	bool run = true;
	int keyBoard;

	do
	{
		txtAff(win, g);

        #ifdef _WIN32
		Sleep(100);
        #else
		usleep(100000);
        #endif // WIN32

        keyBoard = win.getCh();
		switch (keyBoard)
		{
		case 'z': //UP
			g.toucheClavier('z');
			break;
		case 'q': //LEFT
			g.toucheClavier('q');
			break;
		case 's': //DOWN
			g.toucheClavier('s');
			break;
		case 'd': //RIGHT
			g.toucheClavier('d');
			break;
		case 'k': //arreter k comme kill , ahhh les signaux en LIFSE
            run = false;
			break;
		}

	} while (run);
}
