#pragma once

#include "point.h"
#include "color.h"


class chip : public point
{
	private:
		color chipColor;
		unsigned char isOnBoard;

	public:
		chip(color chipColorParam);

		void move(point targetPosition);
		void place(point position);
		void remove(void);
};