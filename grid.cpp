#include <iostream>

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