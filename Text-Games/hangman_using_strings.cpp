#include <iostream>
#include<random>

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
char play_again;
const unsigned MAX_TRIES = 8;
unsigned int wrong_tries;

int main(){
    srand(static_cast<unsigned int>(time(0)));
    do{
        char guess;
        wrong_tries = 0;
        // vector<string> secret_word = WORD_LIST[rand()%NUM_OF_WORDS +1][WORD];
        // vector<string> hint = WORD_LIST[rand()%NUM_OF_WORDS +1][HINT];
        
        string secret_word = WORD_LIST[rand()%NUM_OF_WORDS][WORD]; // change it to string ???
        string hint = WORD_LIST[rand()%NUM_OF_WORDS][HINT]; // change it to string ???
        
        // resetting user word string
        string for_now(secret_word.size(), '_');
        string for_now_prev = for_now;

        // add welcome
        // jumbled word ??
        while ((wrong_tries<MAX_TRIES) && (for_now != secret_word)) {
            system("cls");
            cout << "\nNo of tries: " << MAX_TRIES - wrong_tries << endl;
            // print user guessed word
            cout << "Guessed word so far: " << for_now <<endl;

            // user input
            cout << "Enter your guess: ";
            cin >> guess; 
            cout << endl;
            
            // checking if entered char is already used or not
            // cout << "You have already correctly guessed this character!" << endl;
            
            // finding guess in secret word;
            for_now_prev = for_now;
            for (unsigned int i = 0; i <= secret_word.size() ; i++){
                if (secret_word[i] == guess && (for_now[i] =='_')) for_now[i] = secret_word[i];
            }
            // checking if for_Now is updated or not
            if (for_now_prev != for_now) cout << "You guessed right!" << endl;
            else { 
                cout << "Wrong guess!!!" << endl;
                wrong_tries++;
            }
            // clear screen
        } // guessing while loop ends
        if (for_now != secret_word) cout << "\t\t\t\t  ----- Nooooo, you were HANGED !!! ----- " << endl;
        else  cout << "\t\t\t\t   ----- a WINNER is you!!! ----- " << endl;

        play_again = 'n';
        cout << "\n\t\t\t\tDo you want to play again? (y/n): ";
        cin >> play_again;
        system("cls");
     }while(play_again=='y');

    return 0;
}   