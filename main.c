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


int main() {
    srand(time(NULL));
    int n = rand() % 8;
    initscr();
    keypad(stdscr, TRUE);  
    nodelay(stdscr, TRUE); 
    noecho();              
    curs_set(0);           

    int row = 18, col = COLUMN / 2;
    Tetrimino tetrimino;
    init_tetrimino(&tetrimino, n);

    Board board;
    init_board(&board);

    drop_tetrimino(&tetrimino, &board, &row, &col);

    //test();
    endwin();
    return 0;
}
