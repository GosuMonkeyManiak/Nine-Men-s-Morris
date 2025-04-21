#pragma once

class point
{
	protected:
		unsigned int x;
		unsigned int y;

		void setX(unsigned int xNewValue);
		void setY(unsigned int yNewValue);

	public:
		point(unsigned int xParam, unsigned int yParam);

		unsigned int getX(void);
		unsigned int getY(void);

		void setPosition(unsigned int newX, unsigned int newY);
};