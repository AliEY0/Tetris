#include <stdio.h>
#include "board.h"
#include "tetrimino.h"
#include "tetris.h"
#include <unistd.h>
#include <stdlib.h>
typedef struct{
    int x;
    int y;
} Point;


void check_collision(Tetrimino *tetrimino, Board *board, int row, int column){

}

void drop_by_one(Tetrimino *tetrimino, Board *board){
    
}

void draw_tetrimino_onboard(Tetrimino *tetrimino, Board *board, int row, int column){
    system("clear");
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
    sleep(1);
    for(int i = 0; i < 4; i++){
        board->arr[points[i].x][points[i].y] = '.';
        board->arr[points[i].x-1][points[i].y] = '*';
    }
    system("clear");
    draw_board(board);
}

void drop_tetrimino(Tetrimino *tetrimino, Board *board){
    int mid = COLUMN / 2;
    draw_tetrimino_onboard(tetrimino, board, 20 - tetrimino->height, mid);
}


