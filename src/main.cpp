#include <iostream>
#include <cmath>
#include <grid.h>

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
            cout << "Enter row,column (e.g. 0,2) and hit enter:" << endl;
            cin >> row;
            cin.ignore(1);
            cin >> col;
            if (cin.fail()) {
                cout << "INVALID. Try again." << endl;
                cin.clear();
            }
            else if(grid[row][col] == 0) {
                grid[row][col] = player;
                isValid = true;
            }
            else {
                cout << "INVALID. Current state: " << endl;
                printGrid(grid);
            }
            cin.ignore(1000, '\n');
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
    printGrid(grid);
    return 0;
}