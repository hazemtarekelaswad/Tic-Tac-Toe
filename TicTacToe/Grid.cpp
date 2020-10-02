#include "Grid.h"
#include "constants.h"

#include <iostream>
#include <string>

Grid::Grid(const std::string& title) : m_title(title), m_turn(0) {
	char cellNums = '1';
	for (int i = 0; i < GRID_SIZE; ++i)
		for (int j = 0; j < GRID_SIZE; ++j)
			cell[i][j] = cellNums++;

	for (int i = 0; i < MAX_PLAYERS_NUMBER; ++i) {
		player[i].name = "Player " + (i + 1);
		player[i].symbol = 'X' + i;
	}
}

void Grid::PrintTitle() const{

	auto PrintBorder = [=]() {
		for (int i = 0; i < 18 + m_title.length(); ++i)
			std::cout << '=';
	};

	PrintBorder();
	std::cout << "\n\t" << m_title << '\n';
	PrintBorder();
	std::cout << '\n';
}

void Grid::ReadPlayersInfo() {
	for (int i = 0; i < MAX_PLAYERS_NUMBER; ++i) {
		std::cout << "Player " << i + 1 << " Name: ";
		std::cin >> player[i].name;
		std::cout << "Symbol: ";
		std::cin >> player[i].symbol;

		std::cout << '\n';
	}
}

void Grid::PrintPlayersInfo() const {
	for (int i = 0; i < MAX_PLAYERS_NUMBER; ++i) {
		std::cout << player[i].name << " (" << player[i].symbol << ")";
		if(i != MAX_PLAYERS_NUMBER - 1)
			std::cout << "    Vs.    ";
	}
	std::cout << "\n\n";
}

void Grid::AdvancePlayer() {
	m_turn ^= 1;
}

void Grid::DrawGrid(char selectedCell) {
	std::cout << "------------------\n";
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			for (int k = 0; k < GRID_SIZE; ++k) {
				if (j == 1) {
					if (cell[i][k] == selectedCell) {
						cell[i][k] = player[m_turn].symbol;
						AdvancePlayer();
					}
					std::cout << "  " << cell[i][k] << "  ";
				}
				else
					std::cout << "     ";
				std::cout << '|';
			}
			std::cout << '\n';
		}
		std::cout << "------------------\n";
	}
}

void Grid::UpdateGrid(char selectedCell) {
	system("cls");
	PrintTitle();
	PrintPlayersInfo();
	DrawGrid(selectedCell);
}

char Grid::SelectCell() {
	std::cout << player[m_turn].name << " | Choose a Number: ";
	char selectedCell;
	std::cin >> selectedCell;
	return selectedCell;
}