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

chip* player::placechip(point position)
{
	chip* selectedChip = &chips[chipsOnBoard];
	selectedChip->setPosition(position.getX(), position.getY());
	selectedChip->setIsOnBoard(true);
	chipsOnBoard++;

	return selectedChip;
}

void player::removechip(chip* chip) 
{
	chip->setPosition(0,0);
	chip->setIsOnBoard(false);

	chipsOnBoard--;
	
}

void player::movechip(chip* chipToMove, point targetPosition)
{
	chipToMove->setPosition(targetPosition.getX(), targetPosition.getY());
	
}