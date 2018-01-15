#include "factory.h"

Factory::~Factory()
{

}

GameObject* TetriminoFactory::createObject()
{
	return new Tetrimino;
}

GameObject* BlockFactory::createObject()
{
	return new Block;
}

GameObject* TextFactory::createObject(int wight, int height)
{
	return new Text(wight,height);
}
/*
GameObject* AnimationFactory::createObject(QRect position, const QString &image, const int imageCount)
{
	return new Animation(position,image,imageCount);
}
*/
