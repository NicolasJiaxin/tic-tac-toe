#pragma once
class Game {        
    public:
        int grid[3][3];
        bool isHuman1;
        bool isHuman2;
        int numofturns;
        bool isOver;

        Game();
        void printGrid();
        bool checkWinner(int i,int j);
        void doTurn(int turn,bool isHuman);
        int* minimax(int depth,bool maximaxing);
};
