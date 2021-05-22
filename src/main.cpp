#include <iostream>
#include <game.h>

using namespace std;

int main()
{
    int numofplayers;
    Game game;

    // Asking for number of players until valid choice is given (1 or 2 players)
    cout << "WELCOME TO TIC-TAC-TOE" << endl << "How many players? (1 or 2 players)" << endl;
    cin >> numofplayers;
    while (cin.fail() || numofplayers > 2 || numofplayers < 1) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "INVALID. Try again." << endl;
        cin >> numofplayers;
    }

    // If one player, then ask if human wants to go first and update isHuman[1,2] accordingly
    if (numofplayers == 1) {
        string gofirst;
        while(true) {
            cout << "Go first? Yes/no" << endl;
            cin >> gofirst;
            if (gofirst == "Yes" || gofirst == "yes") {
                game.isHuman1 = true;
                game.isHuman2 = false;
                break;
            } 
            else if (gofirst == "No" || gofirst == "no"){
                game.isHuman1 = false;
                game.isHuman2 = true;
                break;
            }
            else {
                cout << "Invalid. Try again." << endl;
            }
        }
    }

    // Otherwise (2 players), both isHuman are true
    else {
        game.isHuman1 = true;
        game.isHuman2 = true;
    }
    
    // Game starts
    int turn;
    while (!game.isOver && game.numofturns < 9) {
        // turn is either 1 or 2
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

    // If loop terminated because reached 9 turns, then it is a draw
    if (game.numofturns == 9) {
        cout << endl <<  "DRAW" << endl;
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
    }
    
    game.printGrid();
    cout << endl;
    return 0;
}