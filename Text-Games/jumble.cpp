#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_OF_WORDS = 5;
    const string WORDS[NUM_OF_WORDS][NUM_FIELDS]{
        {"wall", "Do you feel you're banging your head against something?"},
        {"glasses", "These might help you see the answer."},
        {"labored", "Going slowly, is it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It's what the game is all about."}
    };

    srand(static_cast<unsigned int>(time(0)));
    int choice = rand()%NUM_OF_WORDS;
    string the_word = WORDS[choice][WORD];
    string hint = WORDS[choice][HINT];

    string jumbled = the_word;
    int length = jumbled.size();
    for (int i=0; i<=length; i++){
        int index1 = rand()%length;
        int index2 = rand()%length;
        char temp = jumbled[index1];
        jumbled[index1] = jumbled[index2];
        jumbled[index2] = temp;
    }
    cout << "\t\t\tWelcome to Word Jumble!\n\n";
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n\n";
    cout << "The jumble is: " << jumbled;
    string guess;
    cout << "\n\nYour guess: ";
    cin >> guess;
    while ((guess != the_word) && (guess != "quit")){
        if (guess == "hint"){
        cout << hint;
        }
        else{
        cout << "Sorry, that’s not it.";
        }
        cout <<"\n\nYour guess: ";
        cin >> guess;
        }
        if (guess == the_word)
            {
            cout << "\nThat’s it! You guessed it!\n";
            }
        cout << "\nThanks for playing.\n";
        return 0;
}