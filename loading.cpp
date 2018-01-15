#include <QMessageBox>
#include <QPainter>
#include <QWidget>
#include <QDebug>
#include "loading.h"
#include "game.h"
#include "menu.h"

Loading* Loading::_instance = 0;

Loading* Loading::Instance()
{
	if(_instance == 0)
		_instance = new Loading;
	return _instance;
}

Loading::Loading()
{
	block_factory = new BlockFactory;
	logo = block_factory->createObject();
	bckg = block_factory->createObject();
	bckg->setDescription(QRect(0,0,500,500),":/main_menu/00.jpg");
	p0 = block_factory->createObject();
	p1 = block_factory->createObject();
	p2 = block_factory->createObject();
	p3 = block_factory->createObject();
	p4 = block_factory->createObject();
	p5 = block_factory->createObject();
	p6 = block_factory->createObject();

	pauser = 0;
	i = 0;
	w = 500;
}

void Loading::anim(GameObject *o, QRect r, QString s, int k)
{
	if(pauser < /*w - 0 <- до какой координаты делать анимашку*/w - k)
	{
		o->setDescription(r,s);
	}
	else
	{
		i++;
		w += 400;
	}
}

QVector<GameObject *> Loading::objects()
{
	QVector <GameObject*> objects;

	objects.reserve(9);

	switch (i)
	{
	case 0:
		anim(p0,QRect(w - pauser,450,75,50),":/main_menu/05.png",75);
		break;
	case 1:
		anim(p1,QRect(w - pauser,450,75,50),":/main_menu/07.png",100);
		break;
	case 2:
		anim(p2,QRect(w - pauser,450,50,50),":/main_menu/02.png",175);
		break;
	case 3:
		anim(p3,QRect(w - pauser,450,75,50),":/main_menu/13.png",225);
		break;
	case 4:
		anim(p4,QRect(w - pauser,450,75,50),":/main_menu/11.png",250);
		break;
	case 5:
		anim(p5,QRect(w - pauser,475,100,25),":/main_menu/09.png",325);
		break;
	case 6:
		anim(p6,QRect(w - pauser,450,100,25),":/main_menu/09.png",325);
		break;
	case 7:
		logo->setDescription(QRect(80,20,340,200),":/main_menu/TetrisLogo.png");
		Game::Instance().setCurrent(Menu::Instance());
		break;
	}
	pauser += 1;

	objects.append(bckg);
	objects.append(logo);
	objects.append(p0);
	objects.append(p1);
	objects.append(p2);
	objects.append(p3);
	objects.append(p4);
	objects.append(p5);
	objects.append(p6);

	return objects;
}

void Loading::keyPress(QKeyEvent* event)
{
	if(event->key() == Qt::Key_Return)
	{
		Game::Instance().setCurrent(Menu::Instance());
	}
}

void Loading::keyRelease(GameWidget*, QKeyEvent*, QTimer*)
{

}
