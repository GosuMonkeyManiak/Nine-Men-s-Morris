#include "chip.h"

chip::chip() : point(0, 0)
{
	chipColor = noColor;
	isOnBoard = 0;
}

chip::chip(color chipColorParam) : point(0, 0)
{
	chipColor = chipColorParam;
	isOnBoard = 0;
}

color chip::getColor()
{
	return chipColor;
}

void chip::setColor(color newColorValue)
{
	chipColor = newColorValue;
}

void chip::setIsOnBoard(bool state)
{
	isOnBoard = state;
}