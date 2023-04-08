// Black Jack game
#include "blackjack_game.h"
#include <iostream>

using namespace std;
int main(){
    cout << "\t\t Welcome to Blackjack!" << endl << endl;
    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "How many players? (1-7): ";
        // cin >> numPlayers;
        numPlayers = 3;
    }
     
    vector<string> names;
    string name;
    for(int i = 0; i < numPlayers; i++){
        cout << "Enter player name: ";
        name  = std::to_string(i+1);
        // cin >> name;
        names.push_back(name);
    }
    cout << endl;

    // The Game Loop:
    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.Play();
        cout << std::endl  << std::endl  << "Do you want to play again (Y/N): ";
        cin >> again;
    }
    return 0;
}