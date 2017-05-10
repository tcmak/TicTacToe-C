/*
 * GameTests.cpp
 *
 *  Created on: 7 May 2017
 *      Author: stevenmak
 */

#include <Game.h>
#include "CppUTest/TestHarness.h"

TEST_GROUP(Game) {
	void setup() {
	}

	void teardown() {
	}
};

TEST(Game, DefaultMove) {
	Game game = newGame("XOXOX-OXO");
	CHECK_EQUAL(5, game.move(&game, 'X'));

	game = newGame("XOXOXOOX-");
	CHECK_EQUAL(8, game.move(&game, 'O'));

	game = newGame("---------");
	CHECK_EQUAL(0, game.move(&game, 'X'));

	game = newGame("XXXXXXXXX");
	CHECK_EQUAL(-1, game.move(&game, 'X'));
}

TEST(Game, FindWinningMove) {
	Game game = newGame("XO-XX-OOX");
	CHECK_EQUAL(5, game.move(&game, 'X'));
}

TEST(Game, WinConditions) {
	Game game = newGame("---XXX---");
	CHECK_EQUAL('X', game.getWinner(&game));

	game = newGame("------OOO");
	CHECK_EQUAL('O', game.getWinner(&game));

	game = newGame("YYY------");
	CHECK_EQUAL('Y', game.getWinner(&game));
}
