#pragma once

#include <iostream>
#include <string>
#include "Constants.h"

struct Player {
	std::string name;
	char symbol;
};

class Grid {
private:
	const std::string m_title;				// Game title
	Player m_player[NUMS_OF_PLAYERS];		// Array of players (2 players)
	char m_cell[GRID_SIZE][GRID_SIZE];		// The grid cells as 2D array
	bool m_turn;							// Turn toggles between 0 and 1 (2 players)

	void AdvancePlayer();					// To change turns between the two players
	bool IsFull() const;

public:
	Grid(const std::string& title);			// Constructor the take Game title as a parameter

	void PrintTitle() const;
	void ReadPlayersInfo();					// Asks players to enter their names and their chosen symbols
	void PrintPlayersInfo() const;			// Prints players' names and symbols in specific format
	
	void DrawGrid(int selectedCell);		// Draws the grid and takes the selected cell as a parameter to replace then chosen number with a symbol
	void UpdateGrid(int selectedCell = 0);	// Updates the Grid with the chosen numbers
	
	int SelectCell() const;					// Asks players to select number from the grid
	GameStatus GetGameStatus();				// Returns if the game ends as draw or winning or still proceeded
};	

