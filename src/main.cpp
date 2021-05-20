#include <iostream>
#include <game.h>

using namespace std;

int main()
{
    int numofplayers;
    Game game;

    cout << "WELCOME TO TIC-TAC-TOE" << endl << "How many players?" << endl;
    cin >> numofplayers;
    while (cin.fail() || numofplayers > 2 || numofplayers < 1) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "INVALID. Try again." << endl;
        cin >> numofplayers;
    }

    if (numofplayers == 1) {
        string gofirst;
        cout << "Go first? Yes/no" << endl;
        cin >> gofirst;
        if (gofirst == "Yes" || gofirst == "yes") {
            game.isHuman1 = true;
            game.isHuman2 = false;
        } 
        else if (gofirst == "No" || gofirst == "no"){
            game.isHuman1 = false;
            game.isHuman2 = true;
        }
        else {
            game.isHuman1 = true;
            game.isHuman2 = true;
        }
    }
    else {
        game.isHuman1 = true;
        game.isHuman2 = true;
    }
    
    int turn;
    while (!game.isOver && game.numofturns < 9) {
        turn = (game.numofturns % 2) + 1;
        switch (turn)
        {
            case 1:
            game.doTurn(turn,game.isHuman1);
            break;
            case 2:
            game.doTurn(turn,game.isHuman2);
        }
        game.numofturns++;
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }

    if (game.numofturns == 9) {
        cout << "DRAW." << endl;
    }
    game.printGrid();
    return 0;
}