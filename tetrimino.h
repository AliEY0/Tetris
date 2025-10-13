#ifndef TETRIMINO_H
#define TETRIMINO_H


typedef struct {
    int arr[4][4];
    int width;
    int height;
    int curr_rotation;
    int number_rotations;
} Tetrimino;


void draw_tetrimino(Tetrimino *tetrimino);
void init_tetrimino(Tetrimino *tetrimino, int id); 
void rotate_tetrimino(Tetrimino *tetrimino, int id);
#endif
