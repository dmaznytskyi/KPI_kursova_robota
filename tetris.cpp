#include <QMessageBox>
#include <QPainter>
#include <QWidget>
#include <QDebug>
#include <QtMultimedia/QSound>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QInputDialog>

#include "scoreboard.h"
#include "game.h"
#include "menu.h"
#include "tetris.h"

Tetris::Tetris()
{
	int gameMap[16][10]  = {{0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0}};

	Lose = false;

	tetrimino_factory =	   new TetriminoFactory;
	block_factory     =    new BlockFactory;
	text_factory      =    new TextFactory;
	animation_factory =    new AnimationFactory;

	next = text_factory->createObject(100,100);
	next->setText("NEXT :",QRect(350,50,0,0),"black");

	tnext = tetrimino_factory->createObject();
	tnext->setDescription(QRect(375,75,20,20),":/main_menu/00.png");

	bckg = block_factory->createObject();
	bckg->setDescription(QRect(0,0,500,500),":/main_menu/00.jpg");

	score = text_factory->createObject(100,100);
	score->setText("SCORE \n 0",QRect(350,180,0,0),"black");

	gamefield = block_factory->createObject();
	gamefield->setDescription(QRect(48,48,254,404),":/main_menu/gamefield.png");

	controls = block_factory->createObject();
	controls->setDescription(QRect(348,238,104,222),":/main_menu/controls.png");

	tetrimino = tetrimino_factory->createObject();
	tetrimino->setDescription(QRect(200,200,75,50),":/main_menu/00.png");

	tetrimino->setColliding(PlacedTetriminoesMap);
	Score = 0;
//	animation = animation_factory->createObject(QRect(300,300,40,40),":/images/explosion.png",5);
/*
	base = block_factory->createObject();
	base->setDescription(QRect(350,530,30,30),":/images/base.png");
	base->setID(5);

	BrickMap.append(base);
	PlayerCollisions.append(base);

	gameover = block_factory->createObject();
	gameover->setDescription(QRect(300,300,100,100),":/images/logo.png");

	border = block_factory->createObject();
	border->setDescription(QRect(0,0,800,600),":/images/images/border.png");

	playercontrol = block_factory->createObject();
	playercontrol->setDescription(QRect(10,200,120,220),":/images/Control1");

	lifecounter = block_factory->createObject();
	lifecounter->setDescription(QRect(700,400,20,20),":/images/3.png");

	for(int i =0;i<13;i++)
	{
		for(int j =0;j<13;j++)
		{
			if(gameMap[i][j] == Brick){
				block = block_factory->createObject();
				block->setID(1);
				block->setDescription(QRect(40*j+140,40*i+40,40,40),":/images/brick.png");
				BrickMap.append(block);
				PlayerCollisions.append(block);
			}
			if(gameMap[i][j] == Green){
				block = block_factory->createObject();
				block->setID(2);
				block->setDescription(QRect(40*j+140,40*i+40,40,40),":/images/green.png");
				GreenMap.append(block);
			}
			if(gameMap[i][j] == Water)
			{
				block = block_factory->createObject();
				block->setID(3);
				block->setDescription(QRect(40*j+140,40*i+40,40,40),":/images/water.png");
				WaterMap.append(block);
				PlayerCollisions.append(block);
			}
			if(gameMap[i][j] == Steel)
			{
				block = block_factory->createObject();
				block->setID(4);
				block->setDescription(QRect(40*j+140,40*i+40,40,40),":/images/metal.png");
				BrickMap.append(block);
				PlayerCollisions.append(block);
			}
		}
	}

	EnemyCollisions = PlayerCollisions;



	player1->setColliding(PlayerCollisions);

	Pause = false;

	bullet = nullptr;

	pauser = 0;
	EnemyCount = 0;
	*/
}


void Tetris::draw()
{


}

void Tetris::clearList()
{
	qDeleteAll(Game::Instance().current->objects());
}

