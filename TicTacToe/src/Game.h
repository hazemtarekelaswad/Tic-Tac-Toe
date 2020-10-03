#pragma once

#include <iostream>
#include <string>
#include "Constants.h"
#include "Grid.h"

class Game {
private:
	Grid grid;
	GameStatus status;

public:
	Game(const std::string& title);						
	void SetUp();										// Setup the game with basic info
	GameStatus Start();									// Starts the game loop and returns the game result (winner)
	void PrintResult(const GameStatus& status) const;	// Prints the game result
};

