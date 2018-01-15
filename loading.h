#ifndef LOADING_H
#define LOADING_H

#include "state.h"
#include <QWidget>
#include "factory.h"

class Loading : public State
{
	public:
		QVector<GameObject *> objects();
		static Loading* Instance();
		void keyPress(QKeyEvent*);
		void keyRelease(GameWidget *, QKeyEvent *, QTimer *);
	private:
		void anim(GameObject *, QRect, QString, int stop);
		BlockFactory *block_factory;
		int w, i;
		GameObject *p0,*p1,*p2,*p3,*p4,*p5,*p6;
		GameObject *bckg;
		GameObject *logo;
		int pauser;

		Loading();
		Loading(const Loading& root);
		Loading& operator=(const Loading&);
		static Loading* _instance;
};

#endif // LOADING_H
