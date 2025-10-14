#include <stdio.h>
#include "board.h"
#include "tetrimino.h"
#include "tetris.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "input.h"
#include <ncurses.h>

typedef struct{
    int x;
    int y;
} Point;

bool check_bottom(Tetrimino *tetrimino, Board *board, int row, int column) {
    if (!(row >= tetrimino->height - 1)) {
        return false;
    }
    for (int j = 0; j < tetrimino->width; j++) {
        for (int i = 0; i < tetrimino->height; i++) {
            if (tetrimino->arr[i][j]) {
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


bool left_right_boundaries(Tetrimino *tetrimino, Board *board, int row, int column){
    //return true;
    if(column < 0) return false;
    if(column + tetrimino->width > COLUMN) return false; 
    //if(row + tetrimino->height > ROW) return false;    

    for (int i = 0; i < tetrimino->height; i++) {
        for (int j = 0; j < tetrimino->width; j++) {
            if (tetrimino->arr[i][j] && board->arr[row + i][column + j] == '*') {
   //             return false;
            }
        }
    }

    return true;
}

bool check_collision(Tetrimino *tetrimino, Board *board, int row, int column){


    return false;
}

void drop_by_one(Tetrimino *tetrimino, Board *board, int *row, int *column){
    if(check_bottom(tetrimino, board, *row, *column)){
        for(int i = 0; i < tetrimino->height; i++){
            for(int j = 0; j < tetrimino->width; j++){
                if(tetrimino->arr[i][j]){
                    board->arr[*row + i][*column + j] = '.';
                }
            }
        }
        *row = *row -  1 ;
        draw_tetrimino_onboard(tetrimino, board, row, column);
    }
}

void move_right(Tetrimino *tetrimino, Board *board, int *row, int *column){
    if(left_right_boundaries(tetrimino,board, *row, *column +1)== false) return;


    for(int i = 0; i < tetrimino->height; i++){
        for(int j = 0;j < tetrimino->width; j++){
            if(tetrimino->arr[i][j]){
            board->arr[*row+i][*column+j] = '.'; 
            }
        }
    }
    

    for(int i = 0; i < tetrimino->height; i++){
        for(int j = 0;j < tetrimino->width; j++){
            if(tetrimino->arr[i][j]){
//            board->arr[row+i][column+j - 1] = '*'; 
            }
        }
    }
    *column = *column + 1;
    draw_tetrimino_onboard(tetrimino, board, row, column);
}
void move_left(Tetrimino *tetrimino, Board *board, int *row, int *column){
    if(left_right_boundaries(tetrimino,board, *row, *column -1)== false) return;

    //printf("testleft\n");

    for(int i = 0; i < tetrimino->height; i++){
        for(int j = 0;j < tetrimino->width; j++){
            if(tetrimino->arr[i][j]){
            board->arr[*row+i][*column+j] = '.'; 
            }
        }
    }
    

    *column = *column - 1;
    draw_tetrimino_onboard(tetrimino, board, row, column);
}

void draw_tetrimino_onboard(Tetrimino *tetrimino, Board *board, int *row, int *column){
    clear();
    

    for(int i = 0; i < tetrimino->height; i++){
        for(int j = 0; j < tetrimino->width; j++){
            if(tetrimino->arr[i][j]){
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

void drop_tetrimino(Tetrimino *tetrimino, Board *board, int *row, int *column) {
    int delay = 150000;
    while(1) {
        int val = read_input(); 

        switch(val) {
            case 2: // L
                move_left(tetrimino, board, row, column);
                break;
            case 3: // R
                move_right(tetrimino, board, row, column);
                break;
            case 4: // F
                drop_by_one(tetrimino, board, row, column);
                break;
            case 5: // E
                rotate_tetrimino(tetrimino, tetrimino->id);
                draw_tetrimino_onboard(tetrimino, board, row, column);
                break;
            case -1: // Q
                endwin();
                return;
        }
        if(check_bottom(tetrimino, board, *row, *column)){
            drop_by_one(tetrimino, board, row, column);
        } else {
            //return;
        }

        usleep(delay);
    }
}