QVector <GameObject*> Tetris::objects()
{
	gameobjects.clear();
//	gameobjects.append(bckg);
	gameobjects.append(tetrimino);
	gameobjects.append(gamefield);
	gameobjects.append(tnext);
	gameobjects.append(next);
	gameobjects.append(score);
	gameobjects.append(controls);

	tetrimino = tetrimino_factory->createObject();
	tetrimino->setDescription(QRect(200,200,75,50),":/main_menu/00.png");
/*
	gameobjects.append(border);

	gameobjects.append(lifecounter);
	gameobjects.append(playerlifes);
	gameobjects.append(playercontrol);

	//для конца игры
	if( player1->getLifes() == 0 || Lose ){
		gameobjects.append(gameover);
		setHighscore();
	}

	foreach (GameObject* animation, Animations)
	{
		if(animation->isActive())
		{
			gameobjects.append(animation);
		}
		else
		{
			Animations.removeOne(animation);
			delete animation;
		}
	}

	foreach (GameObject* water, WaterMap)
	{
		gameobjects.append(water);
	}


	if(player1->bulletPointer() != nullptr){
		bullets.append(player1->bulletPointer());
		gameobjects.append(player1->bulletPointer());

	}

	foreach (GameObject* enemy, enemies) {
		if(enemy->bulletPointer() != nullptr ){
			gameobjects.append(enemy->bulletPointer());
			bullets.append(enemy->bulletPointer());
			enemybullets.append(enemy->bulletPointer());
		}
	}

	YouLose(enemybullets);

	KillEnemies(player1);

	foreach(GameObject * tonew,BulletsBlocks(bullets))
	{
		// if(tonew->isActive())
		gameobjects.append(tonew) ;
	}

	foreach(GameObject * tonew,BrickMap)
	{
		gameobjects.append(tonew);
	}

	if(player1->getLifes()>0)
	{
		player1->setColliding(PlayerCollisions);
		gameobjects.append(player1);
	}


	foreach (GameObject* tonew, enemies)
	{
		EnemyCollisions.removeOne(tonew);
		tonew->setColliding(EnemyCollisions);
		EnemyCollisions.append(tonew);
		gameobjects.append(tonew);
	}

	foreach (GameObject* green, GreenMap)
	{
		gameobjects.append(green);
	}

	if(Pause)
	{
		block = block_factory->createObject();
		block->setDescription(QRect(350,300,60,15),":/images/pause.png");
		QSound::play(":/sound/sounds/pause.wav");
		gameobjects.append(block);
		Game::Instance().WinGame->timer->stop();
	}
*/
	return gameobjects;
}

