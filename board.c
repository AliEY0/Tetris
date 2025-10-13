#include <stdio.h>
#include "board.h"



void init_board(Board *board){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++){
            board->arr[i][j] = '.';
        }
    }
}

void draw_board(Board *board) {
    for (int i = ROW - 1; i >= 0; i--) {  
        for (int j = 0; j < COLUMN; j++) {
            printf("%c", board->arr[i][j]);
        }
        printf("\n");
    }
}

