#include <iostream>
// #include <string>
#include <vector>
#include<random>
#include <ctime>

using namespace std;


enum fields {WORD, HINT, NUM_OF_FIELD};
const int NUM_OF_WORDS = 5;
const string WORD_LIST [NUM_OF_WORDS][NUM_OF_FIELD] = {
        {"wall", "Do you feel you're banging your head against something?"},
        {"glasses", "These might help you see the answer."},
        {"labored", "Going slowly, is it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It's what the game is all about."}
};
char play_again = 'n';
const unsigned MAX_TRIES = 8;
unsigned int wrong_tries;
srand(static_cast<unsigned int>(time(0)));
int main(){
    do{
        vector<char>::iterator iter;
        char guess;
        wrong_tries = 0;
        // vector<string> secret_word = WORD_LIST[rand()%NUM_OF_WORDS +1][WORD];
        // vector<string> hint = WORD_LIST[rand()%NUM_OF_WORDS +1][HINT];
        
        vector<char> secret_word = WORD_LIST[3][WORD]; // change it to string ???
        vector<char> hint = WORD_LIST[3][HINT]; // change it to string ???
        
        // resetting user word string
        vector<char> for_now(secret_word.size(), '_');

        // add welcome
        // jumbled word ??
        while ((wrong_tries<MAX_TRIES) && (for_now != secret_word)) {
            cout << MAX_TRIES - wrong_tries << endl;
            // print user guessed word
            for (int i =0; i < secret_word.size(); i++){
                cout << for_now[i];
            }
            cout <<endl;
            cin >> guess; // user input
            cout << endl;
            // finding guess in secret word;
            for (iter = secret_word.begin(); iter!=secret_word.end(); ++iter){
                iter = secret_word.find(guess); // repeating words ?????
                if (iter != secret_word.end() && (for_now[iter- secret_word.begin()]=="_")){
                    for_now[iter - secret_word.begin] = *iter;
                }
                else wrong_tries++;
            }
        }
        if (for_now != secret_word) cout << "hanged !!! " << endl;
        else  cout << "win" << endl;

    }while(play_again=="y");

    return 0;
}   