/*
QVector<GameObject *> Tetris::BulletsBlocks(QVector<GameObject *> bullets)
{
	QVector <GameObject*> back;

	foreach(GameObject* bullet,bullets)
	{
		foreach(GameObject* block,BrickMap)
		{
			if( block->pos().intersects(bullet->pos()) )
			{
				if(block->getID() == 1){
					Animations.append(animation_factory->createObject(QRect(block->getX(),block->getY(),40,40),":/images/explosion.png",5));
					bullet->hited(true);

					PlayerCollisions.removeOne(block);
					EnemyCollisions.removeOne(block);

					BrickMap.removeAt(BrickMap.indexOf(block));

					delete block;
					block = nullptr;

					QSound::play(":/sound/sounds/brickhit.wav");

				}else{
					if ( block->getID() == 4)
					{
						bullet->hited(true);
						QSound::play(":/sound/sounds/steelhit.wav");
					}

					if (block->getID() == 5)
						Lose = true;
				}
			}else{
				back.append(bullet);
			}
		}
	}
	return back;
}
*/
/*
void Tetris::KillEnemies(GameObject * player)
{
	foreach(GameObject* enemy , enemies)
	{
		if(player->bulletPointer() != nullptr)
		{
			if( enemy->pos().intersects(player->bulletPointer()->pos()) )
			{
				Animations.append(animation_factory->createObject(QRect(enemy->getX(),enemy->getY(),40,40),":/images/explosion.png",5));
				EnemyCount--;

				enemies.removeOne(enemy);
				PlayerCollisions.removeOne(enemy);
				EnemyCollisions.removeOne(enemy);

				// delete enemy->bulletPointer();
				// enemy->bulletPointer() = nullptr;

				delete enemy;
				enemy = nullptr;
				player->bulletPointer()->hited(true);

				Score++;
				QString str = QString("SCORE \n%1").arg(Score);
				score->drawText(str);
				QSound::play(":/sound/sounds/eexplosion.wav");
				QSound::play(":/sound/sounds/winner.wav");
				return;
			}
		}else{return;}
	}
}
*/
/*
void Tetris::YouLose(QVector<GameObject *>bullets)
{
	foreach(GameObject* bullet,bullets)
	{
		if(player1->pos().intersects(bullet->pos()))
		{
			bullet->hited(true);
			Animations.append(animation_factory->createObject(QRect(player1->getX(),player1->getY(),35,35),":/images/explosion.png",5));
			player1->die();
			QString str = QString(":/images/%1.png").arg(player1->getLifes());
			lifecounter->setDescription(QRect(700,400,20,20),str);
		}
	}
}
*/

/*
 * this is for score!
 *
 * QString str = QString("SCORE \n%1").arg(Score);
 * score->drawText(str);
 */

//всё что ниже - готово!!!
void Tetris::setHighscore()
{
	bool Entered;

	QString str = QInputDialog::getText( 0,
										 "GAME OVER",
										 "Enter Name:",
										 QLineEdit::Normal,
										 "",
										 &Entered
										 );
	if(Entered)
	{
		std::vector<data_player> data;

		QFile inputFile("/Users/dmaznytskyi/KPI_kursova_robota/highscores.txt");

		inputFile.open(QFile::ReadOnly);
		QTextStream in(&inputFile);
		while (!in.atEnd())
		{
			QString line1 = in.readLine();
			QString line2 = in.readLine();
			data.push_back(data_player(line1,line2));
		}

		data.push_back(data_player(str,QString::number(Score)));
		std::sort(data.begin(),data.end());
		inputFile.close();
		inputFile.open(QFile::WriteOnly | QFile::Truncate);
		foreach(data_player scores, data)
		{
			inputFile.flush();
			in << scores.name;
			inputFile.flush();
			in << "\n";
			inputFile.flush();
			in << scores.score;
			inputFile.flush();
			in << "\n" ;
		}
		data.clear();
		inputFile.close();
		Game::Instance().setCurrent(new Scoreboard);
	}
	else
	{
		Game::Instance().setCurrent(Menu::Instance());
	}
}

void Tetris::mouse(GameWidget*, QMouseEvent*)
{

}

void Tetris::keyPress(QKeyEvent* event)
{
	switch (event->key())
	{
	case Qt::Key_Down :
		tetrimino->moveDown();
		break;

	case Qt::Key_Right :
		tetrimino->moveRight();
		break;

	case Qt::Key_Left :
		tetrimino->moveLeft();
		break;

	case Qt::Key_Space :
		tetrimino->rotate();
		break;

	case Qt::Key_P :
		if(Pause)
		{
			Pause = false;
			Game::Instance().game->timer->start(16.666);
		}
		else
		{
			Pause = true;
		}

	case Qt::Key_Escape :
		setHighscore();
		break;
	}

}

void Tetris::keyRelease(GameWidget*, QKeyEvent* event, QTimer*)
{

	switch (event->key())
	{
	case Qt::Key_Down :
		tetrimino->move();
		break;

	case Qt::Key_Right :
		tetrimino->move();
		break;

	case Qt::Key_Left :
		tetrimino->move();
		break;
	}
}
