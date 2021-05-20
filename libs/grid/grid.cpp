#include <iostream>
#include <vector>

using namespace std;

void printGrid(int grid[3][3])
{   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            switch (grid[i][j])
            {
                case 0:
                cout << " -";
                break;
                case 1:
                cout << " x";
                break;
                case 2:
                cout << " o";
                break;
            }
            if (j != 2) {
                cout << " |";
            }
        }
        cout << endl;
        if (i != 2) {
            cout << "-----------" << endl;
        }
    }
}

bool checkWinner(int grid[3][3],int row,int col)
{
    int player = grid[row][col];
    bool winRow = true, winCol = true, winDia = false;

    // Check row
    for (int j = 0; j < 3; j++) {
        if (grid[row][j] != player) {
            winRow = false;
        }
    }
    
    // Check col
    for (int i = 0; i < 3; i++) {
        if (grid[i][col] != player) {
            winCol = false;
        }
    }
    
    // Check diagonals (upperleft-lowerright and upperright-lowerleft)
    if (row == col) {
        winDia = true;
        for (int i = 0; i < 3; i++) {
            if (grid[i][i] != player) {
                winDia = false;
            } 
        }
    }
    if (row + col == 2) {
        winDia = true;
        for (int i = 0; i < 3; i++) {
            if (grid[i][2-i] != player) {
                winDia = false;
            } 
        }
    }
    return (winRow || winCol || winDia);
}
