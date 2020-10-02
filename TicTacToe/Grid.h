#pragma once
#include <iostream>
#include <string>
#include "constants.h"

struct Player {
	std::string name;
	char symbol;

	void Select(int selectedCell) {
		
	}
};

class Grid {
private:
	const std::string m_title;
	char cell[GRID_SIZE][GRID_SIZE];
	Player player[MAX_PLAYERS_NUMBER];
	bool m_turn;

	void AdvancePlayer();

public:
	Grid(const std::string& title);
	void PrintTitle() const;
	void ReadPlayersInfo();
	void PrintPlayersInfo() const;
	void DrawGrid(char selectedCell);
	void UpdateGrid(char selectedCell = '0');
	char SelectCell();
	int GetWinner();
	bool IsFull() const;
};

