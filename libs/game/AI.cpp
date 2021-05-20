#include <game.h>

using namespace Game;
int* minimax(bool maximazing) 
{
    int* bestMove = new int[3];
    bestMove[0] = 0;
    bestMove[1] = 0;
    bestMove[2] = 0;
    
    if (numofturns == 9) {
        bestMove[0] = 0;
        return bestMove;
    }

    else {
        int* evaluation;
        if (maximazing) {
            bestMove[2] = -2;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (grid[i][j] == 0) {
                        grid[i][j] = 1;
                        if (checkWinner(grid,i,j)) {
                            bestMove[0] = i;
                            bestMove[1] = j;
                            bestMove[2] = 1;
                        }
                        else {
                            evaluation = minimax(grid, numofturns + 1, false);
                            if (evaluation[2] > bestMove[2]) {
                                bestMove[0] = i;
                                bestMove[1] = j;
                                bestMove[2] = evaluation[2];
                            }
                        }
                        grid[i][j] = 0;
                    }
                }
            }
        }
         
        else {
            bestMove[2] = 2;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (grid[i][j] == 0) {
                        grid[i][j] = -1;
                        if (checkWinner(grid,i,j)) {
                            grid[i][j] = 0;
                            bestMove[0] = i;
                            bestMove[1] = j;
                            bestMove[2] = -1;
                        }
                        else {
                            evaluation = minimax(grid, numofturns + 1, true);
                            if (evaluation[2] < bestMove[2]) {
                                bestMove[0] = i;
                                bestMove[1] = j;
                                bestMove[2] = evaluation[2];
                            }
                        }
                        grid[i][j] = 0;
                    }
                }
            }
        }
        return bestMove;
    }
}