#ifndef TETRIS_H
#define TETRIS_H

#include <stdbool.h>
#include "board.h"
#include "tetrimino.h"




void drop_tetrimino(Tetrimino *tetrimino, Board *board, int *row, int *column);

void draw_tetrimino_onboard(Tetrimino *tetrimino, Board *board, int *row, int *column);


bool check_collision(Tetrimino *tetrimino, Board *board, int row, int column);

bool check_bottom(Tetrimino *tetrimino, Board *board, int row, int column);

bool left_right_boundaries(Tetrimino *tetrimino, Board *board, int row, int column);

void drop_by_one(Tetrimino *tetrimino, Board *board, int *row, int *column);

void move_left(Tetrimino *tetrimino, Board *board, int *row, int *column);

void move_right(Tetrimino *tetrimino, Board *board, int *row, int *column);



#endif
