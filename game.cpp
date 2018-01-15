#include "game.h"
#include "loading.h"
#include "menu.h"
//#include "tetris.h"
//#include "scoreboard.h"

Game::Game()
{
	game = new GameWidget;
	current = Loading::Instance();
}

Game& Game::Instance()
{
	static Game theSingleInstance;
	return theSingleInstance;
}

State *Game::getState(Game *)
{
	return current;
}

void Game::run()
{
	game->show();
}

void Game::draw(QPainter *painter)
{
	current->draw(painter);
}
