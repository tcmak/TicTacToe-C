/*
 * Game.h
 *
 *  Created on: 7 May 2017
 *      Author: stevenmak
 */

#ifndef GAME_H_
#define GAME_H_

#ifdef __cplusplus
extern "C"{
#endif

typedef int (*MoveOp)(const void * self, char player);
typedef char (*WinnerOp)(const void * self);

typedef struct _game {

	char board[10];
	MoveOp move;
	WinnerOp getWinner;

} Game ;

extern Game newGame(const char*);
extern Game newGameOfNextRound(const char*, int, char);

#ifdef __cplusplus
}
#endif

#endif /* GAME_H_ */
