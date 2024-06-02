#include <stdio.h>
#include <stdbool.h>

#define SIZE 3
#define X 'X'
#define O 'O'

char board[SIZE][SIZE];

void initBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" ");
        for (int j = 0; j < SIZE; j++) {
            printf("%c", board[i][j]);
            if (j < SIZE - 1) {
                printf(" | ");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

void getIndices(int box, int *row, int *col) {
    *row = (box - 1) / SIZE;
    *col = (box - 1) % SIZE;
}

bool isValid(int box) {
    int row, col;
    getIndices(box, &row, &col);
    return (box >= 1 && box <= SIZE * SIZE && board[row][col] == ' ');
}

void mark(int box, char symbol) {
    int row, col;
    getIndices(box, &row, &col);
    board[row][col] = symbol;
}

bool isWin(char symbol) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true;
        }
    }
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
            return true;
        }
    }
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return true;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return true;
    }
    return false;
}

bool isFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
void playGame() {
    initBoard();
    printBoard();
    int turn = 1;
    while (true) {
        int player = (turn % 2) ? 1 : 2;
        char symbol = (player == 1) ? X : O;
        int box;
        printf("Player %d (%c), enter a box number (1-9): ", player, symbol);
        scanf("%d", &box);
        if (isValid(box)) {
            mark(box, symbol);
            printBoard();
            if (isWin(symbol)) {
                printf("Player %d (%c) wins!\n", player, symbol);
                break;
            }
            if (isFull()) {
                printf("It's a tie!\n");
                break;
            }
            turn++;
        } else {
            printf("Invalid box number. Try again.\n \a");
        }
    }
}

int main() {
    playGame();
    return 0;
}