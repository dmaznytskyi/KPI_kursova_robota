#ifndef TETRIMINO_H
#define TETRIMINO_H

#include "gameobject.h"
#include "game.h"

class Tetrimino : public QObject,public GameObject
{
		Q_OBJECT
	public:
		void moveDown();
		void moveLeft();
		void moveRight();
		void rotate();
		void move();
		void setX(int);
		void setY(int);

		void setColliding(QVector<GameObject*>);
		bool isActive();
		void setActive(bool);
		int getX();
		int getY();
		bool isDead();
		void die();
		QRect pos();
		QPixmap img();
		Tetrimino();

	private:
		int tetr_state;
		QVector <GameObject*> collidings;
		int directionUp,directionRight;
		int speed_x,speed_y;

		bool Notdead;
		GameObject* bullet;
		QRect size;
		QPixmap image;


	private slots:
		void updatePos();

};

#endif // TETRIMINO_H
