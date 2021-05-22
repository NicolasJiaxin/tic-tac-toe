#include <game.h>

int main() {
    Game game;

    // Winners check
    int grid1[3][3] = {{1,1,1},{-1,-1,0},{0,0,0}};
    game.setGrid(grid1);
    if (!game.checkWinner(0,0)) {
        return 1;
    }

    int grid2[3][3] = {{0,0,-1},{1,0,-1},{0,0,-1}};
    game.setGrid(grid2);
    if (!game.checkWinner(2,2)) {
        return 1;
    }

    int grid3[3][3] = {{1,0,-1},{0,1,0},{0,0,1}};
    game.setGrid(grid3);
    if (!game.checkWinner(2,2)) {
        return 1;
    }
    
    // No winner check
    int grid4[3][3] = {{1,0,-1},{0,1,0},{0,0,1}};
    game.setGrid(grid1);
    if (game.checkWinner(1,0)) {
        return 1;
    }

    int grid5[3][3] = {{1,0,-1},{1,-1,1},{0,-1,1}};
    game.setGrid(grid5);
    if (game.checkWinner(1,0)) {
        return 1;
    }

    int grid6[3][3] = {{1,0,-1},{0,0,0},{0,0,1}};
    game.setGrid(grid6);
    if (game.checkWinner(0,0)) {
        return 1;
    }
    
    return 0;
}