#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int VELICINA = 9;

void printPloca(vector<vector<int>>& board) {
    cout << "  ";
    for (int i = 0; i < VELICINA; ++i) {
        cout << i + 1 << " ";
        if ((i + 1) % 3 == 0 && i != VELICINA - 1) {
            cout << "| ";
        }
    }
    cout << endl << " -";
    for (int i = 0; i < VELICINA; ++i) {
        cout << "--";
        if ((i + 1) % 3 == 0 && i != VELICINA - 1) {
            cout << "-";
        }
    }
    cout << endl;
    for (int i = 0; i < VELICINA; ++i) {
        cout << i + 1 << "|";
        for (int j = 0; j < VELICINA; ++j) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0 && j != VELICINA - 1) {
                cout << "| ";
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0 && i != VELICINA - 1) {
            cout << " -";
            for (int j = 0; j < VELICINA; ++j) {
                cout << "--";
                if ((j + 1) % 3 == 0 && j != VELICINA - 1) {
                    cout << "-";
                }
            }
            cout << endl;
        }
    }
}


bool isRowValid(vector<vector<int>>& board, int row) {
    bool used[VELICINA + 1] = { false };
    for (int i = 0; i < VELICINA; ++i) {
        int val = board[row][i];
        if (val == 0) {
            continue;
        }
        if (used[val]) {
            return false;
        }
        used[val] = true;
    }
    return true;
}

bool isColValid(vector<vector<int>>& board, int col) {
    bool used[VELICINA + 1] = { false };
    for (int i = 0; i < VELICINA; ++i) {
        int val = board[i][col];
        if (val == 0) {
            continue;
        }
        if (used[val]) {
            return false;
        }
        used[val] = true;
    }
    return true;
}

bool isBoxValid(vector<vector<int>>& board, int row, int col) {
    bool used[VELICINA + 1] = { false };
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; ++i) {
        for (int j = startCol; j < startCol + 3; ++j) {
            int val = board[i][j];
            if (val == 0) {
                continue;
            }
            if (used[val]) {
                return false;
            }
            used[val] = true;
        }
    }
    return true;
}

bool isValid(vector<vector<int>>& board, int row, int col) {
    return isRowValid(board, row) && isColValid(board, col) && isBoxValid(board, row, col);
}

bool solveSudoku(vector<vector<int>>& board, int row, int col) {
    if (row == VELICINA) {
        return true;
    }
    if (col == VELICINA) {
        return solveSudoku(board, row + 1, 0);
    }
    if (board[row][col] != 0) {
        return solveSudoku(board, row, col + 1);
    }
    for (int val = 1; val <= 9; ++val) {
        board[row][col] = val;
        if (isValid(board, row, col) && solveSudoku(board, row, col + 1)) {
            return true;
        }
    }
    board[row][col] = 0;
    return false;
}

void generisiPlocu(vector<vector<int>>& board) {
    srand(time(NULL));
    int numCells = rand() % 10 + 50;
    for (int i = 0; i < numCells; ++i) {
        int row = rand() % 9;
        int col = rand() % 9;
        int val = rand() % 9 + 1;
        if (board[row][col] != 0) {

            continue;
        }
        board[row][col] = val;
        if (!isValid(board, row, col)) {
            board[row][col] = 0;
        }
    }
}

bool isBoardFull(vector<vector<int>>& board) {
    for (int i = 0; i < VELICINA; ++i) {
        for (int j = 0; j < VELICINA; ++j) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool isBoardValid(vector<vector<int>>& board) {
    for (int i = 0; i < VELICINA; ++i) {
        if (!isRowValid(board, i)) {
            return false;
        }
        if (!isColValid(board, i)) {
            return false;
        }
    }
    for (int i = 0; i < VELICINA; i += 3) {
        for (int j = 0; j < VELICINA; j += 3) {
            if (!isBoxValid(board, i, j)) {
                return false;
            }
        }
    }
    return true;
}

void unosKorisnika(int& row, int& col, int& val) {
    cout << "Unesi red, kolonu i vrijednost (odvojeno razmakom): ";
    cin >> row >> col >> val;
    --row;
    --col;
}

int main() {
    vector<vector<int>> board(VELICINA, vector<int>(VELICINA, 0));
    generisiPlocu(board);
    printPloca(board);
    while (!isBoardFull(board)) {
        int row, col, val;
        unosKorisnika(row, col, val);
        board[row][col] = val;
        if (!isValid(board, row, col)) {
            cout << "Nepravilan potez!" << endl;
            board[row][col] = 0;
        }
        printPloca(board);
    }
    if (isBoardValid(board)) {
        cout << "Cestitamo!" << endl;
    }
    else {
        cout << "Zao mi je, rjesenje je netacno." << endl;
    }
    return 0;
}
