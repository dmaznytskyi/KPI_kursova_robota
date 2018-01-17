#ifndef ABOUT_H
#define ABOUT_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#include "state.h"
#include "factory.h"
#include "gameobject.h"

class About : public State
{
	public:
		About();
		~About();
		QVector<GameObject *> objects();
		void keyPress(QKeyEvent*);
		void keyRelease(GameWidget*, QKeyEvent*, QTimer*);
		void mouse(GameWidget*, QMouseEvent*);
		void draw();
		void clearList();

	private:
		QVector <GameObject*> about;
};

#endif // ABOUT_H
