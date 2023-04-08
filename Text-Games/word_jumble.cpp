using namespace std;
#include <iostream>
#include <string>

enum difficulty {easy, medium, hard, number_of_difficulty_levels};
difficulty level_of_difficulty = easy;
enum fields {WORD, HINT, NUM_FIELDS};
const string WORDS[][NUM_FIELDS] = {
    {"wall", "Do you feel you're banging your head against something?"},
    {"glasses", "These might help you see the answer."},
    {"labored", "Going slowly, is it?"},
    {"persistent", "Keep at it."},
    {"jumble", "It's what the game is all about."}
};
string jumble_word = WORDS[1][WORD];
string& jumble(string& word){
    int length = word.length();
    for (int8_t i = 0; i < length; i++){
        int index1 = rand()%length;
        int index2 = rand() % length;
        char temp = word[index1];
        word[index1] = word[index2];
        word[index2] = temp;
    }
    return word; 
}

int main() {
    // welcome the player
    cout << "\t\t\tWelcome to Word Jumble!\n\n";
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n\n";

    // game loop 
    while(1){
        // dificulty
        // cout << "Selet difficult 0-4: " << endl;
        // int temp = 0;
        // cin >> temp;
        // switch (temp)
        // {
        // case 0:
        //     level_of_difficulty = easy;
        //     jumble = WORDS[0][WORD]; break;
        // case 1:
        //     jumble = WORDS[2][WORD]; break;
        // case 2:
        //     jumble = WORDS[4][WORD]; break;
 
        // default:
        //     break;
        // } 
        // caling function that jumbles the words
        jumble_word = jumble(jumble_word);
        
        // printing jumbled word
        cout << "The jumble is: " << jumble_word << endl;

        // guessing the word

        // showing number of guesses left

    // saying good bye
    }
}