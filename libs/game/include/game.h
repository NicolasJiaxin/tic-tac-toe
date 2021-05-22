#pragma once
class Game {        
    public:
        int grid[3][3];
        bool isHuman1;
        bool isHuman2;
        int numofturns;
        bool isOver;

        Game();
        void setGrid(int newgrid[3][3]);
        void printGrid();
        bool checkWinner(int i,int j);
        void doTurn(int turn,bool isHuman);
        int* minimax(int depth,bool maximaxing);
};
