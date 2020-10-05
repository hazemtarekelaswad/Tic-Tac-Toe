#include <iostream>
#include <string>
#include "Constants.h"
#include "Game.h"
#include "Grid.h"

Game::Game(const std::string& title) : grid(title), status(GameStatus::STILL_PLAYING) {}

void Game::SetUp() {
	grid.PrintTitle();
	grid.ReadPlayersInfo();
	grid.PrintPlayersInfo();
	grid.UpdateGrid();
}

GameStatus Game::Start() {
	do {
		grid.UpdateGrid(grid.SelectCell());
		status = grid.GetGameStatus();
	} while (status == GameStatus::STILL_PLAYING);
	return status;
}

void Game::PrintResult(const GameStatus& status) const {
	switch (status) {
	case GameStatus::PLAYER1:
		std::cout << "PLAYER 1 WINS :D \n\n";
		break;

	case GameStatus::PLAYER2:
		std::cout << "PLAYER 2 WINS :D \n\n";
		break;

	case GameStatus::DRAW:
		std::cout << "DRAW :( \n\n";
		break;
	}
}