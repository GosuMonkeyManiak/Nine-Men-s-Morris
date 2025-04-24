#include "board.h"
#include "color.h"

int main()
{
	char player1Name[] = "Dimitar";
	char player2Name[] = "Ivan";

	player player1(player1Name, white);
	player player2(player2Name, black);

	board game(&player1, &player2, white, black);

	game.placingChips();
	game.movingChips();
}