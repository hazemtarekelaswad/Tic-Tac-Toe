#pragma once

const int NUMS_OF_PLAYERS = 2;
const int GRID_SIZE = 3;

static enum class GameStatus {
	PLAYER1,
	PLAYER2,
	DRAW,
	STILL_PLAYING,
} Status;