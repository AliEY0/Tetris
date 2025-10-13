#include <stdio.h>
#include "tetrimino.h"
#include <string.h>


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


void init_tetrimino(Tetrimino *tetrimino, int id){
    memset(tetrimino->arr, 0, sizeof(tetrimino->arr));
    tetrimino->curr_rotation = 0;
    
    if(id == 0){
        tetrimino->number_rotations = 0;
    } else if(id == 1 || id > 4){
        tetrimino->number_rotations = 2;
    } else {
        tetrimino->number_rotations = 4;
    }


    switch (id) {
        case 0:{ // O
            int temp_arr[4][2] = {
                {0,0}, {0,1}, {1,0}, {1,1}
            };
            tetrimino->width = 2;
            tetrimino->height = 2;
            for(int i = 0; i < 4;i++){
                int x = temp_arr[i][0];
                int y = temp_arr[i][1];
                tetrimino->arr[x][y] = 1;
            }
   
            break;
            };
   case 1: { // I 
            int temp_arr[4][2] = {
                {0,0}, {1,0}, {2,0}, {3,0}
            };
            tetrimino->width = 1;
            tetrimino->height = 4;
            for(int i = 0; i < 4; i++){
                int x = temp_arr[i][0];
                int y = temp_arr[i][1];
                tetrimino->arr[x][y] = 1;
            }
            break;
        }

        case 2: { // T 
            int temp_arr[4][2] = {
                {0,1}, {1,0}, {1,1}, {1,2}
            };
            tetrimino->width = 3;
            tetrimino->height = 2;
            for(int i = 0; i < 4; i++){
                int x = temp_arr[i][0];
                int y = temp_arr[i][1];
                tetrimino->arr[x][y] = 1;
            }
            break;
        }

        case 3: { // L
            int temp_arr[4][2] = {
                {0,0}, {1,0}, {2,0}, {2,1}
            };
            tetrimino->width = 2;
            tetrimino->height = 3;
            for(int i = 0; i < 4; i++){
                int x = temp_arr[i][0];
                int y = temp_arr[i][1];
                tetrimino->arr[x][y] = 1;
            }
            break;
        }

        case 4: { // J
            int temp_arr[4][2] = {
                {0,1}, {1,1}, {2,1}, {2,0}
            };
            tetrimino->width = 2;
            tetrimino->height = 3;
            for(int i = 0; i < 4; i++){
                int x = temp_arr[i][0];
                int y = temp_arr[i][1];
                tetrimino->arr[x][y] = 1;
            }
            break;
        }

        case 5: { // S
            int temp_arr[4][2] = {
                {0,1}, {0,2}, {1,0}, {1,1}
            };
            tetrimino->width = 3;
            tetrimino->height = 2;
            for(int i = 0; i < 4; i++){
                int x = temp_arr[i][0];
                int y = temp_arr[i][1];
                tetrimino->arr[x][y] = 1;
            }
            break;
        }

        case 6: { // Z
            int temp_arr[4][2] = {
                {0,0}, {0,1}, {1,1}, {1,2}
            };
            tetrimino->width = 3;
            tetrimino->height = 2;
            for(int i = 0; i < 4; i++){
                int x = temp_arr[i][0];
                int y = temp_arr[i][1];
                tetrimino->arr[x][y] = 1;
            }
            break;
        }

    }
}
void rotate_tetrimino(Tetrimino *tetrimino, int id) {
    int temp[4][4] = {0};
    if (id == 0) return;

    // Rotatie: 90° rechts (clockwise)
    for (int i = 0; i < tetrimino->height; i++) {
        for (int j = 0; j < tetrimino->width; j++) {
            temp[j][tetrimino->height - 1 - i] = tetrimino->arr[i][j];
        }
    }

    // Kopieer terug naar originele array
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tetrimino->arr[i][j] = temp[i][j];
        }
    }

    // Wissel width en height
    int tmp = tetrimino->width;
    tetrimino->width = tetrimino->height;
    tetrimino->height = tmp;
}

