#include <string.h>

#include "player.h"

player::player(char* nameParam, color chipsColorParam)
{
	unsigned char nameLength = strlen(nameParam);

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