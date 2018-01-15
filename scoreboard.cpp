#include <QTextStream>

#include "scoreboard.h"
#include "game.h"
#include "menu.h"


Scoreboard::Scoreboard()
{
	text_factory =  new TextFactory;
	block_factory = new BlockFactory;

	int i = 0;

	GameObject* Table = block_factory->createObject();
	Table->setDescription(QRect(0,0,500,500),":/main_menu/scoreboard.png");

	table.append(Table);


	QFile inputFile("/Users/dmaznytskyi/univer/OOP/labs/tetris_game/highscores.txt");
	if (inputFile.open(QIODevice::ReadOnly))
	{
	   QTextStream in(&inputFile);
	   while (!in.atEnd())
	   {
		  QString line1 = in.readLine();
		  QString line2 = in.readLine();

		  GameObject* name = text_factory->createObject(500,450);
		  GameObject* score = text_factory->createObject(500,450);
		  name->setText(line1,QRect(40,104+i*35,0,0),"white");
		  score->setText(line2,QRect(345,104+i*35,0,0),"white");

		  table.append(name);
		  table.append(score);
		  i++;
	   }
	   inputFile.close();
	}


}

void Scoreboard::clearList()
{

}


void Scoreboard::draw()
{


}

QVector<GameObject *> Scoreboard::objects()
{
	QVector <GameObject*> objects;

	foreach (GameObject* fromstr, table)
	{
		objects.append(fromstr);
	}

	return objects;

}

void Scoreboard::mouse(GameWidget*, QMouseEvent*)
{

}

void Scoreboard::keyPress(QKeyEvent* event)
{
	switch(event->key()){
		case Qt::Key_Escape :
			Game::Instance().setCurrent(Menu::Instance());
			delete this;
			break;
	}


}

Scoreboard::~Scoreboard()
{
   qDeleteAll(table);
   table.clear();
   delete text_factory;
   delete block_factory;

}

void Scoreboard::keyRelease(GameWidget*, QKeyEvent*, QTimer*)
{

}
