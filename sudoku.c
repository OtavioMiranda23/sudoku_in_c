#include<stdio.h>
#include<stdlib.h>

void printTable(int table[9][9]);
int setNumber(int table[9][9], int row, int column, int value);
int isInvalid(int table[9][9], int row, int column, int value);


int main() {
    int table[9][9] = {
        {5, 3, 0,    0, 7, 0,   0, 0, 0},
        {6, 0, 0,    1, 9, 5,   0, 0, 0},
        {0, 9, 8,    0, 0, 0,   0, 6, 0},
        
        {8, 0, 0,    0, 6, 0,   0, 0, 3},
        {4, 0, 0,    8, 0, 3,   0, 0, 1},
        {7, 0, 0,    0, 2, 0,   0, 0, 6},
        
        {0, 6, 0,    0, 0, 0,   2, 8, 0},
        {0, 0, 0,    4, 1, 9,   0, 0, 5},
        {0, 0, 0,    0, 8, 0,   0, 7, 9}
    };
    printTable(table);
    printf("------------------------\n");
    printf("%d\n", isInvalid(table, 0, 2, 1));



    return 0;
}

void printTable(int table[9][9]) {
    for(int row = 0; row < 9; row++){
        if(row == 3 || row == 6) {
            printf("\n");

        }
        for (int column = 0; column < 9; column++)
        {
            printf("%d", table[row][column]);
            if(column == 2 || column == 5 || column == 9) {
                printf(" ");
            }
            if(column == 8) {
                printf("\n");
            }
        }   
    }
}

int setNumber(int table[9][9], int row, int column, int value) {
    if (table[row][column] != 0) {
        return 0;
    }
    table[row][column] = value;
    return 1;
};

int isInvalid(int table[9][9], int row, int column, int value) {
    //percorrer row
    for (int j = 0; j < 9; j++) {
        if (table[row][j] == value) return 1;
    }
    //percorrer column
    for (int i = 0; i < 9; i++) {
        if(table[i][column] == value) return 1;
    }
    //percorrer quadrados
    int startRow = (row / 3) * 3;
    int startCol = (column / 3);
    for (int i = startRow; i < i + 2 ; i++) {
        for (int j = startCol; j < j + 2; j++) {
            if (table[i][j] == value) return 1;
        }
    } 
    return 0; 
}