#include <iostream>
#include <vector>
#include <cmath>

void printBoard(const std::vector<int>& placement) {
    int N = placement.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (placement[i] == j) {
                std::cout << " Q ";
            } else {
                std::cout << " . ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

bool isSafe(const std::vector<int>& placement, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (placement[i] == col || std::abs(placement[i] - col) == row - i) {
            return false;
        }
    }
    return true;
}

void solveNQueens(std::vector<int>& placement, int row, int N) {
    if (row == N) {
        printBoard(placement);
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(placement, row, col)) {
            placement[row] = col;
            solveNQueens(placement, row + 1, N);
            placement[row] = -1; // Backtrack
        }
    }
}

void nQueens(int N) {
    std::vector<int> placement(N, -1);
    solveNQueens(placement, 0, N);
}

int main() {
    int N;
    std::cout << "Enter the value of N for N-Queens: ";
    std::cin >> N;

    nQueens(N);

    return 0;
}

