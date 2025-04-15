#pragma once

#include "chip.h"

class player
{
	private:
		char *name;
		chip chips[9];
		unsigned char chipsOnBoard;

	public:
		player(char *nameParam, color chipsColorParam);
		~player(void);
};