#include <stdbool.h>
#include <stdio.h>
#include "board.h"
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#define ROWS 20
#define COLUMN 10

void init_board(Board *board)
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            board->arr[i][j] = '.';
        }
    }
}

void draw_board(Board *board)
{
    clear();

    for (int i = ROW - 1; i >= 0; i--)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            mvaddch(ROW - 1 - i, j, board->arr[i][j]);
        }
    }

    refresh();
}

void lower_row(Board *board, int row) {
    for (int i = row; i < ROWS - 1; i++) {  
        for (int j = 0; j < COLUMN; j++) {
            board->arr[i][j] = board->arr[i + 1][j];
        }
    }

    for (int j = 0; j < COLUMN; j++) {
        board->arr[ROWS - 1][j] = '.';
    }
}
void check_rows(Board *board, int row){
    int i = 0;
    for(i = 0; i < 20; i++){
        bool full = true;
        for(int j = 0; j < COLUMN;j++){
            if(board->arr[i][j] == '.') {
                full = false;
            }

        }

        if(full){
            lower_row(board, i);
            i--;
        }
    }
}
