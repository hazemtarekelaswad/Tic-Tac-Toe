#include <iostream>
#include <string>
#include "Constants.h"
#include "Grid.h"

Grid::Grid(const std::string& title) : m_title(title), m_turn(0) {
	
	// Initialize grid cells with numbers from 1 to 9
	char cellNums = '1';
	for (int i = 0; i < GRID_SIZE; ++i)
		for (int j = 0; j < GRID_SIZE; ++j)
			m_cell[i][j] = cellNums++;

	// Initilize default name to "Player 1" and "Player 2"
	// Initilize default symbols to "X" and "O"
	for (int i = 0; i < NUMS_OF_PLAYERS; ++i) {
		m_player[i].name = "Player ";
		m_player[i].symbol = 'X' - i * 9;
	}
}

void Grid::PrintTitle() const{

	// "PrintBorder" Closure creates borders that fit with title length
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

	for (int i = 0; i < NUMS_OF_PLAYERS; ++i) {
		std::cout << "Player " << i + 1 << " Name: ";
		std::cin >> m_player[i].name;
		std::cout << "Symbol: ";
		std::cin >> m_player[i].symbol;

		// Assures the chosen symbol is a letter not a number
		while (m_player[i].symbol >= '0' && m_player[i].symbol <= '9') {
			std::cout << "Please, choose a letter symbol: ";
			std::cin >> m_player[i].symbol;
		}

		// Assures that Player 2 symbol is different from Player 1's
		while (i == NUMS_OF_PLAYERS - 1 && m_player[i].symbol == m_player[i - 1].symbol) {
			std::cout << "Please, choose another symbol: ";
			std::cin >> m_player[i].symbol;
		}

		std::cout << '\n';
	}

}

void Grid::PrintPlayersInfo() const {
	for (int i = 0; i < NUMS_OF_PLAYERS; ++i) {
		std::cout << m_player[i].name << " (" << m_player[i].symbol << ")";
		if(i != NUMS_OF_PLAYERS - 1)
			std::cout << "    Vs.    ";
	}
	std::cout << "\n\n";
}


void Grid::DrawGrid(int selectedCell) {
	/*
		------------------
		     |     |     |
		  1  |  2  |  3  |
		     |     |     |
		------------------
			 |     |     |
		  4  |  5  |  6  |
			 |     |     |
		------------------
			 |     |     |
		  7  |  8  |  9  |
			 |     |     |
		------------------
	*/

	std::cout << "------------------\n";
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			for (int k = 0; k < GRID_SIZE; ++k) {
				if (j == 1) {
					if (m_cell[i][k] == selectedCell + 48) {	// To change int to char in order to compare correctly
						m_cell[i][k] = m_player[m_turn].symbol;
						AdvancePlayer();
					}
					std::cout << "  " << m_cell[i][k] << "  ";
				}
				else
					std::cout << "     ";
				std::cout << '|';
			}
			std::cout << '\n';
		}
		std::cout << "------------------\n";
	}
	std::cout << '\n';
}

void Grid::UpdateGrid(int selectedCell) {
	system("cls");
	PrintTitle();
	PrintPlayersInfo();
	DrawGrid(selectedCell);
}

int Grid::SelectCell() const {
	std::cout << m_player[m_turn].name << " | Choose a Number: ";
	int selectedCell;
	std::cin >> selectedCell;

	// Checks for valid inputs, numbers from 1 to 9
	while (std::cin.fail()) {
		std::cout << m_player[m_turn].name << " | Choose a Number not a letter: ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> selectedCell;
	}
	return selectedCell;
}

GameStatus Grid::GetGameStatus() {

	// Checks for columns and rows similarities
	for (int i = 0; i < GRID_SIZE; ++i) {
		if (m_cell[i][0] == m_cell[i][1] && m_cell[i][1] == m_cell[i][2] ||
			m_cell[0][i] == m_cell[1][i] && m_cell[1][i] == m_cell[2][i]) {
			AdvancePlayer();
			return static_cast<GameStatus>(m_turn);
		}
	}

	// Checks for Diagonals similarities
	if (m_cell[0][0] == m_cell[1][1] && m_cell[1][1] == m_cell[2][2] ||
		m_cell[0][2] == m_cell[1][1] && m_cell[1][1] == m_cell[2][0]) {
		AdvancePlayer();
		return static_cast<GameStatus>(m_turn);
	}

	// The game ends DRAW if the grid is full of symbols without any matching happens
	if (IsFull()) {
		AdvancePlayer();
		return GameStatus::DRAW;
	}

	// Else, then the game is still proceeding
	return GameStatus::STILL_PLAYING;
}

void Grid::AdvancePlayer() {
	m_turn ^= 1;
}

bool Grid::IsFull() const {
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			if (m_cell[i][j] >= '1' && m_cell[i][j] <= '9')
				return false;
		}
	}
	return true;
}