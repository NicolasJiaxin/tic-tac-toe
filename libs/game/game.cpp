#include <iostream>
#include <game.h>


Game::Game()
{
    numofturns = 0;
    isOver = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) { 
            grid[i][j] = 0;
        }
    }
}

void Game::printGrid()
{   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            switch (grid[i][j])
            {
                case 0:
                std::cout << " -";
                break;
                case 1:
                std::cout << " x";
                break;
                case 2:
                std::cout << " o";
                break;
            }
            if (j != 2) {
                std::cout << " |";
            }
        }
        std::cout << std::endl;
        if (i != 2) {
            std::cout << "-----------" << std::endl;
        }
    }
}

bool Game::checkWinner(int row,int col)
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

void Game::doTurn(int turn,bool isHuman) 
{
    int row, col;
    
    std::cout << "PLAYER " << turn << "'s turn:" << std::endl;
    std::cout << "Current state: " << std::endl;
    printGrid();

    if (isHuman) {
        while(true) {
            std::cout << "Enter row,column (e.g. 0,2) and hit enter:" << std::endl;
            std::cin >> row;
            std::cin.ignore(1);
            std::cin >> col;
            if (std::cin.fail()) {
                std::cout << "INVALID. Try again." << std::endl;
                std::cin.clear();
            }
            else if(grid[row][col] == 0) {
                break;
            }
            else {
                std::cout << "INVALID. Current state: " << std::endl;
                printGrid();
            }
            std::cin.ignore(1000,'\n');
        }
    }
    /*
    else {
        std::cout << "THINKING..." << std::endl;
        bool maximazing = turn % 2;
        int *move = minimax(maximazing);
        row = move[0];
        col = move[1];
        std::cout << "MOVE: " << row << ',' << col << std::endl;
    }
    */
    grid[row][col] = turn;
    
    if (checkWinner(row,col)) {
        std::cout << std::endl;
        std::cout << "PLAYER " << turn << " HAS WON!!!" << std::endl;
        isOver = true;
    }
}