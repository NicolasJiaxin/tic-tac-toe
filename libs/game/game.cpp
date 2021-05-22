#include <iostream>
#include <game.h>

// Constructor
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

// Setter
void Game::setGrid(int newgrid[3][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = newgrid[i][j];
        }
    }
}
 
// Given the grid, replaces 1 by x, 0 by - and -1 by o with lines separators
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
                case -1:
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

// Given a position in the grid, check if the player has won
bool Game::checkWinner(int row,int col)
{
    // Getting which player to check
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
    
    // Check if entry is on a diagonal
    // Upperleft-lowerright diagonal
    if (row == col) {
        winDia = true;
        for (int i = 0; i < 3; i++) {
            if (grid[i][i] != player) {
                winDia = false;
            } 
        }
    }
    // Upperright-lowerleft diagonal
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

// Performs a turn, given the number of turns and if the player is human or AI
void Game::doTurn(int turn,bool isHuman) 
{
    int row, col;
    
    std::cout << "PLAYER " << turn << "'s turn:" << std::endl;
    std::cout << "Current state: " << std::endl;
    printGrid();

    // Human turn
    if (isHuman) {
        // Asking for input until valid choice is given by the user
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
    
    // AI turn
    else {
        std::cout << "THINKING..." << std::endl;
        bool maximazing = turn % 2;
        int *move = minimax(numofturns,maximazing);
        row = move[0];
        col = move[1];
        std::cout << "MOVE: " << row << ',' << col << std::endl;
    }

    // Writing the move in the grid
    switch(turn)
    {
        case 1:
        grid[row][col] = 1;
        break;
        case 2:
        grid[row][col] = -1;
        break;
    }
    
    // Checking for winner at the end of the turn
    if (checkWinner(row,col)) {
        std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
        std::cout << "PLAYER " << turn << " HAS WON!!!" << std::endl;
        isOver = true;
    }
}