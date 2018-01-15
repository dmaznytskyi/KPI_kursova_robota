#ifndef TETRIMINO_H
#define TETRIMINO_H

#include "gameobject.h"
#include "game.h"

class Tetrimino : public QObject,public GameObject
{
		Q_OBJECT
	public:
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		void move();
		void setX(int);
		void setY(int);
		void setType(QPoint,int);
		int getType();

		GameObject* bulletPointer();

		void setColliding(QVector<GameObject*>);
		bool isActive();
		void setActive(bool);
		int getLifes();
		int getX();
		int getY();
		bool isDead();
		void die();
		void rotate();
		QRect pos();
		QPixmap img();
		Tetrimino();

	private:
		int player_type;
		bool bulletHit;
		QVector <GameObject*> collidings;
		int directionUp,directionRight;
		int speed_x,speed_y;
		int Lifes;

		bool Notdead;
		GameObject* bullet;
		QRect size;
		QPixmap image;


	private slots:
		void updatePos();
		void checkBullet();


};

#endif // TETRIMINO_H
