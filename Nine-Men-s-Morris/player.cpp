#define _CRT_SECURE_NO_WARNINGS

#include <string.h>

#include "player.h"
#include "utilities.h"


player::player(char* nameParam, color chipsColorParam)
{
	byte nameLength = strlen(nameParam);

	name = new char[nameLength + 1];
	strncpy(name, nameParam, nameLength);
	name[nameLength] = '\0';

	for (int i = 0; i < 9; i++)
	{
		chips[i].setColor(chipsColorParam);
	}

	chipsOnBoard = 0;
}

player::~player(void)
{
	delete [] name;
}

char* player::getName(void)
{
	return name;
}

int player::getChipsOnBoard(void)
{
	return chipsOnBoard;
}

chip* player::placeChip(point position)
{
	chip* selectedChip = &chips[chipsOnBoard];
	selectedChip -> setX(position.getX());
	selectedChip -> setY(position.getY());
	selectedChip -> setIsOnBoard(true);
	chipsOnBoard++;

	return selectedChip;
}

void player::removeChip(chip* chipToRemove) 
{
	chipToRemove -> setX(0);
	chipToRemove -> setY(0);
	chipToRemove -> setIsOnBoard(false);

	chipsOnBoard--;
}

void player::moveChip(chip* chipToMove, point targetPosition)
{
	chipToMove -> setX(targetPosition.getX());
	chipToMove -> setY(targetPosition.getY());
}