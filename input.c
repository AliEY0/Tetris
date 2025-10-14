#include <stdio.h>
#include <curses.h>
#include "input.h"

void read_input(){
    
    initscr();
    int ch;
    //noecho();
    cbreak();
    keypad(stdscr, true);
    for (;;) {
        ch = getch();

        if (ch == 'q') break;

        switch (ch) {
            case KEY_UP:
                break;
            case KEY_DOWN:
                break;
            case KEY_LEFT:
                break;
            case KEY_RIGHT:
                break;
            default:
                break;
        }
    }
      
   
   endwin;

}



