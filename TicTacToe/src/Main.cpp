#include <iostream>
#include <string>
#include "Constants.h"
#include "Grid.h"

int main() {
	Grid game("Tic - Tac - Toe");
	game.PrintTitle();
	game.ReadPlayersInfo();
	game.UpdateGrid();
	
	do {
		game.UpdateGrid(game.SelectCell());
		Status = game.GetGameStatus();
	} while (Status == GameStatus::STILL_PLAYING);

	if (Status == GameStatus::DRAW)
		std::cout << "DRAW\n";
	else if (Status == GameStatus::PLAYER1)
		std::cout << "Player 1 Wins\n";
	else
		std::cout << "Player 2 Wins \n";

	return 0;
}