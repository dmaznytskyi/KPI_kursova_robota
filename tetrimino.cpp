#include "tetrimino.h"
#include "game.h"

Tetrimino::Tetrimino()
{
	directionRight = 0;
	directionUp = -1;

//	bullet = new Bullet(QPoint(this->getX()+15*directionRight,this->getY()+15*directionUp),directionRight,directionUp);

//	connect(Game::Instance().game->timer,SIGNAL(timeout()),this,SLOT(checkBullet()));

	speed_x = 0;
	speed_y = 0;
	tetr_state = rand() % 19;

	QString prefix = (QString::number(tetr_state).length() == 1) ? "0" : "";

	image.load(":/main_menu/" + prefix + QString::number(tetr_state) + ".png");
	size = QRect(375,75,100,100);
	//connect(Game::Instance().game->timer,SIGNAL(timeout()),this,SLOT(updatePos()));
}

void Tetrimino::updatePos()
{
	bool collide = false;

	size.translate(speed_x,speed_y);

	foreach(GameObject* collision, collidings)
	{
	  if ( this->pos().intersects(collision->pos()) || size.x()<140 || size.x()>630 || size.y()<40 || size.y()>530 )
	  collide = true;
	}

	if (collide)
	size.translate(-speed_x,-speed_y);
}

void Tetrimino::die()
{
	disconnect(Game::Instance().game->timer,SIGNAL(timeout()),this,SLOT(updatePos()));
}

void Tetrimino::move()
{
	speed_x = 0;
	speed_y = 0;
}

void Tetrimino::setX(int a)
{
	size.setRect(a,size.y(),30,30);
}

void Tetrimino::setY(int a)
{
	size.setRect(size.x(),a,30,30);
}

int Tetrimino::getX()
{
	return size.x();
}

int Tetrimino::getY()
{
	return size.y();
}

bool Tetrimino::isDead()
{

}

QPixmap Tetrimino::img()
{
	return image;
}

QRect Tetrimino::pos()
{
	return size;
}

void Tetrimino::moveDown()
{
	directionRight  = 0;
	directionUp = 1;

	speed_x = 0;
	speed_y = 2;
}

void Tetrimino::moveLeft()
{
	directionRight  = -1;
	directionUp = 0;

	speed_x = -2;
	speed_y = 0;
}

void Tetrimino::moveRight()
{
	directionRight  = 1;
	directionUp = 0;

	speed_x = 2;
	speed_y = 0;
}

void Tetrimino::setColliding(QVector<GameObject *> vector)
{
	collidings = vector;
}

bool Tetrimino::isActive()
{
	return Notdead;
}
void Tetrimino::setActive(bool a)
{
	Notdead = a;
}

void Tetrimino::rotate()
{
	switch (tetr_state)
	{
		case 0:
			image.load(":/main_menu/01.png");
			size = QRect(375,75,50,75);
			break;
		case 1:
			image.load(":/main_menu/00.png");
			size = QRect(375,75,75,50);
			break;
		case 3:
			image.load(":/main_menu/04.png");
			size = QRect(375,75,50,75);
			break;
		case 4:
			image.load(":/main_menu/03.png");
			size = QRect(375,75,75,50);
			break;
		case 5:
			image.load(":/main_menu/06.png");
			size = QRect(375,75,50,75);
			break;
		case 6:
			image.load(":/main_menu/07.png");
			size = QRect(375,75,75,50);
			break;
		case 7:
			image.load(":/main_menu/08.png");
			size = QRect(375,75,50,75);
			break;
		case 8:
			image.load(":/main_menu/05.png");
			size = QRect(375,75,75,50);
			break;
		case 9:
			image.load(":/main_menu/10.png");
			size = QRect(375,75,25,100);
			break;
		case 10:
			image.load(":/main_menu/09.png");
			size = QRect(375,75,100,25);
			break;
		case 11:
			image.load(":/main_menu/12.png");
			size = QRect(375,75,50,75);
			break;
		case 12:
			image.load(":/main_menu/13.png");
			size = QRect(375,75,75,50);
			break;
		case 13:
			image.load(":/main_menu/14.png");
			size = QRect(375,75,50,75);
			break;
		case 14:
			image.load(":/main_menu/11.png");
			size = QRect(375,75,75,50);
			break;
		case 15:
			image.load(":/main_menu/16.png");
			size = QRect(375,75,75,50);
			break;
		case 16:
			image.load(":/main_menu/17.png");
			size = QRect(375,75,50,75);
			break;
		case 17:
			image.load(":/main_menu/18.png");
			size = QRect(375,75,75,50);
			break;
		case 18:
			image.load(":/main_menu/15.png");
			size = QRect(375,75,50,75);
			break;
	}
}
