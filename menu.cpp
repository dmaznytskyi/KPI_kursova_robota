#include "menu.h"
#include "game.h"
#include "tetris.h"
#include "scoreboard.h"

#include <QDebug>


Menu::Menu()
{
	block_factory = new BlockFactory;
	text_factory = new TextFactory;

	logo = block_factory->createObject();
	items = block_factory->createObject();
	pointer = block_factory->createObject();
	bckg = block_factory->createObject();

	p0 = block_factory->createObject();
	p1 = block_factory->createObject();
	p2 = block_factory->createObject();
	p3 = block_factory->createObject();
	p4 = block_factory->createObject();
	p5 = block_factory->createObject();
	p6 = block_factory->createObject();

	logo->setDescription(QRect(80,20,340,200),":/main_menu/TetrisLogo.png");
	items->setDescription(QRect(80,250,340,200),":/main_menu/main_menu_0.png");
	bckg->setDescription(QRect(0,0,500,500),":/main_menu/00.jpg");

	p0->setDescription(QRect(75,450,75,50),":/main_menu/05.png");
	p1->setDescription(QRect(100,450,75,50),":/main_menu/07.png");
	p2->setDescription(QRect(175,450,50,50),":/main_menu/02.png");
	p3->setDescription(QRect(225,450,75,50),":/main_menu/13.png");
	p4->setDescription(QRect(250,450,75,50),":/main_menu/11.png");
	p5->setDescription(QRect(325,475,100,25),":/main_menu/09.png");
	p6->setDescription(QRect(325,450,100,25),":/main_menu/09.png");

	MenuItem = 1;
}

Menu* Menu::_instance = 0;

Menu* Menu::Instance()
{
	if( _instance == 0)
	{
		_instance = new Menu;
	}
	return _instance;
}

void Menu::clearList()
{
	qDeleteAll(Game::Instance().current->objects());
}

QVector<GameObject *> Menu::objects()
{
	QVector <GameObject*> objects;

	objects.reserve(4);
	objects.append(bckg);
	objects.append(logo);
	objects.append(items);
	objects.append(pointer);

	objects.append(p0);
	objects.append(p1);
	objects.append(p2);
	objects.append(p3);
	objects.append(p4);
	objects.append(p5);
	objects.append(p6);

	switch (MenuItem)
	{
	case 1:
		pointer->setDescription(QRect(47,270,46,32),":/main_menu/16.png");
		break;
	case 2:
		pointer->setDescription(QRect(50,330,32,47),":/main_menu/17.png");
		break;
	case 3:
		pointer->setDescription(QRect(115,405,47,32),":/main_menu/18.png");
		break;
	}
	return objects;
}

void Menu::mouse(GameWidget*, QMouseEvent*)
{

}

void Menu::keyPress(QKeyEvent *event)
{
	if(event->key() == Qt::Key_Up)
	{
		switch (MenuItem)
		{
		case 1:
			MenuItem = 3;
			break;
		case 2:
			MenuItem = 1;
			break;
		case 3:
			MenuItem = 2;
			break;
		}
	}

	if(event->key() == Qt::Key_Down)
	{
		switch (MenuItem)
		{
		case 1:
			MenuItem = 2;
			break;
		case 2:
			MenuItem = 3;
			break;
		case 3:
			MenuItem = 1;
			break;
		}
	}

	if(event->key() == Qt::Key_Return)
	{
		switch (MenuItem)
		{
		case 1:
			Game::Instance().setCurrent(new Tetris);
			break;
		case 2:
			Game::Instance().setCurrent(new Scoreboard);
			break;
		case 3:
			Game::Instance().game->close();
			break;
		}
	}
}

void Menu::keyRelease(GameWidget*, QKeyEvent*, QTimer*)
{

}
