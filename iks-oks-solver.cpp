#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void displayBoard(char board[3][3]) {
    cout << "    1   2   3\n";
    cout << "  -------------\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n";
        cout << "  -------------\n";
    }
}

void displayNumberedBoard() {
    char numberedBoard[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
    displayBoard(numberedBoard);
}


bool checkWin(char board[3][3], char symbol) {
    // Provjera pobjede u redovima
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
            return true;
    }

    // Provjera pobjede u kolonama
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
            return true;
    }

    // Provjera pobjede na dijagonalama
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
        return true;

    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
        return true;

    return false;
}

void makeComputerMove(char board[3][3], char computerSymbol, char playerSymbol) {
    // Provjera pobjede računara
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = computerSymbol;
                if (checkWin(board, computerSymbol))
                    return;
                else
                    board[i][j] = ' ';
            }
        }
    }

    // Provjera pobjede igrača i blokiranje
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = playerSymbol;
                if (checkWin(board, playerSymbol)) {
                    board[i][j] = computerSymbol;
                    return;
                }
                else
                    board[i][j] = ' ';
            }
        }
    }

    // Slučajno odabiranje slobodnog polja
    srand(time(0));
    int num;
    do {
        num = rand() % 9 + 1;
    } while (board[(num - 1) / 3][(num - 1) % 3] != ' ');

    board[(num - 1) / 3][(num - 1) % 3] = computerSymbol;
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char playerSymbol, computerSymbol;

    cout << "Dobrodošli u Tic-Tac-Toe!" << endl;

    cout << "Izaberite simbol (X ili O): ";
    cin >> playerSymbol;

    playerSymbol = toupper(playerSymbol); // Pretvara unos u veliko slovo

    while (playerSymbol != 'X' && playerSymbol != 'O') {
        cout << "Neispravan unos. Izaberite simbol (X ili O): ";
        cin >> playerSymbol;
        playerSymbol = toupper(playerSymbol);
    }

    if (playerSymbol == 'X')
        computerSymbol = 'O';
    else
        computerSymbol = 'X';

    cout << "Odabrali ste simbol: " << playerSymbol << endl;

    displayNumberedBoard();

    int num;
    int moves = 0;

    while (moves < 9) {
        cout << "Unesite broj polja (1-9): ";
        cin >> num;

        if (num < 1 || num > 9) {
            cout << "Neispravan unos. Pokušajte ponovo." << endl;
            continue;
        }

        int row = (num - 1) / 3;
        int col = (num - 1) % 3;

        if (board[row][col] != ' ') {
            cout << "Polje je već zauzeto. Pokušajte ponovo." << endl;
            continue;
        }

        board[row][col] = playerSymbol;
        displayBoard(board);

        if (checkWin(board, playerSymbol)) {
            cout << "Pobjeda! Čestitamo!" << endl;
            break;
        }

        moves++;

        if (moves == 9) {
            cout << "Neriješeno. Igra je završena." << endl;
            break;
        }

        cout << "Računar je na potezu..." << endl;
        makeComputerMove(board, computerSymbol, playerSymbol);
        displayBoard(board);

        if (checkWin(board, computerSymbol)) {
            cout << "Računar je pobijedio. Pokušajte ponovo!" << endl;
            break;
        }

        moves++;
    }

    return 0;
}