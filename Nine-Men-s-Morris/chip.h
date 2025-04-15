#pragma once

#include "point.h"
#include "color.h"
#include "utilities.h"

class chip : public point
{
	private:
		color chipColor;
		byte isOnBoard;

	public:
		chip();
		chip(color chipColorParam);

		void setColor(color newColorValue);

		void move(point targetPosition);
		void place(point position);
		void remove(void);
};