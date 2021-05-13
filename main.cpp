#include <iostream>
#include <cmath>
#include "grid.h"

using namespace std;

int main()
{
    int grid [3][3] = {};
    bool hasWinner = false;
    bool isValid;
    int row, col;
    int turn = 2;
    while (!hasWinner) {
        turn = turn - pow(-1,turn);
        isValid = false;
        cout << "Current state: " << endl;
        printGrid(grid);
        while(!isValid) {
            cout << "PLAYER " << turn << ":" << endl;
            cout << "Enter row (0-2):" << endl;
            cin >> row;
            while (row > 2 || row < 0) {
                cout << "INVALID. Enter row(0-2):" << endl;
                cin >> row;
            }
            cout << "Enter column(0-2):" << endl;
            cin >> col;
            while (col > 2 || col < 0) {
                cout << "INVALID. Enter col(0-2):" << endl;
                cin >> col;
            }
            if(grid[row][col] == 0) {
                grid[row][col] = turn;
                isValid = true;
            }
            else {
                cout << "INVALID. Current state: " << endl;
                printGrid(grid);
            }
        }
    }
}