#include <iostream>
#include <string>
#include "Constants.h"
#include "Game.h"
#include "Grid.h"

int main() {
	Game game("Tic - Tac - Toe");
	game.SetUp();
	game.PrintResult(game.Start());
	system("pause");

	return 0;
}