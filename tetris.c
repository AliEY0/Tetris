#include <stdio.h>
#include "board.h"
#include "tetrimino.h"
#include "tetris.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct{
    int x;
    int y;
} Point;

bool left_right_boundaries(Tetrimino *tetrimino, Board *board, int row, int column){

    
    if(column<0) return false;
    if(column>19) return false;
    //if(!(column+tetrimino->width <= COLUMN)) return false;
    return true;
}

bool check_collision(Tetrimino *tetrimino, Board *board, int row, int column){


    return false;
}

void drop_by_one(Tetrimino *tetrimino, Board *board){
    
}

void move_left(Tetrimino *tetrimino, Board *board, int *row, int *column){
    if(left_right_boundaries(tetrimino,board, *row, *column -1)== false) return;

    printf("testleft\n");

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
    draw_tetrimino_onboard(tetrimino, board, *row, *column-1);
    *column = *column - 1;
}

void draw_tetrimino_onboard(Tetrimino *tetrimino, Board *board, int row, int column){
    //system("clear");
    int check = 0;  
    Point points[4];
    Point p1,p2,p3,p4;
    for(int i = 0; i < tetrimino->height; i++){
        for(int j = 0; j < tetrimino->width; j++){
            if(tetrimino->arr[i][j]){
                board->arr[row + i][column + j] = '*';
                points[check].x = row+i;
                points[check].y=column+j;
                check++;
            }
        }
    }    

    draw_board(board);
    /*for(int i = 0; i < 4; i++){
        board->arr[points[i].x][points[i].y] = '.';
        board->arr[points[i].x-1][points[i].y] = '*';
    }
    sleep(1);
    draw_board(board);
    system("clear");
    */
    //draw_tetrimino_onboard(tetrimino, board, row-1, column);
}

void drop_tetrimino(Tetrimino *tetrimino, Board *board){
    int mid = COLUMN / 2;
    draw_tetrimino_onboard(tetrimino, board, 20 - tetrimino->height, mid );
    
}


