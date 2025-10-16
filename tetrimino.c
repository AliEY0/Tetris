#include <stdio.h>
#include "board.h"
#include "tetrimino.h"
#include <string.h>
#include "tetris.h"
/*
void draw_tetrimino(Tetrimino *tetrimino){
    for(int i = 0; i < tetrimino->height; i++){
        for(int j = 0; j < tetrimino->width; j++){
            if(tetrimino->arr[i][j] == 1){
                printf("*");
            }else{
                printf(".");
            }
        }
        printf("\n");
    }
    
}
*/

void init_tetrimino(Tetrimino *t, int id) {
    memset(t, 0, sizeof(Tetrimino));
    t->curr_rotation = 0;
    t->id = id;

    if (id == 0) t->number_rotations = 1;           
    else if (id == 1 || id > 4) t->number_rotations = 2; 
    else t->number_rotations = 4;                   
    if(id==2)t->number_rotations = 4;
    switch (id) {
        case 0: // O
            for (int r = 0; r < 1; r++) {
                int temp[4][2] = {{0,0},{0,1},{1,0},{1,1}};
                t->width[r] = 2; t->height[r] = 2;
                for (int i = 0; i < 4; i++)
                    t->arr[r][temp[i][0]][temp[i][1]] = 1;
            }
            break;

        case 1:{ // I
            int temp0[4][2] = {{0,0},{1,0},{2,0},{3,0}};
            t->width[0] = 1; t->height[0] = 4;
            for (int i = 0; i < 4; i++)
                t->arr[0][temp0[i][0]][temp0[i][1]] = 1;

            int temp1[4][2] = {{0,0},{0,1},{0,2},{0,3}};
            t->width[1] = 4; t->height[1] = 1;
            for (int i = 0; i < 4; i++)
                t->arr[1][temp1[i][0]][temp1[i][1]] = 1;
            break;
               }
        case 2: // T
        {
            int rot[4][4][2] = {
                {{0,1},{1,0},{1,1},{1,2}},   
                {{0,0},{1,0},{1,1},{2,0}},   
                {{0,0},{0,1},{0,2},{1,1}},   
                {{0,1},{1,0},{1,1},{2,1}}    
             };
            int dims[4][2] = {{3,2},{2,3},{3,2},{2,3}};
            for (int r = 0; r < 4; r++) {
                t->width[r] = dims[r][0];
                t->height[r] = dims[r][1];
                for (int i = 0; i < 4; i++)
                    t->arr[r][rot[r][i][0]][rot[r][i][1]] = 1;
            }

        } break;

        case 3: // L
        {
            int rot[4][4][2] = {
                {{0,0},{1,0},{2,0},{2,1}},
                {{1,0},{1,1},{0,2},{1,2}},
                {{0,0},{0,1},{1,1},{2,1}},
                {{0,0},{0,1},{0,2},{1,0}}
            };
            int dims[4][2] = {{2,3},{3,2},{2,3},{3,2}};
            for (int r = 0; r < 4; r++) {
                t->width[r] = dims[r][0];
                t->height[r] = dims[r][1];
                for (int i = 0; i < 4; i++)
                    t->arr[r][rot[r][i][0]][rot[r][i][1]] = 1;
            }
        } break;

        case 4: // J
        {
            int rot[4][4][2] = {
                {{0,1},{1,1},{2,1},{2,0}},
                {{0,0},{0,1},{0,2},{1,2}},
                {{0,0},{0,1},{1,0},{2,0}},
                {{0,0},{1,0},{1,1},{1,2}}
            };
            int dims[4][2] = {{2,3},{3,2},{2,3},{3,2}};
            for (int r = 0; r < 4; r++) {
                t->width[r] = dims[r][0];
                t->height[r] = dims[r][1];
                for (int i = 0; i < 4; i++)
                    t->arr[r][rot[r][i][0]][rot[r][i][1]] = 1;
            }
        } break;

        case 5: // S
        {
            int rot[2][4][2] = {
                {{0,1},{0,2},{1,0},{1,1}},
                {{0,0},{1,0},{1,1},{2,1}}
            };
            int dims[2][2] = {{3,2},{2,3}};
            for (int r = 0; r < 2; r++) {
                t->width[r] = dims[r][0];
                t->height[r] = dims[r][1];
                for (int i = 0; i < 4; i++)
                    t->arr[r][rot[r][i][0]][rot[r][i][1]] = 1;
            }
        } break;

        case 6: // Z
        {
            int rot[2][4][2] = {
                {{0,0},{0,1},{1,1},{1,2}},
                {{0,1},{1,0},{1,1},{2,0}}
            };
            int dims[2][2] = {{3,2},{2,3}};
            for (int r = 0; r < 2; r++) {
                t->width[r] = dims[r][0];
                t->height[r] = dims[r][1];
                for (int i = 0; i < 4; i++)
                    t->arr[r][rot[r][i][0]][rot[r][i][1]] = 1;
            }
        } break;
    }
}

bool rotate_allowed(Tetrimino *tetrimino, Board *board, int *row, int *column){
    Tetrimino cc = *tetrimino;
    rotate_tetrimino(&cc, cc.id);
    if(*column + cc.width[cc.curr_rotation] > COLUMN) return false;
    if(left_right_boundaries(&cc, board, *row, *column) == false){
        return false;
    }

  /*  for(int i = 0; i < tetrimino[tetrimino->curr_rotation]->height[tetrimino->curr_rotation]; i++){

        for(int j = 0; j < tetrimino->width; j++){
            if(tetrimino->arr[i][j]){
                
            }
        }
    }
    */return true;
}
void rotate_tetrimino(Tetrimino *t, int id) {
    t->curr_rotation = (t->curr_rotation + 1) % t->number_rotations;
}

