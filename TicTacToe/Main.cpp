#include <iostream>
#include <string>

#include "constants.h"
#include "Grid.h"

int main() {
	Grid game("Tic - Tac - Toe");
	game.PrintTitle();
	game.ReadPlayersInfo();
	game.UpdateGrid();
	
	int winner;
	do {
		game.UpdateGrid(game.SelectCell());
		winner = game.GetWinner();
	} while (winner == -2);

	if (winner == -1)
		std::cout << "DRAW\n";
	else if (winner == 0)
		std::cout << "Player 1 Wins\n";
	else
		std::cout << "Player 2 Wins \n";

	return 0;
}