using namespace std;
#include <iostream>
#include <string>
#include <vector>

unsigned int ALLOWED_GUESSES = 5;
unsigned int left_guesses;

//Create  a group of words
enum fields {WORD, HINT, NUM_OF_FIELDS};
const vector<string> WORDS[][NUM_OF_FIELDS] = {
    {"wall", "Do you feel you're banging your head against something?"},
    {"glasses", "These might help you see the answer."},
    {"labored", "Going slowly, is it?"},
    {"persistent", "Keep at it."},
    {"jumble", "It's what the game is all about."}
};

inline string secret_word(){
    unsigned int rows = sizeof(WORDS)/sizeof(WORDS[0]);
    // unsigned int cols = sizeof(WORDS[0]/sizeof(WORDS[0][0]));
    return WORDS[rand()%rows][WORD];
}

void GUI(unsigned int left_guesses, char guessed_word[]){
    cout <<"No of Guessed left: "<< left_guesses << endl;
    cout << "Your Guessed Word: " << guessed_word << endl;
    // cout << << endl;
    // cout << << endl;
    // cout << << endl;
}

bool belongs_to_guessed_word(char word, char guessed_word[]){
    for(int i = 0; i<sizeof(guessed_word[0]); i++)
    if (guessed_word[i]==word)  return true;
    return false;
}

bool belongs_to_secret_word(char word, const string SECRET_WORD){
    if (SECRET_WORD.find(word)!= string::npos) 
            return true;
    return false;
}

void update_guessed_word_list(char word, char guessed_word[], const string SECRET_WORD){
    size_t pos = 0;
    while(SECRET_WORD.find(word, pos) != string::npos){
        pos = SECRET_WORD.find(word, pos);
        if (pos != string::npos) 
            guessed_word[pos] = word;
        pos++;
    }
}


int main(){
    //Pick a random word from the group as the secret word
    const string SECRET_WORD = secret_word();
    cout << SECRET_WORD << endl;
    int length = SECRET_WORD.size();

    char guessed_word[length];
    for (int i=0; i < length; ++i){
        guessed_word[i] = '_';
    }
    left_guesses = ALLOWED_GUESSES;
    char word;
    while ((left_guesses > 0) && (guessed_word != SECRET_WORD)){ /// !!!!!
        GUI(left_guesses, guessed_word);
        cout << "Enter your Guess: "; cin>> word;
        if (belongs_to_guessed_word(word, guessed_word)){
            cout << "Already guessed!" << endl;
        }
        else if(belongs_to_secret_word(word, SECRET_WORD)){
            update_guessed_word_list(word, guessed_word, SECRET_WORD);
            cout << "You guess is correct!" << endl;
        }
        else{
            left_guesses--;
            cout << "You guess is incorrect!" << endl;
        }
    }
    if (guessed_word == SECRET_WORD) cout << "Congrats, you won!!!" << endl;
    else cout << "You have been hanged!";
}