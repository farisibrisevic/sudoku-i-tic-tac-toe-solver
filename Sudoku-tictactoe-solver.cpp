#include <iostream>
#include <stdlib.h>

using namespace std;

char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char player = 'X';
int n;

void draw_board() {
    //system("clear");
    cout << "\n\n\tTic Tac Toe\n\n";

    for (int i = 0; i < 3; i++) {
        cout << "\t\t";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void player_turn() {
    int choice;
    cout << "Player " << player << ", enter a number: ";
    cin >> choice;

    switch (choice) {
    case 1:
        if (board[0][0] == '1') {
            board[0][0] = player;
        }
        else {
            cout << "Invalid move!";
            player_turn();
        }
        break;
    case 2:
        if (board[0][1] == '2') {
            board[0][1] = player;
        }
        else {
            cout << "Invalid move!";
            player_turn();
        }
        break;
    case 3:
        if (board[0][2] == '3') {
            board[0][2] = player;
        }
        else {
            cout << "Invalid move!";
            player_turn();
        }
        break;
    case 4:
        if (board[1][0] == '4') {
            board[1][0] = player;
        }
        else {
            cout << "Invalid move!";
            player_turn();
        }
        break;
    case 5:
        if (board[1][1] == '5') {
            board[1][1] = player;
        }
        else {
            cout << "Invalid move!";
            player_turn();
        }
        break;
    case 6:
        if (board[1][2] == '6') {
            board[1][2] = player;
        }
        else {
            cout << "Invalid move!";
            player_turn();
        }
        break;
    case 7:
        if (board[2][0] == '7') {
            board[2][0] = player;
        }
        else {
            cout << "Invalid move!";
            player_turn();
        }
        break;
    case 8:
        if (board[2][1] == '8') {
            board[2][1] = player;
        }
        else {
            cout << "Invalid move!";
            player_turn();
        }
        break;
    case 9:
        if (board[2][2] == '9') {
            board[2][2] = player;
        }
        else {
            cout << "Invalid move!";
            player_turn();
        }
        break;
    default:
        cout << "Invalid move!";
        player_turn();
        break;
    }
}

bool game_over() {
    // Check for win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return
            true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    // Check for tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;

}

void switch_player() {
    if (player == 'X') {
        player = 'O';
    }
    else {
        player = 'X';
    }
}

int main() {
    draw_board();

    while (!game_over()) {
        player_turn();
        draw_board();
        switch_player();
    }

    cout << "Game over!" << endl;

    if (n == 10) {
        cout << "It's a tie!";
    }
    else {
        switch_player();
        cout << "Player " << player << " wins!";
    }

    return 0;
}