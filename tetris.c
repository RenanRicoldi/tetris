#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>

#define clear() printf("\033[H\033[J")
#define ROWS 20
#define COLUMNS 10
#define VOID_CHAR ''

void clear_board(int grid [ROWS][COLUMNS]) {
    for(int row = 0; row < ROWS; row ++) {
        for (int column = 0; column < COLUMNS; column ++) {
            grid[row][column] = 0;
        }
    }
}

void draw_board(int grid [ROWS][COLUMNS]) {
    clear();
    char *position_char = malloc(2 * sizeof(char));
    for(int row = 0; row < ROWS; row ++) {
        printf("<!");
        for (int column = 0; column < COLUMNS; column ++) {
            position_char = " .";

            if(grid[row][column] == 1) {
                position_char = "[]";
            }

            printf("%s", position_char);
        }
        printf("!>\n");
    }

    printf("<!");
    for (int column = 0; column < COLUMNS; column ++) {
        printf("==");
    }
    printf("!>\n  ");

    for (int column = 0; column < COLUMNS; column ++) {
        printf("\\/");
    }

    printf("\n");

    return;
}

int main() {
    int grid [ROWS][COLUMNS];
    int continue_game = 1;
    clear_board(grid);
    while(continue_game) {
        draw_board(grid);
        sleep(1);
        int row = rand() % ROWS;
        int col = rand() % COLUMNS;
        grid[row][col] = 1;
    }
    return 0;
}