#include <iostream>
#include <string>

#include "constants.h"
#include "Grid.h"

int main() {
	Grid game("Tic - Tac - Toe");
	game.PrintTitle();
	game.ReadPlayersInfo();
	game.UpdateGrid();

	while (1) {
		game.UpdateGrid(game.SelectCell());
	}

	return 0;
}