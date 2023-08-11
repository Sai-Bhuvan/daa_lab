#include <stdio.h>
#include <stdbool.h>

#define N 4

void printboard(char board[N][N]) {
    printf("------------------------------\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool issafe(char board[N][N], int row, int col) {
    for (int i = row - 1; i >= 0; i--) {
        if (board[i][col] == 'Q') {
            return false;
        }
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q') {
            return false;
        }
        if (col + (row - i) < N && board[i][col + (row - i)] == 'Q') {
            return false;
        }
    }
    return true;
}

void n_queens(char board[N][N], int i) {
    if (i == N) {
        printboard(board);
        printf("\n");
        return;
    }

    for (int j = 0; j < N; j++) {
        if (issafe(board, i, j)) {
            board[i][j] = 'Q';
            n_queens(board, i + 1);
            board[i][j] = '.'; // backtracking step
        }
    }
}

int main() {
    char board[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = '.';
        }
    }

    n_queens(board, 0);
    return 0;
}
