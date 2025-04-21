#include "point.h"

point::point(unsigned int xParam, unsigned int yParam)
{
	x = xParam;
	y = yParam;
}

unsigned int point::getX(void)
{
	return x;
}

void point::setX(unsigned int xNewValue)
{
	x = xNewValue;
}

unsigned int point::getY(void)
{
	return y;
}

void point::setY(unsigned int yNewValue)
{
	y = yNewValue;
}

void point::setPosition(unsigned int newX, unsigned int newY)
{
	setX(newX);
	setY(newY);
}