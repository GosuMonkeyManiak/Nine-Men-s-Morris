#define _CRT_SECURE_NO_WARNINGS

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

	player1Damas = 0;
	player2Damas = 0;
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
			if (chips[0] != NULL && chips[7] != NULL && chips[6] != NULL)
			{
				if (chips[0] -> getColor() == chips[7] -> getColor() && chips[0] -> getColor() == chips[6] -> getColor())
				{
					flag++;
				}
			}
			else if ((chips[0] != NULL && chips[1] != NULL && chips[2] != NULL))
			{
				if (chips[0] -> getColor() == chips[1] -> getColor() && chips[0] -> getColor() == chips[2] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 1:
		{
			if (chips[1] != NULL && chips[0] != NULL && chips[2] != NULL)
			{
				if (chips[1] -> getColor() == chips[0] -> getColor() && chips[1] -> getColor() == chips[2] -> getColor())
				{
					flag++;
				}
			}

			if (chips[1] != NULL && chips[9] != NULL && chips[17] != NULL)
			{
				if (chips[1] -> getColor() == chips[9] -> getColor() && chips[1] -> getColor() == chips[17] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 2:
		{
			if (chips[2] != NULL && chips[1] != NULL && chips[0] != NULL)
			{
				if (chips[2] -> getColor() == chips[1] -> getColor() && chips[2] -> getColor() == chips[0] -> getColor())
				{
					flag++;
				}
			}
			else if ((chips[2] != NULL && chips[3] != NULL && chips[4] != NULL))
			{
				if (chips[2] -> getColor() == chips[3] -> getColor() && chips[2] -> getColor() == chips[4] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 3:
		{
			if (chips[3] != NULL && chips[2] != NULL && chips[4] != NULL)
			{
				if (chips[3] -> getColor() == chips[2] -> getColor() && chips[3] -> getColor() == chips[4] -> getColor())
				{
					flag++;
				}
			}

			if (chips[3] != NULL && chips[11] != NULL && chips[19] != NULL)
			{
				if (chips[3] -> getColor() == chips[11] -> getColor() && chips[3] -> getColor() == chips[19] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 4:
		{
			if (chips[4] != NULL && chips[3] != NULL && chips[2] != NULL)
			{
				if (chips[4] -> getColor() == chips[3] -> getColor() && chips[4] -> getColor() == chips[2] -> getColor())
				{
					flag++;
				}
			}
			else if ((chips[4] != NULL && chips[5] != NULL && chips[6] != NULL))
			{
				if (chips[4] -> getColor() == chips[5] -> getColor() && chips[4] -> getColor() == chips[6] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 5:
		{
			if (chips[5] != NULL && chips[4] != NULL && chips[6] != NULL)
			{
				if (chips[5] -> getColor() == chips[4] -> getColor() && chips[5] -> getColor() == chips[6] -> getColor())
				{
					flag++;
				}
			}

			if (chips[5] != NULL && chips[13] != NULL && chips[21] != NULL)
			{
				if (chips[5]->getColor() == chips[13]->getColor() && chips[5]->getColor() == chips[21]->getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 6:
		{
			if (chips[6] != NULL && chips[5] != NULL && chips[4] != NULL)
			{
				if (chips[6] -> getColor() == chips[5] -> getColor() && chips[6] -> getColor() == chips[4] -> getColor())
				{
					flag++;
				}
			}
			else if ((chips[6] != NULL && chips[7] != NULL && chips[0] != NULL))
			{
				if (chips[6] -> getColor() == chips[7] -> getColor() && chips[6] -> getColor() == chips[0] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 7:
		{
			if (chips[7] != NULL && chips[6] != NULL && chips[0] != NULL)
			{
				if (chips[7] -> getColor() == chips[6] -> getColor() && chips[7] -> getColor() == chips[0] -> getColor())
				{
					flag++;
				}
			}

			if (chips[7] != NULL && chips[15] != NULL && chips[23] != NULL)
			{
				if (chips[7] -> getColor() == chips[15] -> getColor() && chips[7] -> getColor() == chips[23] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 8:
		{
			if (chips[8] != NULL && chips[9] != NULL && chips[10] != NULL)
			{
				if (chips[8] -> getColor() == chips[9] -> getColor() && chips[8] -> getColor() == chips[10] -> getColor())
				{
					flag++;
				}
			}
			else if ((chips[8] != NULL && chips[15] != NULL && chips[14] != NULL))
			{
				if (chips[8] -> getColor() == chips[15] -> getColor() && chips[8] -> getColor() == chips[14] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 9:
		{
			if (chips[9] != NULL && chips[1] != NULL && chips[17] != NULL)
			{
				if (chips[9] -> getColor() == chips[1] -> getColor() && chips[9] -> getColor() == chips[17] -> getColor())
				{
					flag++;
				}
			}

			if (chips[9] != NULL && chips[8] != NULL && chips[10] != NULL)
			{
				if (chips[9] -> getColor() == chips[8] -> getColor() && chips[9] -> getColor() == chips[10] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 10:
		{
			if (chips[10] != NULL && chips[9] != NULL && chips[8] != NULL)
			{
				if (chips[10] -> getColor() == chips[9] -> getColor() && chips[10] -> getColor() == chips[8] -> getColor())
				{
					flag++;
				}
			}
			else if ((chips[10] != NULL && chips[11] != NULL && chips[12] != NULL))
			{
				if (chips[10] -> getColor() == chips[11] -> getColor() && chips[10] -> getColor() == chips[12] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 11:
		{
			if (chips[11] != NULL && chips[3] != NULL && chips[19] != NULL)
			{
				if (chips[11] -> getColor() == chips[3] -> getColor() && chips[11] -> getColor() == chips[19] -> getColor())
				{
					flag++;
				}
			}

			if (chips[11] != NULL && chips[10] != NULL && chips[12] != NULL)
			{
				if (chips[11] -> getColor() == chips[10] -> getColor() && chips[11] -> getColor() == chips[12] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 12:
		{
			if (chips[12] != NULL && chips[11] != NULL && chips[10] != NULL)
			{
				if (chips[12] -> getColor() == chips[11] -> getColor() && chips[12] -> getColor() == chips[10] -> getColor())
				{
					flag++;
				}
			}
			else if ((chips[12] != NULL && chips[13] != NULL && chips[14] != NULL))
			{
				if (chips[12] -> getColor() == chips[13] -> getColor() && chips[12] -> getColor() == chips[14] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 13:
		{
			if (chips[13] != NULL && chips[5] != NULL && chips[21] != NULL)
			{
				if (chips[13] -> getColor() == chips[5] -> getColor() && chips[13] -> getColor() == chips[21] -> getColor())
				{
					flag++;
				}
			}

			if (chips[13] != NULL && chips[12] != NULL && chips[14] != NULL)
			{
				if (chips[13] -> getColor() == chips[12] -> getColor() && chips[13] -> getColor() == chips[14] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 14:
		{
			if (chips[14] != NULL && chips[13] != NULL && chips[12] != NULL)
			{
				if (chips[14] -> getColor() == chips[13] -> getColor() && chips[14] -> getColor() == chips[12] -> getColor())
				{
					flag++;
				}
			}
			else if ((chips[14] != NULL && chips[15] != NULL && chips[8] != NULL))
			{
				if (chips[14] -> getColor() == chips[15] -> getColor() && chips[14] -> getColor() == chips[8] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 15:
		{
			if (chips[15] != NULL && chips[7] != NULL && chips[23] != NULL)
			{
				if (chips[15] -> getColor() == chips[7] -> getColor() && chips[15] -> getColor() == chips[23] -> getColor())
				{
					flag++;
				}
			}

			if (chips[15] != NULL && chips[14] != NULL && chips[8] != NULL)
			{
				if (chips[15]->getColor() == chips[14]->getColor() && chips[15]->getColor() == chips[8]->getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 16:
		{
			if (chips[16] != NULL && chips[17] != NULL && chips[18] != NULL)
			{
				if (chips[16] -> getColor() == chips[17] -> getColor() && chips[16] -> getColor() == chips[18] -> getColor())
				{
					flag++;
				}
			}
			else if ((chips[16] != NULL && chips[23] != NULL && chips[22] != NULL))
			{
				if (chips[16] -> getColor() == chips[23] -> getColor() && chips[16] -> getColor() == chips[22] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 17:
		{
			if (chips[17] != NULL && chips[9] != NULL && chips[1] != NULL)
			{
				if (chips[17] -> getColor() == chips[9] -> getColor() && chips[17] -> getColor() == chips[1] -> getColor())
				{
					flag++;
				}
			}

			if (chips[17] != NULL && chips[16] != NULL && chips[18] != NULL)
			{
				if (chips[17] -> getColor() == chips[16] -> getColor() && chips[17] -> getColor() == chips[18] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 18:
		{
			if (chips[18] != NULL && chips[17] != NULL && chips[16] != NULL)
			{
				if (chips[18] -> getColor() == chips[17] -> getColor() && chips[18] -> getColor() == chips[16] -> getColor())
				{
					flag++;
				}
			}
			else if ((chips[18] != NULL && chips[19] != NULL && chips[20] != NULL))
			{
				if (chips[18] -> getColor() == chips[19] -> getColor() && chips[18] -> getColor() == chips[20] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 19:
		{
			if (chips[19] != NULL && chips[11] != NULL && chips[3] != NULL)
			{
				if (chips[19] -> getColor() == chips[11] -> getColor() && chips[19] -> getColor() == chips[3] -> getColor())
				{
					flag++;
				}
			}

			if (chips[19] != NULL && chips[18] != NULL && chips[20] != NULL)
			{
				if (chips[19] -> getColor() == chips[18] -> getColor() && chips[19] -> getColor() == chips[20] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 20:
		{
			if (chips[20] != NULL && chips[19] != NULL && chips[18] != NULL)
			{
				if (chips[20] -> getColor() == chips[19] -> getColor() && chips[20] -> getColor() == chips[18] -> getColor())
				{
					flag++;
				}
			}
			else if ((chips[20] != NULL && chips[21] != NULL && chips[22] != NULL))
			{
				if (chips[20] -> getColor() == chips[21] -> getColor() && chips[20] -> getColor() == chips[22] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 21:
		{
			if (chips[21] != NULL && chips[13] != NULL && chips[5] != NULL)
			{
				if (chips[21] -> getColor() == chips[13] -> getColor() && chips[21] -> getColor() == chips[5] -> getColor())
				{
					flag++;
				}
			}

			if (chips[21] != NULL && chips[20] != NULL && chips[22] != NULL)
			{
				if (chips[21] -> getColor() == chips[20] -> getColor() && chips[21] -> getColor() == chips[22] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 22:
		{
			if (chips[22] != NULL && chips[21] != NULL && chips[20] != NULL)
			{
				if (chips[22] -> getColor() == chips[21] -> getColor() && chips[22] -> getColor() == chips[20] -> getColor())
				{
					flag++;
				}
			}
			else if ((chips[22] != NULL && chips[23] != NULL && chips[16] != NULL))
			{
				if (chips[22] -> getColor() == chips[23] -> getColor() && chips[22] -> getColor() == chips[16] -> getColor())
				{
					flag++;
				}
			}
		}
		break;

		case 23:
		{
			if (chips[23] != NULL && chips[15] != NULL && chips[7] != NULL)
			{
				if (chips[23] -> getColor() == chips[15] -> getColor() && chips[23] -> getColor() == chips[7] -> getColor())
				{
					flag++;
				}
			}

			if (chips[23] != NULL && chips[22] != NULL && chips[16] != NULL)
			{
				if (chips[23]->getColor() == chips[22]->getColor() && chips[23]->getColor() == chips[16]->getColor())
				{
					flag++;
				}
			}
		}
		break;
	}

	return flag;
}

void board::placingChips(void)
{
	printBoard(NULL);

	char i;
	int selectedPosition;

	for (i = 18; i > 0; i--)
	{
		enter_Position:

		do
		{
			printf("Player %d (%s) enter position (0-23): ", INLINE_IF(i % 2 == 0, 1, 2), INLINE_IF(i % 2 == 0, player1, player2)->getName());
			scanf("%d", &selectedPosition);
		} while (selectedPosition < 0 || selectedPosition > 23);
		
		if (!isPositionEmpty(selectedPosition))
		{
			goto enter_Position;
		}

		chip* placedChip = INLINE_IF(i % 2 == 0, player1, player2) -> placeChip(screenPositionBasedOnBoardPosition[selectedPosition]);
		chips[selectedPosition] = placedChip;

		printBoard(chips);

		int damaCount = 0;

		if ((damaCount = isThereDama(selectedPosition)))
		{
			INLINE_IF(i % 2 == 0, player1Damas, player2Damas) += damaCount;

			if (damaCount > 1)
			{
				//with one chip we made two damas
				INLINE_IF(i % 2 == 0, player1ChipsInTwoDamas, player2ChipsInTwoDamas)++;
			}

			printf("Player %d (%s) has dama!\n", INLINE_IF(i % 2 == 0, 1, 2), INLINE_IF(i % 2 == 0, player1, player2) -> getName());

			int positionToRemove;

			enter_Position_To_Remove:

			do
			{
				printf("Player %d (%s) choose postion from which to remove chip (0-23): ", INLINE_IF(i % 2 == 0, 1, 2), INLINE_IF(i % 2 == 0, player1, player2)->getName());
				scanf("%d", &positionToRemove);
			} while (positionToRemove < 0 || positionToRemove > 23);

			if ((chips[positionToRemove] -> getColor()) == INLINE_IF(i % 2 == 0, player1Color, player2Color))
			{
				goto enter_Position_To_Remove;
			}

			if ((damaCount = isThereDama(positionToRemove)))
			{
				//check are there any free chips
					//yes - goto enter_Position_To_Remove:
					//no - continue

				int targetChipsOnBoard = INLINE_IF(i % 2 == 0, player2, player1) -> getChipsOnBoard();
				int targetChipsInDama = (INLINE_IF(i % 2 == 0, player2Damas, player1Damas) * 3) - INLINE_IF(i % 2 == 0, player2ChipsInTwoDamas, player1ChipsInTwoDamas);

				if (targetChipsOnBoard > targetChipsInDama)
				{
					goto enter_Position_To_Remove;
				}
				else
				{
					INLINE_IF(i % 2 == 0, player2Damas, player1Damas) -= damaCount;

					if (damaCount > 1)
					{
						INLINE_IF(i % 2 == 0, player2ChipsInTwoDamas, player1ChipsInTwoDamas)--;
					}
				}
			}

			INLINE_IF(i % 2 == 0, player2, player1) -> removeChip(chips[positionToRemove]);
			chips[positionToRemove] = NULL;

			printBoard(chips);
		}

	}

}