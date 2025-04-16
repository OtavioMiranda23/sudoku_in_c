#include<stdio.h>
#include<stdlib.h>

void printTable(int table[9][9]);
int setNumber(int table[9][9], int row, int column, int value);
int isValid(int table[9][9], int row, int column, int value);
int solved(int table[9][9], int row, int column);
int isGameOver(int table[9][9]);

int main() {
    int table[9][9] = {
        {0, 0, 5,    1, 0, 0,   0, 9, 4},
        {3, 4, 1,    8, 5, 0,   0, 2, 0},
        {0, 9, 8,    0, 0, 0,   0, 1, 0},
        
        {2, 0, 0,    0, 0, 0,   9, 7, 3},
        {0, 0, 7,    0, 3, 0,   0, 4, 8},
        {0, 0, 0,    0, 0, 8,   0, 0, 6},
        
        {0, 0, 2,    0, 0, 6,   5, 3, 0},
        {0, 0, 0,    7, 0, 5,   0, 0, 0},
        {0, 6, 4,    3, 0, 0,   0, 0, 9}
    };
    printTable(table);
    printf("------------------------\n");
    solved(table, 0, 0);
    printTable(table);
    
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


int isValid(int table[9][9], int row, int column, int value) {
    //percorrer row
    for (int j = 0; j < 9; j++) {
        if (table[row][j] == value) return 0;
    }
    //percorrer column
    for (int i = 0; i < 9; i++) {
        if(table[i][column] == value) return 0;
    }
    //percorrer quadrados
    int startRow = (row / 3) * 3;
    int startCol = (column / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (table[i][j] == value) return 0;
        }
    } 
    return 1; 
}

int solved(int table[9][9], int row, int column) {
    //verifica se a linha chegou ao fim, terminando o jogo
    if (row == 9) return 1;
    //vericia se a coluna chegou ao fim, aumentando o valor da linha
    if (column == 9) return solved(table, row+1, 0);
    //verifica se o valor do vetor não existe, andando uma coluna
    if (table[row][column] != 0) {
        return solved(table, row, column+1);
    } else {
        //passando por isso, cria os palpites
        for (int guess = 1; guess < 10; guess++) {
            //se for valido, assinala
            if (isValid(table, row, column, guess)) {
                table[row][column] = guess;
                //verifica se foi resolvido para sair da funcao, senao assinala zero e continua o loop
                if (solved(table, row, column+1) == 1) return 1;
                table[row][column] = 0;
            } 
        }
        return 0;
    }    
}