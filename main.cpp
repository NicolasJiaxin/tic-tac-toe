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
    int player = 2;
    int numofturns = 0;

    while (numofturns < 9) {
        player = player - pow(-1,player);
        isValid = false;
        cout << "PLAYER " << player << "'s turn:" << endl;
        cout << "Current state: " << endl;
        printGrid(grid);
        while(!isValid) {
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
                grid[row][col] = player;
                isValid = true;
            }
            else {
                cout << "INVALID. Current state: " << endl;
                printGrid(grid);
            }
        }

        if (checkWinner(grid,row,col)) {
            cout << endl;
            cout << "PLAYER " << player << " HAS WON!!!" << endl;
            printGrid(grid);
            return 0;
        }
        numofturns++;
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
    cout << "DRAW." << endl;
    return 0;
}