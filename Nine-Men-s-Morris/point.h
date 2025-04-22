#pragma once

class point
{
	protected:
		unsigned int x;
		unsigned int y;

	public:
		point(unsigned int xParam, unsigned int yParam);

		unsigned int getX(void);
		void setX(unsigned int xNewValue);

		unsigned int getY(void);
		void setY(unsigned int yNewValue);
};