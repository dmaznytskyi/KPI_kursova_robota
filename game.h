#ifndef GAME_H
#define GAME_H

#include "loading_state.h"
/*#include "main_menu_state.h";
#include "game_state.h";
#include "sb_state.h";
*/
class Game
{
	public:
		Game();
		void run();
	private:
		GameWidget mw;
};

#endif // GAME_H
