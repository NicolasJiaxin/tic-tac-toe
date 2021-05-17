#include <grid.h>

int main() {
    // Winners check
    int grid1[3][3] = {{1,1,1},{-1,-1,0},{0,0,0}};

    if (!checkWinner(grid1,0,0)) {
        return 1;
    }

    int grid2[3][3] = {{0,0,-1},{1,0,-1},{0,0,-1}};
    if (!checkWinner(grid2,2,2)) {
        return 1;
    }

    int grid3[3][3] = {{1,0,-1},{0,1,0},{0,0,1}};
    if (!checkWinner(grid3,2,2)) {
        return 1;
    }
    
    
    // No winner check
    int grid4[3][3] = {{1,0,-1},{0,1,0},{0,0,1}};
    if (checkWinner(grid4,1,0)) {
        return 1;
    }

    int grid5[3][3] = {{1,0,-1},{1,-1,1},{0,-1,1}};
    if (checkWinner(grid5,1,0)) {
        return 1;
    }

    int grid6[3][3] = {{1,0,-1},{0,0,0},{0,0,1}};
    if (checkWinner(grid6,0,0)) {
        return 1;
    }
    return 0;
}