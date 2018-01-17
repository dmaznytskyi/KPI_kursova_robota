#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#include "state.h"
#include "factory.h"
#include "gameobject.h"

class Scoreboard : public State
{
	public:
		QVector<GameObject *> objects();

		void draw();
		void clearList();
		void mouse(GameWidget*, QMouseEvent*);
		void keyPress(QKeyEvent*);
		void keyRelease(GameWidget*, QKeyEvent*, QTimer*);
		Scoreboard();
		~Scoreboard();
	private:
		TextFactory* text_factory;
		BlockFactory* block_factory;
		QList <GameObject*> table;
};

#endif // SCOREBOARD_H
