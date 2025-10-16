#include <stdio.h>
#include "board.h"
#include "tetrimino.h"
#include "tetris.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "input.h"
#include <ncurses.h>

typedef struct {
    int x;
    int y;
} Point;

bool check_bottom(Tetrimino *tetrimino, Board *board, int row, int column) {
    int h = tetrimino->height[tetrimino->curr_rotation];
    int w = tetrimino->width[tetrimino->curr_rotation];

    if (!(row >= 0)) {
        //return false;
    }

    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            if (tetrimino->arr[tetrimino->curr_rotation][i][j]) {
                int below_row = row + i - 1;
                int below_col = column + j;

                if (below_row < 0) {
                    return false;
                }
                if (board->arr[below_row][below_col] == '*') {
                    return false;
                }
                break;
            }
        }
    }

    return true;
}
bool top_reached(){
    
}

bool left_right_boundaries(Tetrimino *tetrimino, Board *board, int row, int column) {
    int h = tetrimino->height[tetrimino->curr_rotation];
    int w = tetrimino->width[tetrimino->curr_rotation];

    if (column < 0) return false;
    if (column + w > COLUMN) return false;

    /*for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (tetrimino->arr[tetrimino->curr_rotation][i][j] &&
                board->arr[row + i][column + j] == '*') {
                 return false;
            }
        }
    }*/

    return true;
}

bool check_collision(Tetrimino *tetrimino, Board *board, int row, int column) {
    return false;
}

void draw_tetrimino_onboard(Tetrimino *tetrimino, Board *board, int *row, int *column) {
    clear();
    int r = tetrimino->curr_rotation;
    int h = tetrimino->height[r];
    int w = tetrimino->width[r];

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (tetrimino->arr[r][i][j]) {
                board->arr[*row + i][*column + j] = '*';
            }
        }
    }

    for (int i = ROW - 1; i >= 0; i--) {
        for (int j = 0; j < COLUMN; j++) {
            mvaddch(ROW - 1 - i, j, board->arr[i][j]);
        }
    }

    refresh();
}

void drop_by_one(Tetrimino *tetrimino, Board *board, int *row, int *column) {
    int r = tetrimino->curr_rotation;
    int h = tetrimino->height[r];
    int w = tetrimino->width[r];

    if (check_bottom(tetrimino, board, *row, *column)) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (tetrimino->arr[r][i][j]) {
                    board->arr[*row + i][*column + j] = '.';
                }
            }
        }
        *row = *row - 1;
        draw_tetrimino_onboard(tetrimino, board, row, column);
    }
}

void move_right(Tetrimino *tetrimino, Board *board, int *row, int *column) {
    int r = tetrimino->curr_rotation;
    int h = tetrimino->height[r];
    int w = tetrimino->width[r];

    if (left_right_boundaries(tetrimino, board, *row, *column + 1) == false) return;
    if(board->arr[*row][*column+w] =='*') return;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (tetrimino->arr[r][i][j]) {
                board->arr[*row + i][*column + j] = '.';
            }
        }
    }

    *column = *column + 1;
    draw_tetrimino_onboard(tetrimino, board, row, column);
}

void move_left(Tetrimino *tetrimino, Board *board, int *row, int *column) {
    int r = tetrimino->curr_rotation;
    int h = tetrimino->height[r];
    int w = tetrimino->width[r];

    if (left_right_boundaries(tetrimino, board, *row, *column - 1) == false) return;
    if(board->arr[*row][*column-1] =='*') return;
    

    printf("testleft\n");

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (tetrimino->arr[r][i][j]) {
                board->arr[*row + i][*column + j] = '.';
            }
        }
    }

    *column = *column - 1;
    draw_tetrimino_onboard(tetrimino, board, row, column);
}

void drop_tetrimino(Tetrimino *tetrimino, Board *board, int *row, int *column) {
    int delay = 150000;
    while (1) {
        int val = read_input();

        switch (val) {
            case 2:
                move_left(tetrimino, board, row, column);
                break;
            case 3:
                move_right(tetrimino, board, row, column);
                break;
            case 4:
                drop_by_one(tetrimino, board, row, column);
                break;
            case 5:
                for(int i = 0; i < tetrimino->height[tetrimino->curr_rotation]; i++){
                    for(int j = 0; j < tetrimino->width[tetrimino->curr_rotation]; j++){
                        if(tetrimino->arr[tetrimino->curr_rotation][i][j]){
                            board->arr[*row+i][*column+j] = '.';

                        }
                    }
                }
                if(rotate_allowed(tetrimino, board, row, column)){
                    rotate_tetrimino(tetrimino, tetrimino->id);
                }
                draw_tetrimino_onboard(tetrimino, board, row, column);
                break;
            case -1:
                endwin();
                return;
        }

        if (check_bottom(tetrimino, board, *row, *column)) {
            drop_by_one(tetrimino, board, row, column);
        } else {
            return;
        }

        usleep(delay);
    }
}

