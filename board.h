#ifndef BOARD_H
#define BOARD_H

#define ROW 20
#define COLUMN 10

typedef struct{
    char arr[ROW][COLUMN];
    
} Board;
void init_board(Board *board);
void draw_board(Board *board);

#endif
