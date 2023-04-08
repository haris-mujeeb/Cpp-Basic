using namespace std;
#include <iostream>
#include <tuple>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>


const int RANGE = 100;
const std::string GUESS_HIGHER_HINT =  "Guess higher.";
const std::string GUESS_LOWER_HINT =  "Guess lower.";
const std::string YOU_WON_MESSAGE =  "Congrats, you won!";
unsigned int no_of_tries = 0;
unsigned int secret_number = 0;
bool check_flag = false;
std::string hint;

// Checks if the number is same as the 
std::tuple<bool, std::string> check(unsigned int guess, unsigned int secret_number){
    if (guess == secret_number) return {true, YOU_WON_MESSAGE}; 
    if (guess < secret_number) return {false, GUESS_HIGHER_HINT};
    else return {false, GUESS_LOWER_HINT};
} 

int next_guess(int initial_guess, std::string hint, vector<int> all_guesses_vector){
    int new_guess = initial_guess;

    // calculating new guess
    if(hint == GUESS_HIGHER_HINT) 
        new_guess = (RANGE + initial_guess)/2;
    else 
        new_guess = (initial_guess)/2;

    // sorting vector in assending order
    // for(iter = all_guesses_vector.begin(),iter == all_guesses_vector.end() , ++iter){
    // }
    sort(all_guesses_vector.begin(), all_guesses_vector.end());

    // checking new guess with previous guesses
    vector<int>::iterator iter;
    for(iter = all_guesses_vector.begin(); iter != all_guesses_vector.end(); ++iter){
        if (*iter == initial_guess)
            new_guess = next_guess(new_guess++, hint, all_guesses_vector);
    }
    return new_guess;
}

int main(){
    cout << "Hello, pick a number between 0-100." << endl;
    // do{
    //     cin >> secret_number; // add error handeling for string case <---!!!
    // }while(secret_number > RANGE);
    secret_number = 20; // only for testing


    vector<int> all_guesses_vector;
    unsigned int guess = 50; // add random guess here <---!!!
    while (!check_flag)
    {
        no_of_tries++;
        auto [check_flag, hint] = check(guess,secret_number);
        all_guesses_vector.push_back(guess);
        cout << "Hint: " << hint << endl;
        guess = next_guess(guess, hint,  all_guesses_vector);
        cout << "New Guess: " << guess << endl;
    }
    cout << "No of tries: " << no_of_tries << endl;
}