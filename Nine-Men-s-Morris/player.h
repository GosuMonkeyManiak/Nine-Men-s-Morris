#pragma once

#include "chip.h"
#include "utilities.h"

class player
{
	private:
		char *name;
		chip chips[9];
		byte chipsOnBoard;

	public:
		player(char *nameParam, color chipsColorParam);
		~player(void);
};