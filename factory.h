#ifndef FACTORY_H
#define FACTORY_H

#include "tetrimino.h"
#include "text.h"
#include "block.h"
//#include "enemy.h"
//#include "bullet.h"
//#include "animation.h"

class Factory
{
	public:
		virtual GameObject* createObject() = 0;
		virtual ~Factory();
};

class TetriminoFactory : public Factory
{
	public:
		GameObject* createObject();
};

class BlockFactory : public Factory
{
	public:
		GameObject* createObject();
};

class TextFactory
{
	public:
		GameObject* createObject(int,int);
};

class AnimationFactory
{
	public:
		GameObject* createObject(QRect position, const QString &image, const int imageCount);
};

#endif // FACTORY_H
