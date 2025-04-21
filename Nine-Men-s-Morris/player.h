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
		
		chip* placechip(point position);
		void removechip(chip* chip);
		
		void movechip(chip* chipToMove, point targetPosition);
		
		
};