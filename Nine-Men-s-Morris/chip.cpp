#include "chip.h"

chip::chip(color chipColorParam) : point(0, 0)
{
	chipColor = chipColorParam;
	isOnBoard = 0;
}

void chip::move(point targetPosition)
{
	setX(targetPosition.getX());
	setY(targetPosition.getY());
}

void chip::place(point position)
{
	setX(position.getX());
	setY(position.getY());

	isOnBoard = 1;
}

void chip::remove(void)
{
	setX(0);
	setY(0);

	isOnBoard = 0;
}