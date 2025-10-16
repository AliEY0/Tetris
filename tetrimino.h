#ifndef TETRIMINO_H
#define TETRIMINO_H
#include <stdbool.h>
#include "board.h"
typedef struct
{
    int arr[4][4][4];
    int width[4];
    int height[4];
    int curr_rotation;
    int number_rotations;
    int id;
} Tetrimino;

void draw_tetrimino(Tetrimino *tetrimino);
void init_tetrimino(Tetrimino *tetrimino, int id);
void rotate_tetrimino(Tetrimino *tetrimino, int id);
bool rotate_allowed(Tetrimino *tetrimino, Board *board, int *row, int *column);
#endif
