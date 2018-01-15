#ifndef STATE_H
#define STATE_H

#include <QObject>
#include <QPainter>
#include "gamewidget.h"
#include "gameobject.h"

class Object
{
	public:
		QRect size;
		QPixmap pixmap;

		Object(QRect rect, QString load)
		{
			size = rect;
			pixmap.load(load);
		}
};

class State
{
	public:
		virtual void clearList();
		virtual void draw(QPainter *);
		virtual QVector <GameObject*> objects();

		virtual void keyPress(QKeyEvent *) = 0;
		virtual void keyRelease(GameWidget *, QKeyEvent *, QTimer *) = 0;
};

#endif // STATE_H
