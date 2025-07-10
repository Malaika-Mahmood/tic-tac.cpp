#include <iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char token = 'x'; // Start with player 'x'
string player1, player2;
bool tie = false;

void FunctionOne() {
    cout << "____________________________________________________________________________________" << endl;
    cout << endl << endl;
    cout << "    |     |" << endl;
    cout << " " << space[0][0] << "  |  " << space[0][1] << "  |  " << space[0][2] << endl;
    cout << "    |     |" << endl;
    cout << "____|_____|____" << endl;
    cout << "    |     |" << endl;
    cout << " " << space[1][0] << "  |  " << space[1][1] << "  |  " << space[1][2] << endl;
    cout << "    |     |" << endl;
    cout << "____|_____|____" << endl;
    cout << "    |     |" << endl;
    cout << " " << space[2][0] << "  |  " << space[2][1] << "  |  " << space[2][2] << endl;
    cout << "    |     |" << endl;
}

void FunctionTwo() {
    int digit;
    if (token == 'x') {
        cout << player1 << " Enter Digit: ";
    } else {
        cout << player2 << " Enter Digit: ";
    }
    cin >> digit;

    int row, column;

    switch (digit) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "Invalid digit! Please enter a number between 1 and 9." << endl;
            FunctionTwo();
            return;
    }

    if (space[row][column] != 'x' && space[row][column] != '0') {
        space[row][column] = token;
        token = (token == 'x') ? '0' : 'x'; // Switch player
    } else {
        cout << "Space already occupied! Try again." << endl;
        FunctionTwo();
    }
}

bool FunctionThree() {
    // Check for a win condition
    for (int i = 0; i < 3; ++i) {
        // Check rows and columns
        if ((space[i][0] == space[i][1] && space[i][1] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[1][i] == space[2][i])) {
            return true;
        }
    }
    // Check diagonals
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }

    // Check for a tie
    bool emptySpace = false;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (space[i][j] != 'x' && space[i][j] != '0') {
                emptySpace = true;
                break;
            }
        }
    }

    if (!emptySpace) {
        tie = true;
        return false; // It's a tie
    }

    return false; // No winner yet
}

int main() {
    cout << "ENTER YOUR NAME |player 1| : ";
    cin >> player1;
    cout << "ENTER YOUR NAME |player 2| : ";
    cin >> player2;
    cout << endl << endl;
    cout << player1 << " ...YOU PLAY FIRST ..." << endl;
    cout << player2 << " ...YOU PLAY SECONDLY ..." << endl;
    cout << endl << endl << endl;

    while (!FunctionThree()) {
        FunctionOne();
        FunctionTwo();
    }

    FunctionOne(); // Display the final board

    if (tie) {
        cout << "It's a draw!" << endl;
    } else if (token == 'x') {
        cout << player2 << " WINS! ...! " << endl;
    } else {
        cout << player1 << " WINS!...! " << endl;
    }

    return 0;
}

