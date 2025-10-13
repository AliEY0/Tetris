#include <stdio.h>


#include "tetrimino.h"
#include "board.h"
#include "tetris.h"

void test(int id){
    Tetrimino O;
    init_tetrimino(&O, id);
    for(int i = 0; i < O.number_rotations;i++){
        draw_tetrimino(&O);
        printf("\n");
        rotate_tetrimino(&O,id);
        printf("\n");
        
    }
}


int main() {
    //for(int i = 0; i < 7; i++){
    //    test(i); 
    //}
    int n = 2;
    test(n);
    printf("---\n");


    Board board;
    init_board(&board);
//    draw_board(&board);
//
    Tetrimino O;
    init_tetrimino(&O, n);
/*    rotate_tetrimino(&O, n);
    drop_tetrimino(&O, &board);
    printf("---\n");
    rotate_tetrimino(&O, n);
    drop_tetrimino(&O, &board);
    printf("---\n");
    rotate_tetrimino(&O, n);
    drop_tetrimino(&O, &board);
    printf("---\n");
    rotate_tetrimino(&O, n);
  */  drop_tetrimino(&O, &board);
    drop_tetrimino(&O, &board);
    drop_tetrimino(&O, &board);
    return 0;
}


