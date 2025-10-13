#ifndef TETRIS_H
#define TETRIS_H


#include "board.h"
#include "tetrimino.h"




void drop_tetrimino(Tetrimino *tetrimino, Board *board);

void draw_tetrimino_onboard(Tetrimino *tetrimino, Board *board, int row, int column);

void check_collision(Tetrimino *tetrimino, Board *board, int row, int column);

void left_right_boundaries(Tetrimino *tetrimino, Board *board);

void drop_by_one(Tetrimino *tetrimino, Board *board);


#endif
