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
		
		chip* placeChip(point position);
		void removeChip(chip* chipToRemove);
		void moveChip(chip* chipToMove, point targetPosition);
};