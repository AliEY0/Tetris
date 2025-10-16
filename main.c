#include <stdbool.h>
#include <stdio.h>

#include <ncurses.h>
#include "input.h"
#include "tetrimino.h"
#include "board.h"
#include "tetris.h"
#include <unistd.h>

#include <stdlib.h>


void test(){
    int row = 18, col = COLUMN / 2;
    Tetrimino tetrimino;
    init_tetrimino(&tetrimino, 2);

    Board board;
    init_board(&board);
    draw_tetrimino_onboard(&tetrimino, &board, &row, &col);
    refresh();
    usleep(1000000); 
    move_left(&tetrimino, &board, &row, &col);
    refresh();
    usleep(1000000); 
    move_left(&tetrimino, &board, &row, &col);
    refresh();
    usleep(1000000); 
    draw_tetrimino_onboard(&tetrimino, &board, &row, &col);
    refresh();
    usleep(1000000);
}

Tetrimino* generate_tetrimino(int n){
    Tetrimino *tetrimino = malloc(sizeof(Tetrimino)); 
    init_tetrimino(tetrimino, n);
    return tetrimino;
}

int main() {
    srand(time(NULL));
    initscr();
    keypad(stdscr, TRUE);  
    nodelay(stdscr, TRUE); 
    noecho();              
    curs_set(0);           
    int row = 18, col = COLUMN / 2;
    int test = 0;
    Board board;
    init_board(&board);
    for(int i = 0; i< 4; i++){
        for(int j = 0; j < COLUMN - 1; j++){
            board.arr[i][j] = '*';
        }
    }

    for(int j = 0; j < COLUMN - 2; j++){
        board.arr[4][j] = '*';
    }



    while(test<20){
        //test = 9;
        //int n = rand() % 7;
        // n = 1 3 4
        int n = 1;

        Tetrimino *tetrimino = generate_tetrimino(n);
        //rotate_tetrimino(tetrimino, n);
        row = ROW - tetrimino->height[tetrimino->curr_rotation] ;
        if(check_bottom(tetrimino, &board, row, col)==true){
       
        }

            if (tetrimino != NULL) {
                drop_tetrimino(tetrimino, &board, &row, &col);
                free(tetrimino); 
                check_rows(&board, 0);
            }



        //row = 18, 
        col = COLUMN / 2;
        test++;
    }


    //test();
    endwin();
    return 0;
}
