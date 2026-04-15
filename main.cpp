#include <iostream>

using namespace std;

void drawGrid(int p, int state[]) {
for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
        int i = row * 3 + col;
        if (state[i] == 0) {
            cout << " ";
        }
        else if (state[i] == 1) {
            cout << "O";
        }
        else cout << "X";
        if (col != 2) cout << " | ";
    }
    if (row != 2)
    cout << "\n__|___|__" << endl;
    else cout << "\n  |   |  " << endl;
}
    cout << endl;
}

int evaluateGame(int state[], bool &over) {
    // check rows
    for (int row = 0; row < 3; row++) {
        if ((state[row*3] != 0) && (state[row*3] == state[(row*3) +1]) && (state[(row*3) +1] == state[(row*3) +2])) {
            over = true;
            cout << "Row match!" << endl;
            return state[row];
        }
    }

    // check columns
    for (int col = 0; col < 3; col++) {
        if ((state[col] != 0) && (state[col] == state[col+3]) && (state[col+3] == state[col+6])) {
            over = true;
            cout << "Col match!" << endl;
            return state[col];
        }
    }

    // check diagonals
    if (state[0] != 0 && state[0] == state[4] && state[4] == state[8]) {
        over = true;
        return state[4];
    }
    else if (state[2] != 0 && state[2] == state[4] && state[4] == state[6]) {
        over = true;
        return state[2];
    }
    // check draw
    bool f = true;
    for (int i = 0; i < 9; i++) {
        if (state[i] == 0) f = false;
    }

    if (f) {
        over = true;
        return 0;
    }
    return 0;
}
void monitor(int state[]) {
    for (int i = 0; i < 9;i++) {
        cout << state[i] << " ";
    }
}


int main() {
    int state[9]{};
    bool over = false;
    bool circle = false;
    char winner = 0;
    cout << "Press q to quit\n\n";
    while (!over) {
      // take user input
        char c;
        if (circle)
            cout << "O's turn: ";
        else cout << "X's turn: ";
        cin >> c;
        if (c == 'q' || c == 'Q') {
            cout << "Game ended abruptly!\n\n";
            return 0;
        }
        int p = c - '0';
        cout << endl;
        if(!(1 <= p && p <= 9)) {
            cout << "Invalid Move! Use numbers from 1-9!\n\n";
            cin.clear();
            continue;
        }
      // check state
        if (state[p-1] > 0) {
            cout << "Invalid Move! Square already occupied!\n\n";
            cin.clear();
            continue;
        }
      // update state
        if (circle) {
            state[p-1] = 1;
        }
        else state[p-1] = 2;
      // draw game
        drawGrid(p, state);
        circle = !circle;
      // evaluate game
        int r = evaluateGame(state, over);
        if (over) {
         if (r == 1) winner = 'O';
         else if (r == 2) winner = 'X';
         else winner = 'D';
        }
    }
    if (winner != 'D')
    cout << "Winner is "<< winner << "!"<< endl;
    else cout << "Draw!" << endl;
    return 0;
}