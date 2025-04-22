#include <stdio.h>

#include "board.h"
#include "global.h"
#include "printUtil.h"

#define INLINE_IF(condition, trueResult, falseResult) ( condition ? trueResult : falseResult )

board::board(
	player* player1Param,
	player* player2Param,
	color player1ColorParam = white,
	color player2ColorParam = black
)
{
	for (int i = 0; i < 24; i++)
	{
		chips[i] = NULL;
	}

	player1 = player1Param;
	player2 = player2Param;

	player1Color = player1ColorParam;
	player2Color = player2ColorParam;
}

int board::isPositionEmpty(int position)
{
	return chips[position] == NULL ? 1 : 0;
}

int board::isThereDama(int position)
{
	char flag = 0;

	switch (position)
	{
		case 0:
		{

		}
		break;

		case 1:
		{

		}
		break;

		case 2:
		{

		}
		break;

		case 3:
		{

		}
		break;

		case 4:
		{

		}
		break;

		case 5:
		{

		}
		break;

		case 6:
		{

		}
		break;

		case 7:
		{

		}
		break;

		case 8:
		{

		}
		break;

		case 9:
		{

		}
		break;

		case 10:
		{

		}
		break;

		case 11:
		{

		}
		break;

		case 12:
		{

		}
		break;

		case 13:
		{

		}
		break;

		case 14:
		{

		}
		break;

		case 15:
		{

		}
		break;

		case 16:
		{

		}
		break;

		case 17:
		{

		}
		break;

		case 18:
		{

		}
		break;

		case 19:
		{

		}
		break;

		case 20:
		{

		}
		break;

		case 21:
		{

		}
		break;

		case 22:
		{

		}
		break;

		case 23:
		{

		}
		break;
	}

	return flag;
}

void board::placingChips(void)
{
	char i;
	int selectedPosition;

	for (i = 18; i > 0; i--)
	{
		enter_Position:

		do
		{
			printf("Player %d enter position (0-23): ", INLINE_IF(i % 2 == 0, 1, 2));
			scanf("%d", &selectedPosition);
		} while (selectedPosition < 0 || selectedPosition > 23);
		
		if (!isPositionEmpty(selectedPosition))
		{
			goto enter_Position;
		}

		chip *placedChip;

		if (i % 2 == 0)
		{
			placedChip = player1 -> placeChip(screenPositionBasedOnBoardPosition[selectedPosition]);
		}
		else
		{
			placedChip = player2 -> placeChip(screenPositionBasedOnBoardPosition[selectedPosition]);
		}

		chips[selectedPosition] = placedChip;

		printBoard(chips, player1Color, player2Color);

		if (isThereDama(selectedPosition))
		{
			printf("Player %d has dama!\n", INLINE_IF(i % 2 == 0, 1, 2));

			int positionToRemove;

			enter_Position_To_Remove:

			do
			{
				printf("Player %d choose postion from which to remove chip (0-23): ", INLINE_IF(i % 2 == 0, 1, 2));
				scanf("%d", &positionToRemove);
			} while (positionToRemove < 0 || positionToRemove > 23);

			if ((chips[positionToRemove] -> getColor()) == INLINE_IF(i % 2 == 0, player1Color, player2Color))
			{
				goto enter_Position_To_Remove;
			}

			if (isThereDama(positionToRemove))
			{
				//check are there any free chips
					//yes - goto enter_Position_To_Remove:
					//no - continue
			}

			INLINE_IF(i % 2 == 0, player2, player1) -> removeChip(chips[positionToRemove]);
			chips[positionToRemove] = NULL;

			printBoard(chips, player1Color, player2Color);
		}

	}

}