#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "printUtil.h"
#include "point.h"
#include "color.h"

void printEmptyBoard();
void printChips(chip* chips[]);

point screenPositionBasedOnBoardPosition[24]
{
	point(0	, 0),
	point(18, 0),
	point(36, 0),
	point(36, 9),
	point(36, 18),
	point(18, 18),
	point(0	, 18),
	point(0	, 9),
	point(8	, 2),
	point(18, 2),
	point(28, 2),
	point(28, 9),
	point(28, 16),
	point(18, 16),
	point(8	, 16),
	point(8	, 9),
	point(12, 5),
	point(18, 5),
	point(24, 5),
	point(24, 9),
	point(24, 13),
	point(18, 13),
	point(12, 13),
	point(12, 9)
};

void printBoard(chip *chips[])
{
	system("cls");
	printEmptyBoard();
	printChips(chips);
}

void printEmptyBoard()
{
	int colLength = 37;
	int rowLength = 19;

	for (int row = 0; row < rowLength; row++)
	{
		for (int col = 0; col < colLength; col++)
		{
			if (row == 0 || row == rowLength - 1) // first and last row
			{
				if (col == 0 || col == (colLength / 2) || col == colLength - 1)
				{
					printf("O");
				}
				else
				{
					printf("%c", col % 2 == 0 ? '-' : ' ');
				}
			}
			else if (row == 1 || row == rowLength - 2) // second and last - 2 row
			{
				if (col == 0 || col == (colLength / 2) || col == colLength - 1)
				{
					printf("|");
				}
				else
				{
					printf(" ");
				}
			}
			else if (row == (rowLength / 2)) // mid row
			{
				if (col == ((colLength / 4) - 1) || col == (((colLength / 4) * 3) + 1))
				{
					printf("O");
				}
				else if (col == 0 || col == (colLength - 1))
				{
					printf("O");
				}
				else if ((col > 0 && col < ((colLength / 4) - 1)) || (col > (((colLength / 4) * 3) + 1) && col < (colLength - 1)))
				{
					printf("%c", col % 2 == 0 ? '-' : ' ');
				}
				else if (col == (((colLength / 8) * 3.5) - 2) || col == (((colLength / 8) * 5.5) + 2))
				{
					printf("O");
				}
				else if ((col > ((colLength / 4) - 1) && col < (((colLength / 8) * 3.5) - 2)) || (col > (((colLength / 8) * 5.5) + 2) && col < (((colLength / 4) * 3) + 1)))
				{
					printf("%c", col % 2 == 0 ? '-' : ' ');
				}
				else
				{
					printf(" ");
				}
			}
			else if (row == 2 || row == rowLength - 1 - 2) // third and last - 3 row
			{
				if (col == ((colLength / 4) - 1) || col == (colLength / 2) || col == (((colLength / 4) * 3) + 1))
				{
					printf("O");
				}
				else if (col > ((colLength / 4) - 1) && col < (((colLength / 4) * 3) + 1))
				{
					printf("%c", col % 2 == 0 ? '-' : ' ');
				}
				else if (col == 0 || col == colLength - 1)
				{
					printf("|");
				}
				else
				{
					printf(" ");
				}
			}
			else if (row == 5 || row == rowLength - 1 - 5) //fifth and last - 5 row
			{
				if (col == (((colLength / 8) * 3.5) - 2) || col == (colLength / 2) || col == (((colLength / 8) * 5.5) + 2))
				{
					printf("O");
				}
				else if ((col > (((colLength / 8) * 3.5) - 2) && col < (colLength / 2)) || (col > (colLength / 2) && col < (((colLength / 8) * 5.5) + 2)))
				{
					printf("%c", col % 2 == 0 ? '-' : ' ');
				}
				else if (col == 0 || col == colLength - 1 || col == ((colLength / 4) - 1) || col == (((colLength / 4) * 3) + 1))
				{
					printf("|");
				}
				else
				{
					printf(" ");
				}
			}
			else if ((row > 2 && row < 5) || (row > 13 && row < 16)) //space between third and fifth row upper half and lower halfs
			{
				if (col == 0 || col == colLength - 1)
				{
					printf("|");
				}
				else if (col == ((colLength / 4) - 1) || col == (((colLength / 4) * 3) + 1))
				{
					printf("|");
				}
				else if (col == (colLength / 2))
				{
					printf("|");
				}
				else
				{
					printf(" ");
				}
			}
			else //space between fifth and mid row upper half and lower half (row > 5 && row < 9) || (row > 9 && row < 13)
			{
				if (col == 0 || col == colLength - 1)
				{
					printf("|");
				}
				else if (col == ((colLength / 4) - 1) || col == (((colLength / 4) * 3) + 1))
				{
					printf("|");
				}
				else if (col == (((colLength / 8) * 3.5) - 2) || col == (((colLength / 8) * 5.5) + 2))
				{
					printf("|");
				}
				else
				{
					printf(" ");
				}
			}
		}

		printf("\n");
	}
}

void printChips(chip* chips[])
{
	HANDLE outputHandler = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD carriagePos;

	for (int i = 0; i < 23; i++)
	{
		if (chips[i] != NULL)
		{
			point screenPos = screenPositionBasedOnBoardPosition[i];

			carriagePos.X = screenPos.getX();
			carriagePos.Y = screenPos.getY();

			SetConsoleCursorPosition(outputHandler, carriagePos);

			//waiting chip::getColor function to be add
			//printf("%d", chips[i] -> getColor() == white ? WHITE_CHIP : BLACK_CHIP);
		}
	}

	carriagePos.X = 0;
	carriagePos.Y = 19;

	SetConsoleCursorPosition(outputHandler, carriagePos);
}