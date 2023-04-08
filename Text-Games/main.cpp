#include <iostream>
#include <string>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
#include<sstream>
#include<vector>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::numeric_limits;
using std::streamsize;

typedef unsigned short int ushort;

enum difficulty {NOVICE, EASY, NORMAL, HARD, UNBEATABLE}; // default values are {0, 1, 2, 3, 4}

difficulty user_difficulty;

int set_difficulty(string& user_entered_difficulty){
    if(user_entered_difficulty == "1") return 1;
    else if(user_entered_difficulty == "2") return 2;
    else if(user_entered_difficulty == "3") return 3;
    else return 50;
   }
  

int main(){

    ushort score = 0;

/* Enum practice */
    enum shipCost {FIGHTER_COST = 25, BOMBER_COST, CRUSIER_COST = 50};
    shipCost my_ship_cost = BOMBER_COST;
    cout << my_ship_cost << endl;
    cout << CRUSIER_COST - my_ship_cost << endl;



    // string name;
    // bool valid = false;
    // do {
    //     cout << "Enter your name: ";
    //     cin >> name ;
    //     if (cin.good()) valid =true;
    //     else {
    //         //something went wrong, we reset the buffer's state to good
    //         cin.clear();
    //         // and empty it 
    //         cin.ignore(numeric_limits<streamsize>::max(),"/n");
    //         cout << "Enter a valid name!" << endl;
    //        }
    // }while (!valid);
    
    return 0;
}