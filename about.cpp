#include "about.h"
#include "game.h"
#include "menu.h"

About::About()
{
	BlockFactory *block_factory = new BlockFactory;
	TextFactory *text_factory = new TextFactory;

	GameObject* author = block_factory->createObject();

	author->setDescription(QRect(0,0,500,500),":/main_menu/author.png");

	about.append(author);
}

void About::keyPress(QKeyEvent* event)
{
	switch(event->key()){
		case Qt::Key_Return :
			Game::Instance().setCurrent(Menu::Instance());
			delete this;
			break;
	}
}

QVector<GameObject *> About::objects()
{
	QVector <GameObject*> objects;

	foreach (GameObject* go, about)
	{
		objects.append(go);
	}
	return objects;
}

About::~About()
{
   qDeleteAll(about);
   about.clear();
}

void About::clearList()
{

}

void About::draw()
{

}

void About::mouse(GameWidget*, QMouseEvent*)
{

}

void About::keyRelease(GameWidget*, QKeyEvent*, QTimer*)
{

}
