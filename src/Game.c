/*
 * Game.c
 *
 *  Created on: 9 May 2017
 *      Author: stevenmak
 */

#include <Game.h>
#include <string.h>

static Game play(Game* game, int i, char player) {
	return newGameOfNextRound(game->board, i, player);
}

static int move(const void * self, char player) {
	Game* game = (Game*) self;

	// find a cell that can win
	for (int i = 0; i < 9; i++) {
		if (game->board[i] == '-') {
			Game gameNextMove = play(game, i, player);
			if (gameNextMove.getWinner(&gameNextMove) == player)
				return i;
		}
	}

	// find an empty cell
	for (int i = 0; i < 9; i++) {
		if (game->board[i] == '-')
			return i;
	}

	return -1;
}

static char getWinner(const void * self) {
	Game* game = (Game*) self;

	if (game->board[0] != '-'
        && game->board[0] == game->board[1]
        && game->board[1] == game->board[2])
		return game->board[0];
	if (game->board[3] != '-'
        && game->board[3] == game->board[4]
        && game->board[4] == game->board[5])
		return game->board[3];
	if (game->board[6] != '-'
        && game->board[6] == game->board[7]
        && game->board[7] == game->board[8])
		return game->board[6];
	return '-';
}

Game newGame(const char* s) {
	Game game;
	strcpy(game.board, s);
	game.move = move;
	game.getWinner = getWinner;
	return game;
}

Game newGameOfNextRound(const char* s, int position, char player) {
	Game game;
	strcpy(game.board, s);
	game.move = move;
	game.getWinner = getWinner;
	game.board[position] = player;
	return game;
}

